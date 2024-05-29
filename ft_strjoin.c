/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 05:53:58 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/29 05:53:59 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	result = (char *)malloc(len_s1 + len_s2 + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (++i < len_s1 && s1[i] != '\0')
		result[i] = s1[i];
	i = -1;
	while (++i < len_s2 && s2[i] != '\0')
		result[len_s1 + i] = s2[i];
	result[len_s1 + i] = '\0';
	return (result);
}
