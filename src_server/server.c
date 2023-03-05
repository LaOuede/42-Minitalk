/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:51:35 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/04 18:02:44 by gwenolalero      ###   ########.fr       */
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
	//pid_t	pid;

	//pid = getpid();
	//printf("PID : %d", pid);
	write(1, "PID : ", 6);
	system("ps | awk '$4 ~ /server/ {print $1}'");
	signal(SIGUSR1, handler_sigusr1);
	while (1)
		pause();
} */

/* TEST 2 - Binary conversion */
/* static void	handler_sigusr1(int signum)
{
	(void)signum;
	write(1, "1", 1);
}

static void	handler_sigusr2(int signum)
{
	(void)signum;
	write(1, "0", 1);
}

int	main(void)
{
	write(1, "PID : ", 6);
	system("ps | awk '$4 ~ /server/ {print $1}'");
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
		pause();
} */

/* TEST 3 - ASCII conversion */
static void	handler_sigusr1(int signum)
{
	(void)signum;
	write(1, "1", 1);
}

static void	handler_sigusr2(int signum)
{
	(void)signum;
	write(1, "0", 1);
}

int	main(void)
{
	write(1, "PID : ", 6);
	system("ps | awk '$4 ~ /server/ {print $1}'");
	signal(SIGUSR1, handler_sigusr1);
	signal(SIGUSR2, handler_sigusr2);
	while (1)
		pause();
}