/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:35 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/10 15:49:04 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* TEST 1 - Simple communication between processes
static void	handler_sigusr1(int signum)
{
	printf(KGRN "🟢 signal %d received.\n" KNRM, signum);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	//write(1, "PID : ", 6);
	//system("ps | awk '$4 ~ /server/ {print $1}'");
	signal(SIGUSR1, handler_sigusr1);
	while (1)
		pause();
} */

/* TEST 2 - Binary conversion */
/* static void	handler_sigusr(int signum)
{
	if (signum == SIGUSR1)
		write(1, "1", 1);
	else if (signum == SIGUSR2)
		write(1, "0", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
		pause();
} */

/* TEST 3 - ASCII conversion */
/* void	handler_sigusr(int signum)
{
	static char	c;
	static int	bits = 0;
	static int	ascii = 0;
	static int	bitshift = 128;

	if (signum == SIGUSR1)
	{
		printf("1");
		ascii += bitshift;
	}
	else if (signum == SIGUSR2)
	{
		printf("0");
	}
	bits++;
	bitshift /= 2;
	if (bits == 8)
	{
		c = (char)ascii;
		printf(" -> %c\n", c);
		bits = 0;
		ascii = 0;
		bitshift = 128;
	}
} */

/* void	handler_sigusr(int signum)
{
	static char	c = 0;
	static int	bits = 0;

	if (signum == SIGUSR1)
	{
		printf("1");
		c |= 128 >> bits;
	}
	else if (signum == SIGUSR2)
		printf("0");
	bits++;
	if (bits == 8)
	{
		printf(" -> %c\n", c);
		c = 0;
		bits = 0;
	}
} */

/* void	handler_sigusr(int signum)
{
	static char	c = 0;
	static int	bits = 0;

	if (signum == SIGUSR1)
		c |= 128 >> bits;
	bits++;
	if (bits == 8)
	{
		printf("%c\n", c);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID : %d\n", pid);
	pid = system("ps | awk '$4 ~ /client/ {print $1}'");
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
} */

/* TEST 5 - Notifications from server to client*/
/* void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;
	pid_t		pid_client = 0;

	(void)context;
	if (info->si_pid)
		pid_client = info->si_pid;
	if (signum == SIGUSR1)
		c |= 128 >> bits;
	if (++bits == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bits = 0;
		kill(pid_client, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_handler = 0;
	action.sa_sigaction = handler_sigusr;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf(KBLU "Server PID : %d\n" KNRM, pid);
	ft_printf(KBLU KBLD"🔵 Server listening...\n" KNRM);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
} */

/* TEST 6 - Memory allocation and handling */

void	ft_print_msg(char *str)
{
	ft_printf(KBLU "Message received : \n%s\n"KNRM, str);
	free(str);
}

char	*ft_stock_char(char *str, char c)
{
	int	i = 0;

	if (!str)
	{
		ft_printf("check str\n");
		str = ft_calloc(sizeof(str), 2);
		if (!str)
		{
			free(str);
			return (NULL);
		}
	}
	while (str[i] != '\0')
		i++;
	str[i] = c;
	ft_printf("i = %d\n", i);
	ft_printf("char = %c\n", str[i]);
	return (str);
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bits = 0;
	static char	*msg = NULL;
	pid_t		pid_client = 0;

	(void)context;
	if (info->si_pid)
		pid_client = info->si_pid;
	if (signum == SIGUSR1)
		c |= 128 >> bits;
	if (++bits == 8)
	{
		ft_printf("c = %c\n", c);
		if (c != '\0')
		{
			ft_printf("check add char\n");
			msg = ft_stock_char(msg, c);
			ft_printf("msg = %s\n", msg);
		}
		if (!c)
			ft_print_msg(msg);
		c = 0;
		bits = 0;
		kill(pid_client, SIGUSR1);
		ft_printf("---------------------\n");

	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_handler = 0;
	action.sa_sigaction = handler_sigusr;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf(KBLU "Server PID : %d\n" KNRM, pid);
	ft_printf(KBLU KBLD"🔵 Server listening...\n" KNRM);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
		pause();
}
