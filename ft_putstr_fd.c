/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 05:53:24 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 05:53:26 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		i;
	char	a;

	i = 0;
	a = ' ';
	if (s == 0)
		write(fd, &a, 1);
	else
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
