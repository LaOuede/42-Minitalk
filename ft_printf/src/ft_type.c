/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:06:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 10:08:00 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*ft_type
int		ft_str_type(va_list args)
int		ft_int_type(va_list args)
int		ft_ptr_type(va_list args)
int		ft_unsigned_type(va_list args)
int		ft_hex_type(va_list arg, const char low_up)*/

int	ft_str_type(va_list arg)
{
	int		len;
	char	*str;

	str = va_arg(arg, char *);
	len = ft_strlen_printf(str);
	if (!str)
		return (write(1, "(null)", 6));
	ft_putstr(str);
	return (len);
}

int	ft_int_type(va_list arg)
{
	int		nb;
	long	len;

	nb = va_arg(arg, int);
	len = ft_numlen(nb);
	ft_putnbr(nb);
	return (len);
}

int	ft_ptr_type(va_list arg)
{
	long			len;
	uintptr_t		ptr;

	ptr = va_arg(arg, uintptr_t);
	ft_putstr("0x");
	len = 2;
	if (!ptr)
	{
		ft_putchar('0');
		len++;
	}
	else
		ft_putptr(ptr);
	len += ft_ptrlen(ptr);
	return (len);
}

int	ft_unsigned_type(va_list arg)
{
	long				len;
	unsigned int		nb;

	nb = va_arg(arg, unsigned int);
	len = ft_numlen(nb);
	ft_putnbr(nb);
	return (len);
}

int	ft_hex_type(va_list arg, const char low_up)
{
	long			len;
	unsigned int	nb;

	nb = va_arg(arg, unsigned int);
	len = ft_hexlen(nb);
	if (nb == 0)
	{
		ft_putchar('0');
		return (1);
	}
	ft_puthex(nb, low_up);
	return (len);
}
