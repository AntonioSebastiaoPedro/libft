/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:30:18 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 11:30:19 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	a = ' ';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n > -2147483648 && n < 0)
	{
		a = '-';
		write(fd, &a, 1);
		ft_putnbr_fd(n *= -1, fd);
	}
	else if (n < 10)
	{
		a = n + '0';
		write(fd, &a, 1);
	}
	else if (n > -2147483648 && n <= 2147483647)
	{
		a = (n % 10) + '0';
		ft_putnbr_fd(n /= 10, fd);
		write(fd, &a, 1);
	}
}
