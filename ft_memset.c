/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:00:13 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/17 12:56:47 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}
/*
int	main(void)
{
	char			buffer[50];
	unsigned long	i;

	ft_memset(buffer, 'A', sizeof(buffer));
	buffer[sizeof(buffer) - 1] = '\0';
	printf("Buffer após ft_memset: %s\n", buffer);
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
