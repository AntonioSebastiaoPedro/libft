/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 10:03:01 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/17 10:26:19 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int	main(void)
{
	int	chars[5];
	int	i;
	int	c;

	chars[0] = 31;
	chars[1] = 32;
	chars[2] = 90;
	chars[3] = 126;
	chars[4] = 127;
	i = 0;
	while (i < 5)
	{
		c = chars[i];
		if (ft_isprint(c))
			printf("O valor %d (%c) é um caractere imprimível.\n", c, c);
		else
			printf("O valor %d não é um caractere imprimível.\n", c);
		i++;
	}
	return (0);
}
*/
