/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:11:55 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/17 09:53:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int	main(void)
{
	int	ch1;
	int	ch2;

	ch1 = 32;
	ch2 = 200;
	if (ft_isascii(ch1))
	{
		printf("O valor %d é um caractere ASCII.\n", ch1);
	}
	else
	{
		printf("O valor %d não é um caractere ASCII.\n", ch1);
	}
	if (ft_isascii(ch2))
	{
		printf("O valor %d é um caractere ASCII.\n", ch2);
	}
	else
	{
		printf("O valor %d não é um caractere ASCII.\n", ch2);
	}
	return (0);
}*/
