/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:33:15 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:33:16 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*listreturn;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	element = NULL;
	listreturn = NULL;
	while (lst)
	{
		temp = f(lst->content);
		element = ft_lstnew(temp);
		if (!element)
		{
			del(temp);
			ft_lstclear(&listreturn, del);
			return (listreturn);
		}
		ft_lstadd_back(&listreturn, element);
		lst = lst->next;
	}
	return (listreturn);
}
