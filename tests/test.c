/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:31:19 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/06 14:52:54 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (48 <= str[i] && str[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int main(void)
{
	char *array = "123a123";
	printf("%d\n", ft_str_isdigit(array));
	return (0);
}
