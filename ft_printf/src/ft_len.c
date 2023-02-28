/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:59:40 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 10:08:00 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*ft_len
int		ft_ptrlen(uintptr_t ptr)
int		ft_strlen(const char *s)
int		ft_numlen(long n)
int		ft_hexlen(long n)*/

int	ft_strlen_printf(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_numlen(long nb)
{
	long	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

int	ft_hexlen(long nb)
{
	long	len;

	len = 0;
	while (nb)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}
