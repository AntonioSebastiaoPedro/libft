/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:15:22 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/15 12:30:48 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_isalpha(int ch)
{
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 123))
	{
		return (1);
	}
	return (0);
}
/*
int	main(void)
{
	char	c;
	c = 'S';
	if (ft_isalpha(c))
	{
		printf("%c é uma letra do alfabeto.\n", c);
	}
	else
	{
		printf("%c não é uma letra do alfabeto.\n", c);
	}
	return (0);
}
*/
