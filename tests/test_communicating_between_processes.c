/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_communicating_between_processes.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:31:19 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/03 11:35:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	x = 0;

static void	handler_sigusr1(int sig)
{
	if (x == 0)
		printf("(HINT) Remember the meaning of everything can be everywhere! %d\n", sig);
}

int	main(void)
{
	int pid = fork ();

	if (pid == -1)
		return 1;
	if (pid == 0)
	{
		sleep(5);
		kill(getppid(), SIGUSR1);
	}
	else
	{
		struct sigaction sa = {0};
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handler_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		printf("Quel est le sens de la vie? : ");
		scanf("%d", &x);
		if (x == 42)
			printf("Les vrais savent!");
		else
			printf("Personne n'est parfait!");
		wait(NULL);
	}
}