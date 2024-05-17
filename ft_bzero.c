/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:00:13 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/17 13:11:35 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = 0;
	return (s);
}
/*
int	main(void)
{
	char			buffer[20];
	unsigned long	i;

	ft_bzero(buffer, sizeof(buffer));
	buffer[sizeof(buffer) - 1] = '\0';
	printf("Buffer após ft_bzero:\n");
	i = 0;
	while (i < sizeof(buffer) - 1)
	{
		printf("%02x ", (unsigned char)buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
