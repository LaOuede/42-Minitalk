/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 09:47:24 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/16 17:24:34 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_send	*ft_init_client(char *pid, char *str)
{
	t_send	*init;

	init = ft_calloc(sizeof(t_send), 1);
	init->len = ft_strlen(str);
	init->bytes_sent = ft_strlen(str);
	init->msg = ft_strdup(str);
	init->pid_c = getpid();
	init->pid_s = atoi(pid);
	init->bits = 0;
	init->index = 0;
	return (init);
}
