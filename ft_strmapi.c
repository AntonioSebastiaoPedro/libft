/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:31:50 by ansebast          #+#    #+#             */
/*   Updated: 2024/08/13 07:24:15 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
        size_t	len;
        unsigned int     i;
        char			*str;

        if (!s || !f)
                return (NULL);
        len = ft_strlen(s);
        str = (char *)ft_calloc(len + 1, sizeof(char));
        if (!str)
                return (NULL);
	str[len] = '\0';
	i = 0;
        while (s[i] != '\0')
        {
                str[i] = f(i, s[i]);
                i++;
        }
        return (str);
}


