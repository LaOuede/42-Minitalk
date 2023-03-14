/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:10:07 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/14 10:26:14 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

/* ----------------COLORS---------------- */
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

#endif
