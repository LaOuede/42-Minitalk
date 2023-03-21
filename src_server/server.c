/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:35 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/21 15:17:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_mem_alloc(char *str, int capacity)
{
	int		i;
	char	*new;

	new = ft_calloc(sizeof(new), (capacity * 2));
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	str = NULL;
	return (new);
}

char	*ft_stock_char(char *str, char c, t_receive *server)
{
	static int	i = 0;
	static int	size = 0;
	static int	capacity = 2;

	if (!str)
	{
		i = 0;
		size = 0;
		capacity = 2;
		str = ft_calloc(sizeof(str), capacity);
	}
	str[i++] = c;
	if (size++ == capacity)
	{
		str = ft_mem_alloc(str, capacity);
		capacity *= 2;
	}
	kill(server->pid_c, SIGUSR2);
	return (str);
}

static void	handler_receiving(int signum, siginfo_t *info, void *ucontext)
{
	static t_receive	*server;

	(void)ucontext;
	if (server && info->si_pid != server->pid_c && info->si_pid != 0)
		ft_reboot(server, info->si_pid);
	if (!server)
		server = ft_init_server(info->si_pid);
	if (signum == SIGUSR2)
		server->byte |= (128 >> server->bits);
	if (++server->bits == 8)
	{
		if (server->byte != '\0')
			server->msg = ft_stock_char(server->msg, server->byte, server);
		else
		{
			ft_print_msg(server);
			if (kill(server->pid_c, SIGUSR1) == -1)
				ft_error_signal(server);
		}
		server->byte = 0;
		server->bits = 0;
	}
	else
	{
		if (kill(server->pid_c, SIGUSR2) == -1)
			ft_error_signal(server);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argv;
	if (argc != 1)
	{
		ft_printf(KYEL "🟡 Usage : ./server 🖖\n" KNRM);
		ft_printf(KYEL "  No argument needed\n" KNRM);
		exit(EXIT_FAILURE);
	}
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_receiving;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ft_printf(KGRE KBLD "Server PID : " KNRM KWHT "%d\n" KNRM, getpid());
	ft_printf(KBLU KBLD"🔵 Server listening... 📟 \n\n" KNRM);
	while (1)
		pause ();
	return (0);
}
