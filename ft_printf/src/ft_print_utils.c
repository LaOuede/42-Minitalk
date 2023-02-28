/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:06:22 by gle-roux          #+#    #+#             */
/*   Updated: 2022/11/25 07:28:30 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*ft_print_utils
int		ft_putchar(char c)
void	ft_putstr(char *str)
void	ft_putnbr(long n)
void	ft_putptr(uintptr_t ptr)
void	ft_puthex(unsigned int nb, const char low_up)*/

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(long nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}	
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	ft_putchar(nb + 48);
}

void	ft_putptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + 48);
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

void	ft_puthex(unsigned int nb, const char low_up)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, low_up);
		ft_puthex(nb % 16, low_up);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + 48);
		else
		{
			if (low_up == 'x')
				ft_putchar(nb - 10 + 'a');
			if (low_up == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
}
