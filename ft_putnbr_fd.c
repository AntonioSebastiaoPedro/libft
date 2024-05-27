/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:34:11 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:34:16 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isnegative(int n, int fd)
{
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = ft_isnegative(n, fd);
	if (n > 9)
	{
		i = i + (n % 10);
		ft_putnbr_fd(n / 10, fd);
		i = i + '0';
		write(fd, &i, 1);
		return ;
	}
	else
	{
		n += '0';
		write(fd, &n, 1);
	}
}
