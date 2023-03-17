/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:24 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/17 16:36:00 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_add_back(t_msg **msg, t_msg *node)
{
	t_msg	*last;

	if (!node)
		return ;
	if (*msg == NULL)
	{
		*msg = node;
		return ;
	}
	last = *msg;
	while (last->next != NULL)
		last = last->next;
	last->next = node;
}

t_msg	*ft_create_node(char c)
{
	t_msg	*new_node;

	new_node = ft_calloc(sizeof(*new_node), 1);
	if (!new_node)
		return (NULL);
	new_node->data = c;
	new_node->next = NULL;
	return (new_node);
}

void	ft_print_msg(t_receive *server)
{
	t_msg			*ptr;
	static int		counter;

	counter++;
	ft_printf(KBLU "Message received from client [" KBLU KBLD "%d"
		KNRM KBLU "] :\n" KNRM, server->pid_c);
	ptr = server->msg;
	while (ptr)
	{
		write(1, &ptr->data, 1);
		ptr = ptr->next;
	}
	write(1, "\n", 1);
	ft_printf(KBLU "End of transmission [" KBLU KBLD "%d" KNRM KBLU
		"] \n\n" KNRM, counter);
	ft_free_msg(&server->msg);
	kill(server->pid_c, SIGUSR1);
	server->pid_c = 0;
}

void	ft_free_msg(t_msg **msg)
{
	t_msg	*ptr;

	if (!msg || !*msg)
		return ;
	while (*msg)
	{
		ptr = (*msg)->next;
		free(*msg);
		*msg = ptr;
	}
	*msg = NULL;
}
