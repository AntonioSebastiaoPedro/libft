/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:53:42 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/14 14:16:19 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/*
int	main(void)
{
	char str[] = "ansebast";
	size_t len = ft_strlen(str);
	printf("Comprimento da String: %zu", len);
	return (0);
}
*/
