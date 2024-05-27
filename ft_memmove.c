/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:33:49 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:33:52 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
		ft_memcpy(d, s, len);
	return (dest);
}
