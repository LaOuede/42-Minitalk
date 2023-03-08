/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/08 14:57:42 by gwenolalero      ###   ########.fr       */
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

/* TEST 5 - Notifications */
void	send_str(char *str, int pid)
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
			usleep(500);
		}
		i++;
	}
}

/* static void	handler_sigusr(int signum)
{
	if (signum == SIGUSR1)
	{
		printf(KYEL "🟢 ./client : Transmission ended\n" KNRM);
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGUSR2)
	{
		printf(KYEL "🟡 ./client : Transmission ended\n" KNRM);
		exit(EXIT_FAILURE);
	}
} */

int	main(int argc, char **argv)
{
	pid_t	pid_server;
	pid_t	pid_client;
	char	*msg;

	if (argc != 3 || ft_str_isdigit(argv[1]) == 0)
	{
		printf(KYEL KBLD "🟡 Invalid arguments\n" KNRM);
		printf(KYEL "Usage: ./client <pid> <message_to_send>\n");
		exit(EXIT_FAILURE);
	}
	pid_client = getpid();
	printf(KMAG "🟣 Client PID : %d\n" KNRM, pid_client);
	msg = argv[2];
	pid_server = atoi(argv[1]);
/* 	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr); */
	send_str(msg, pid_server);
	printf(KGRN KBLD "🟢 Successful transmission\n" KNRM);
}
