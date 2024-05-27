/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:34:53 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:34:56 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	l_src;
	size_t	l_dst;
	size_t	index;
	size_t	indexj;

	index = 0;
	indexj = 0;
	l_src = ft_strlen((char *)src);
	l_dst = ft_strlen(dst);
	if (l_dst >= size)
		return (size + l_src);
	while (dst[index])
		index++;
	while (src[indexj] && index < size - 1)
	{
		dst[index++] = src[indexj++];
	}
	dst[index] = '\0';
	return ((l_dst + l_src));
}
