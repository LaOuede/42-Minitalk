/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/04 18:03:36 by gwenolalero      ###   ########.fr       */
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
void	send_signals(char *str, int pid)
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
}