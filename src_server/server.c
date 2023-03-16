/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:35 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/16 16:00:33 by gle-roux         ###   ########.fr       */
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
/* char	*ft_print_msg(char *str)
{
	ft_printf(KBLU "Message received :" KNRM "\n%s\n", str);
	free(str);
	str = NULL;
	return (NULL);
}

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
	return (new);
}

char	*ft_stock_char(char *str, char c)
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
	return (str);
}

void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	bits = 0;
	static char	*msg = NULL;
	pid_t		pid_client;

	(void)ucontext;
	if (info->si_pid)
		pid_client = info->si_pid;
	if (signum == SIGUSR1)
		c |= 128 >> bits;
		//c |= 8 << bits;
	if (++bits == 8)
	{
		if (c != '\0')
			msg = ft_stock_char(msg, c);
		else if (c == '\0')
		{
			ft_print_msg(msg);
			msg = NULL;
			kill(pid_client, SIGUSR2);
		}
		c = 0;
		bits = 0;
		kill(pid_client, SIGUSR1);
	}
} */

/* TEST 7 - Linked list and structure */
static t_info	server;

static void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	static char byte = 0;

	(void)ucontext;
	server.pid_c = info->si_pid;
	if (signum == SIGUSR2)
		byte |= 128 >> server.bits;
	ft_printf("c : %d\n", byte);
	if (++server.bits == 8)
	{
		if (byte != '\0')
		{
			ft_add_back(&server.msg, ft_create_node(byte));
			kill(server.pid_c, SIGUSR2);
		}
		else if (byte == '\0')
			ft_print_msg(&server);
		byte = 0;
		server.bits = 0;
	}
	else
		kill(server.pid_c, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	server = *ft_init_server();
	ft_printf(KBLU "Server PID : %d\n" KNRM, server.pid_s);
	ft_printf(KBLU KBLD"🔵 Server listening...\n" KNRM);
	while (1)
		pause ();
	return (0);
}

/* Main design to test memory leaks tipping "q" on the server*/
/* int	main(void)
{
	pid_t				pid;
	struct sigaction	action;
	char				c;

	action.sa_sigaction = handler_sigusr;
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	pid = getpid();
	printf(KBLU "Server PID : %d\n" KNRM, pid);
	ft_printf(KBLU KBLD"🔵 Server listening...\n" KNRM);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	while (1)
	{
		printf("\n*** To test mem leaks : send a message and type 'q' ***\n\n");
		scanf("%c", &c);
		if (c == 113)
			break ;
	}
	ft_printf(KBLU KBLD"🔵 ./server closing...\n" KNRM);
	return (0);
} */
