/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/11 10:51:31 by gwenolalero      ###   ########.fr       */
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

/* TEST 6 - Memory allocation and handling */
void	send_char(char c, int pid)
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
		usleep(500);
	}
}

void	send_str(char *str, int pid)
{
	static int	i = 0;

	while (str[i])
		send_char(str[i++], pid);
	if (str[i] == '\0')
	{
		send_char('\0', pid);
		kill(getpid(), SIGUSR2);
	}
}

static void	handler_sigusr(int signum)
{
	static int	counter = 0;

	if (signum == SIGUSR1)
	{
		counter += 1;
		ft_printf(KYEL "🟡 ./client : Bit succesfully sent\n" KNRM);
/* 		printf(KYEL "🟢 ./client : Transmission ended succesfully\n" KNRM);
		exit(EXIT_SUCCESS); */
	}
	else if (signum == SIGUSR2)
	{
		ft_printf(KGRN "Total bytes sent = %d\n" KNRM, counter);
		ft_printf(KGRN "🟢 ./client : Transmission ended succesfully\n" KNRM);
		exit(EXIT_SUCCESS);
/* 		printf(KYEL "🟡 ./client : Transmission ended unexpectedly\n" KNRM);
		exit(EXIT_FAILURE); */
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
}