/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 05:51:07 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 05:51:10 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long n)
{
	int	strlen;

	strlen = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		strlen++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		strlen++;
	}
	return (strlen);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nbr;
	char	*str;

	nbr = n;
	len = ft_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len--) = '\0';
	if (nbr == 0)
	{
		*(str + 0) = '0';
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		*(str + 0) = '-';
	}
	while (nbr > 0)
	{
		*(str + len--) = (48 + (nbr % 10));
		nbr /= 10;
	}
	return (str);
}
