/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_binary_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:09:16 by gwenolalero       #+#    #+#             */
/*   Updated: 2023/03/06 13:24:55 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char**argv)
{
	int	i = 0;
	int	bitshift = 0;

	if (argc != 2)
	{
		printf("🟡 Invalid arguments\n");
		return (1);
	}
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
