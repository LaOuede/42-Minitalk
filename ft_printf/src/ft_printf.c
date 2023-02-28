/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:06:22 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/27 10:08:00 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
Description :
	The printf utility formats and prints its arguments, after the first,
	under control of the format.
Declaration :
	printf format [arguments ...]
Parameters :
	format - The format is a character string which contains three types of
	objects: plain characters, which are simply copied to standard output, 
	character escape sequences which are converted and copied to the standard
	output, and format specifications, each of which causes printing of the
	next successive argument.
    ... - The undefined number od arguments.
Return Value :
	The printf function returns the number of characters printed.

Implement the following conversions:
	%c - Displays a single `char` character
	%s - Displays a string (as defined by the
	convention) `string`
	%p - The void * pointer argument must be displayed in hexadecimal `ptr`
	%d - Displays a decimal number (base 10) `decimal base 10`
	%i - Displays an integer in base 10 `entier base 10`.
	%u - Displays an unsigned decimal number (base 10) `unsigned integer base 10
	%x - Displays a hexadecimal number (base 16) with lowercase letters
	base 16 hexadecimal number MIN` - Displays a hexadecimal number with
	lowercase letters
	%X - Displays a number in hexadecimal (base 16) with upper case letters
	base 16 hex number SHIFT` %% - Displays a percentage sign
	%% - Displays a percent sign `%`.
*/

static int	ft_arg_type(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
		return (ft_str_type(arg));
	else if (c == 'd' || c == 'i')
		return (ft_int_type(arg));
	else if (c == 'p')
		return (ft_ptr_type(arg));
	else if (c == 'u')
		return (ft_unsigned_type(arg));
	else if ((c == 'x') || (c == 'X'))
		return (ft_hex_type(arg, c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	arg;

	if (!format)
		return (0);
	va_start(arg, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_arg_type(arg, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
