/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:33:09 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:33:10 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	tamlist;
	int	i;

	i = 0;
	tamlist = ft_lstsize(lst);
	while (i < tamlist - 1)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
