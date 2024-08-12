/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:28:38 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/12 09:19:08 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int      ft_countnbr(int nbr)
{
        int     count;

        count = 0;
        while (nbr)
        {
                nbr /= 10;
                count++;
        }
        return (count);
}

char    *ft_itoa(int nbr)
{
        char    *number;
        int             count;

        count = ft_countnbr(nbr);
        number = (char *)ft_calloc(count + 1, sizeof(char));
        if (nbr == 0)
                return ("0");
        if (nbr < 0)
        {
                count++;
                nbr *= -1;
                number[0] = '-';
                number[count] = '\0';
        }
        while (nbr != 0)
        {
                number[--count] = nbr % 10 + '0';
                nbr /= 10;
        }
        return (number);
}
