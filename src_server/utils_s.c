/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:24 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/20 09:28:38 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_error_signal(t_receive *server)
{
	if (server->msg)
		free(server->msg);
	if (server)
		free(server);
	ft_printf(KRED KBLD "🔴 ./server : " KNRM KRED
		"Transmission ended unexpectedly 🚨\n" KNRM);
	exit(EXIT_FAILURE);
}

t_receive	*ft_reboot(t_receive *server, int pid)
{
	if (server->msg)
	{
		ft_print_msg(server);
		free(&server->msg);
	}
	server->byte = 0;
	server->bits = 0;
	server->pid_c = pid;
	return (server);
}

t_receive	*ft_init_server(int pid_c)
{
	t_receive	*init;

	init = ft_calloc(sizeof(t_receive), 1);
	init->byte = 0;
	init->bits = 0;
	init->pid_c = pid_c;
	return (init);
}

void	ft_print_msg(t_receive *server)
{
	static int		counter;

	counter++;
	ft_printf(KBLU "Message received from client [" KBLU KBLD "%d"
		KNRM KBLU "] :\n" KNRM, server->pid_c);
	ft_printf("%s\n", server->msg);
	ft_printf(KBLU "End of transmission [" KBLU KBLD "%d" KNRM KBLU
		"] \n\n" KNRM, counter);
	free(server->msg);
	server->msg = NULL;
	if (kill(server->pid_c, SIGUSR1) == -1)
		ft_error_signal(server);
	server->pid_c = 0;
}
