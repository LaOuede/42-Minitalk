/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:08:12 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/28 15:11:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf("Usage: ./client invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
