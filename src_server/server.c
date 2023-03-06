/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:35 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/06 15:30:01 by gle-roux         ###   ########.fr       */
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

/* TEST 5 - Notifications */
static void	handler_sigusr(int signum)
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
	pid_t				pid;

	pid = getpid();
	printf(KBLU KBLD"🔵 Server waiting...\n" KNRM);
	printf(KBLU "PID : %d\n" KNRM, pid);
	signal(SIGUSR1, handler_sigusr);
	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}
