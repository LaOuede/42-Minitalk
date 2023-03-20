/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:24 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/20 11:03:57 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_receive	*ft_reboot(t_receive *server, pid_t pid_c)
{
	if (server->msg)
		ft_print_msg(server);
	server->byte = 0;
	server->bits = 0;
	server->pid_c = pid_c;
	return (server);
}

t_receive	*ft_init_server(int pid_c)
{
	t_receive	*init;

	init = ft_calloc(sizeof(t_receive), 1);
	init->byte = 0;
	init->bits = 0;
	init->msg = NULL;
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
	kill(server->pid_c, SIGUSR1);
}
