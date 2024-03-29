/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/22 08:09:52 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error(t_send	*msg)
{
	if (msg->msg)
		free(msg->msg);
	if (msg)
		free(msg);
	ft_printf(KRED KBLD "🔴 ./client : " KNRM KRED
		"Transmission ended unexpectedly (" KUND KRED
		"Server PID ?" KNRM ") 🚨\n");
	exit(EXIT_FAILURE);
}

void	ft_end_com(t_send *msg)
{
	ft_printf(KGRN KBLD "🟢 ./client : " KNRM KGRN
		"Transmission ended successfully - [" KGRN KBLD "%d"
		KNRM KGRN "] bytes sent 📤\n" KNRM, msg->bytes_sent);
	free(msg->msg);
	free(msg);
	exit(EXIT_SUCCESS);
}

t_send	*ft_init_client(char *pid, char *str)
{
	static t_send	*init;

	if (!init)
	{
		init = ft_calloc(sizeof(t_send), 1);
		init->bits = 0;
		init->bytes_sent = ft_strlen(str);
		init->index = 0;
		init->len = ft_strlen(str);
		init->msg = ft_strdup(str);
		init->pid_c = getpid();
		init->pid_s = atoi(pid);
	}
	return (init);
}

/* 
Conversion from ASCII to binary.
Ex : with 'a' character.
-> a = 01100010;
-> 128 = 10000000;
Using the & and >> binary operators, byte is reduced to bits to be send.
	a & (128 >> 0) is equal to 00000000 so SIGUSR1 [0] is sent;
	a & (128 >> 1) is equal to 01000000 so SIGUSR2 [1] is sent;
	a & (128 >> 2) is equal to 00100000 so SIGUSR2 [1] is sent;
	a & (128 >> 3) is equal to 00000000 so SIGUSR1 [0] is sent;
	a & (128 >> 4) is equal to 00000000 so SIGUSR1 [0] is sent;
	a & (128 >> 5) is equal to 00000000 so SIGUSR1 [0] is sent;
	a & (128 >> 6) is equal to 00000010 so SIGUSR2 [1] is sent;
	a & (128 >> 7) is equal to 00000000 so SIGUSR1 [0] is sent;
 */
static void	handler_sending(int signum, siginfo_t *info, void *ucontext)
{
	int				flag;
	static t_send	*msg;

	(void)info;
	(void)ucontext;
	flag = 0;
	msg = ft_init_client(0, 0);
	if (signum == SIGUSR1)
		ft_end_com(msg);
	if (signum == SIGUSR2)
	{
		if (msg->len >= 0 && (msg->msg[msg->index] & (128 >> msg->bits)))
			flag = kill(msg->pid_s, SIGUSR2);
		else
			flag = kill(msg->pid_s, SIGUSR1);
		if (++msg->bits == 8)
		{
			msg->bits = 0;
			msg->index++;
			msg->len --;
		}
		if (flag == -1)
			ft_error(msg);
	}
}

int	main(int argc, char **argv)
{
	t_send				*msg;
	struct sigaction	action;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		ft_printf(KYEL "🟡 Usage : ./client <pid> <message_to_send> 🖖\n" KNRM);
		exit(EXIT_FAILURE);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_sending;
	msg = ft_init_client(argv[1], argv[2]);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ft_printf(KGRE KBLD "Client PID = " KNRM "%d\n", getpid());
	kill(getpid(), SIGUSR2);
	while (1)
		pause();
	free(msg->msg);
	free(msg);
	return (0);
}
