/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/17 13:18:47 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

/* --------------------COLORS--------------------- */
# define KNRM  "\x1B[m"
# define KBLD  "\x1B[1m"
# define KGRE  "\x1B[2m"
# define KITA  "\x1B[3m"
# define KUND  "\x1B[4m"
# define KRST  "\x1B[5m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

/* -------------------STRUCTURES------------------- */

typedef struct s_msg
{
	char			data;
	struct s_msg	*next;
}					t_msg;

typedef struct s_receive
{
	int		bits;
	char	byte;
	t_msg	*msg;
	pid_t	pid_c;
	pid_t	pid_s;
}			t_receive;

typedef struct s_send
{
	int		bits;
	int		bytes_sent;
	int		index;
	size_t	len;
	char	*msg;
	pid_t	pid_c;
	pid_t	pid_s;
}			t_send;

/* ----------------UTILS FUNCTIONS----------------- */
void		ft_add_back(t_msg **msg, t_msg *node);
t_msg		*ft_create_node(char c);
void		ft_free_msg(t_msg **msg);
t_send		*ft_init_client(char *pid, char *str);
void		ft_print_msg(t_receive *server);

#endif
