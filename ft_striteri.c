/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:31:16 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 11:31:18 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	char	a;

	i = 0;
	a = ' ';
	if (s != 0)
	{
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
	else
		f(i, &a);
}