/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:48:10 by gle-roux          #+#    #+#             */
/*   Updated: 2023/02/09 21:31:19 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Library :
	#include <string.h>
Description :
	The strncmp() function lexicographically compare the null-terminated strings
	s1 and s2.
	The strncmp() function compares not more than n characters. Because
	strncmp() is designed for comparing strings rather than binary data,
	characters that appear after a `\0' character are not compared.
Declaration :
	
Parameters :
	int	strncmp(const char *s1, const char *s2, size_t n)
Return Value :
	The strcmp() and strncmp() functions return an integer greater than, equal
	to, or less than 0, according as the string s1 is greater than, equal to,
	or less than the string s2. The comparison is done using unsigned characters,
	so that `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && s2[i] != '\0') && (n - 1 > 0))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
		n--;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
