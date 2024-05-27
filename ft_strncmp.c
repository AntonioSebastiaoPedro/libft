/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:35:20 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:35:21 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < n - 1) && (*(const unsigned char *)(s1
			+ i) == *(const unsigned char *)(s2 + i))
		&& *(const unsigned char *)(s1 + i) && *(const unsigned char *)(s2 + i))
	{
		i++;
	}
	return ((*(const unsigned char *)(s1 + i)
		-*(const unsigned char *)(s2 + i)));
}
