/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/20 08:27:46 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/* TEST 1 - Simple communication between processes */
/* int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf(KYEL KBLD "🟡 Usage: " KNRM KYEL "./client invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
} */

/* TEST 2 - Binary conversion */
/* void	send_signals(char *str, int pid)
{
	int	i = 0;
	int	bitshift = 0;

	while (str[i])
	{
		bitshift = 128;
		while (bitshift > 0)
		{
			if (str[i] & bitshift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift /= 2;
			usleep(5);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf(KYEL KBLD "🟡 Invalid arguments\n" KNRM);
		printf(KYEL "Usage: " KYEL "./client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
} */

/* TEST 3 - ASCII conversion */
/* void	send_signals(char *str, int pid)
{
	int	i = 0;
	int	bitshift = 0;

	while (str[i])
	{
		bitshift = 128;
		while (bitshift > 0)
		{
			if (str[i] & bitshift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift /= 2;
			usleep(50);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf(KYEL KBLD "🟡 Invalid arguments\n" KNRM);
		printf(KYEL "Usage: " KYEL "./client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
} */

/* TEST 4 - Parsing */
/* int	send_signals(char *str, int pid)
{
	int	i = 0;
	int	bitshift = 0;

	while (str[i])
	{
		bitshift = 128;
		while (bitshift > 0)
		{
			if (str[i] & bitshift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift /= 2;
			usleep(50);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		printf(KYEL KBLD "🟡 Invalid arguments\n" KNRM);
		printf(KYEL "Usage: " KYEL "./client <pid> <message>\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	send_signals(argv[2], pid);
	return (0);
} */

/* TEST 5 - Notifications from server to client*/
/* void	send_str(char *str, int pid)
{
	static int	i = 0;
	static int	bitshift = 0;

	while (str[i])
	{
		bitshift = 128;
		while (bitshift > 0)
		{
			if (str[i] & bitshift)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bitshift /= 2;
			usleep(500);
		}
		i++;
	}
	if (str[i] == '\0')
		kill(getpid(), SIGUSR2);
}

static void	handler_sigusr(int signum)
{
	static int	counter = 0;

	if (signum == SIGUSR1)
	{
		counter += 1;
		ft_printf(KYEL "🟡 ./client : Bit succesfully sent\n" KNRM);
	}
	else (signum == SIGUSR2)
	{
		ft_printf(KGRN "Total bytes sent = %d\n" KNRM, counter);
		ft_printf(KGRN "🟢 ./client : Transmission ended succesfully\n" KNRM);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	pid_t	pid_client;
	char	*msg;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		ft_printf(KRED KBLD "🔴 Invalid arguments\n" KNRM);
		ft_printf(KRED "Usage: ./client <pid> <message_to_send>\n");
		exit(EXIT_FAILURE);
	}
	pid_client = getpid();
	ft_printf(KMAG "🟣 Client PID : %d\n" KNRM, pid_client);
	msg = argv[2];
	pid_server = atoi(argv[1]);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	send_str(msg, pid_server);
	while (1)
		pause();
} */

/* Function signal error */
/* void	ft_signal_error(void)
{
	printf(KYEL KBLD "🟡 ./client : " KNRM KYEL
		"Transmission ended unexpectedly\n" KNRM);
	exit(EXIT_FAILURE);
}

void	send_char(char c, int pid)
{
	static int	bitshift = 0;

	bitshift = 128;
	while (bitshift > 0)
	{
		if (c & bitshift)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_signal_error();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_signal_error();
		}
		bitshift /= 2;
		usleep(500);
	}
} */

/* TEST 6 - Memory allocation and handling */
/* void	send_char(char c, int pid)
{
	static int	bitshift = 0;

	bitshift = 128;
	while (bitshift > 0)
	{
		if (c & bitshift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bitshift /= 2;
		usleep(125);
	}
}

void	send_str(char *str, int pid)
{
	static int	i = 0;

	while (str[i])
		send_char(str[i++], pid);
	if (str[i] == '\0')
		send_char('\0', pid);
}

static void	handler_sigusr(int signum)
{
	static int	counter = 0;

	if (signum == SIGUSR1)
		counter += 1;
	else if (signum == SIGUSR2)
	{
		ft_printf(KGRN KBLD "\n🟢 ./client : " KNRM KGRN
			"Transmission ended succesfully\n" KNRM);
		ft_printf(KGRN KBLD "🟢 ./client : " KNRM KGRN
			"Total bytes sent = %d\n" KNRM, counter);
		exit(EXIT_SUCCESS);
	}
} */

/* TEST 7 - Linked list and structure */
/* size_t		len;

void	send_char(char c, int pid)
{
	size_t	i;

	i = 0;
	while (i++ < 8)
	{
		if (c & 128)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c <<= 1;
		usleep(40);
	}
}

void	send_str(char *str, int pid)
{
	static int	i = 0;

	len = ft_strlen(str);
	while (str[i])
		send_char(str[i++], pid);
	if (str[i] == '\0')
		send_char('\0', pid);
}

static void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (signum == SIGUSR1)
	{
		ft_printf(KGRN KBLD "🟢 ./client : " KNRM KGRN
			"Transmission ended successfully - [" KGRN KBLD "%d"
			KNRM KGRN "] bytes sent\n" KNRM, len);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	pid_t				pid_server;
	pid_t				pid_client;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		ft_printf(KRED KBLD "🔴 Invalid arguments\n" KNRM);
		ft_printf(KRED "Usage: ./client <pid> <message_to_send>\n");
		exit(EXIT_FAILURE);
	}
	action.sa_sigaction = handler_sigusr;
	action.sa_flags = SA_SIGINFO;
	pid_client = getpid();
	ft_printf("Client PID : %d\n", pid_client);
	pid_server = atoi(argv[1]);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	send_str(argv[2], pid_server);
	while (1)
		pause();
} */

/* TEST 8 - Without usleep */
static t_send	*g_msg;

void	ft_error(void)
{
	if (g_msg->msg)
		free(g_msg->msg);
	if (g_msg)
		free(g_msg);
	ft_printf(KRED KBLD "🔴 ./client : " KNRM KRED
		"Transmission ended unexpectedly (" KUND KRED
		"Server PID ?" KNRM ") 🚨\n");
	exit(EXIT_FAILURE);
}

void	ft_end_com(void)
{
	ft_printf(KGRN KBLD "🟢 ./client : " KNRM KGRN
		"Transmission ended successfully - [" KGRN KBLD "%d"
		KNRM KGRN "] bytes sent 📤\n" KNRM, g_msg->bytes_sent);
	free(g_msg->msg);
	free(g_msg);
	exit(EXIT_SUCCESS);
}

t_send	*ft_init_client(char *pid, char *str)
{
	t_send	*init;

	init = ft_calloc(sizeof(t_send), 1);
	init->len = ft_strlen(str);
	init->bytes_sent = ft_strlen(str);
	init->msg = ft_strdup(str);
	init->pid_c = getpid();
	init->pid_s = atoi(pid);
	init->bits = 0;
	init->index = 0;
	return (init);
}

static void	handler_sending(int signum, siginfo_t *info, void *ucontext)
{
	int	flag;

	(void)info;
	(void)ucontext;
	flag = 0;
	if (signum == SIGUSR1)
		ft_end_com();
	if (signum == SIGUSR2)
	{
		if (g_msg->len >= 0 && g_msg->msg[g_msg->index] & 128)
			flag = kill(g_msg->pid_s, SIGUSR2);
		else
			flag = kill(g_msg->pid_s, SIGUSR1);
		g_msg->msg[g_msg->index] <<= 1;
		if (++g_msg->bits == 8)
		{
			g_msg->bits = 0;
			g_msg->index++;
			g_msg->len --;
		}
		if (flag == -1)
			ft_error();
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void) argc;
	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		ft_printf(KYEL "🟡 Usage : ./client <pid> <message_to_send> 🖖\n" KNRM);
		exit(EXIT_FAILURE);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler_sending;
	g_msg = ft_init_client(argv[1], argv[2]);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ft_printf(KGRE KBLD "Client PID = " KNRM "%d\n", g_msg->pid_c);
	kill(g_msg->pid_c, SIGUSR2);
	while (1)
		pause();
	free(g_msg);
	return (0);
}
