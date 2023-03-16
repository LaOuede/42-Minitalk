/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/16 16:00:28 by gle-roux         ###   ########.fr       */
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
static t_send		*msg;

void	ft_error()
{
	ft_printf(KRED KBLD "🔴 ./client : " KNRM KRED
	"Transmission ended unexpectedly");
	exit(EXIT_FAILURE);
}

/* void	send_str(t_send *msg)
{
	static int	i = 0;
	if (msg->msg[i] != '\0')
	{
		ft_printf("check bit\n");
		send_char(msg->msg[i++], msg->pid_s);
	}
	if (msg->msg[i] == '\0')
	{
		ft_printf("check null\n");
		send_char('\0', msg->pid_s);
	}
} */

static void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	int	flag;

	(void)info;
	(void)ucontext;
	if (signum == SIGUSR1)
	{
		ft_printf(KGRN KBLD "🟢 ./client : " KNRM KGRN
			"Transmission ended successfully - [" KGRN KBLD "%d"
			KNRM KGRN "] bytes sent\n" KNRM, msg->len);
		exit(EXIT_SUCCESS);
	}
	if (signum == SIGUSR2)
	{
		if (msg->msg[msg->index] != '\0')
		{
			if (msg->msg[msg->index] & 128)
			{
				flag = kill(msg->pid_s, SIGUSR2);
				msg->msg[msg->index] <<= 1;
			}
			else
			{
				flag = kill(msg->pid_s, SIGUSR1);
				msg->msg[msg->index] <<= 1;
			}
			if (flag == -1)
				ft_error();
		}
		else if (msg->msg[msg->index] == '\0')
		{
			flag = kill(msg->pid_s, SIGUSR1);
			msg->msg[msg->index] <<= 1;
			if (flag == -1)
				ft_error();
		}
		if (++msg->bits == 8)
		{
			msg->bits = 0;
			msg->index++;
		}
		ft_printf("index : %d\n", msg->index);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		ft_printf(KRED KBLD "🔴 Invalid arguments\n" KNRM);
		ft_printf(KRED "Usage: ./client <pid> <message_to_send>\n" KNRM);
		exit(EXIT_FAILURE);
	}
	action.sa_sigaction = handler_sigusr;
	action.sa_flags = SA_SIGINFO;
	msg = ft_init(argv[1], argv[2]);
	sigaction(SIGUSR1, &action, 0);
	sigaction(SIGUSR2, &action, 0);
	ft_printf("PID  = %d\n", SIGUSR1);
	kill(msg->pid_c, SIGUSR2);
	while (1)
		pause();
	return (0);
}
