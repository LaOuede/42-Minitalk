/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:12:38 by gle-roux          #+#    #+#             */
/*   Updated: 2023/03/13 11:12:54 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnjoin(char *s1, const char *s2, int s2_size)
{
	char	*str;
	int		s1_size;
	int		i;

	if ((!s1 && !s2) || !s2_size)
		return (NULL);
	s1_size = ft_strlen(s1);
	str = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (!str)
	{
		free (s1);
		return (NULL);
	}
	i = -1;
	while (++i < s1_size)
		str[i] = s1[i];
	--i;
	while (++i < s1_size + s2_size)
		str[i] = s2[i - s1_size];
	str[i] = 0;
	free (s1);
	return (str);
}