/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:29:38 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 11:29:40 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	v;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	v = (unsigned char)value;
	while (i < num)
	{
		if (p[i] == v)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
