/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwenolaleroux <gwenolaleroux@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:09:16 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/04 17:06:46 by gwenolalero      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char**argv)
{
	int	i = 0;
	int	bitshift = 0;

	if (argc != 2)
		return (1);
	while (argv[1][i])
	{
		printf("Letter = %c ; ASCII = [%d]\n", argv[1][i], argv[1][i]);
		bitshift = 128;
		printf("Binary = ");
		while (bitshift > 0)
		{
			if (argv[1][i] & bitshift)
				printf("1");
			else
				printf("0");
			bitshift /= 2;
		}
		printf("\n\n");
		i++;
	}
}

/* int	main(int argc, char**argv)
{
	int	i = 0;
	int	bitshift = 0;

	if (argc != 2)
		return (1);
	while (argv[1][i])
	{
		printf("Letter = %c ; ASCII = [%d]\n", argv[1][i], argv[1][i]);
		bitshift = 0;
		printf("Binary = ");
		while (bitshift < 8)
		{
			if (argv[1][i] & 128 >> bitshift++)
				printf("1");
			else
				printf("0");
		}
		printf("\n\n");
		i++;
	}
} */

/* void	ft_printbits(char c)
{
	int	bitshift = 0;

	while (bitshift < 8)
	{
		if (c & 128 >> bitshift)
			printf("1");
		else
			printf("0");
		bitshift++;
	}
}

int	main(void)
{
	ft_printbits('2');
	return (0);
} */
