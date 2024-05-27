/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 09:33:21 by ansebast          #+#    #+#             */
/*   Updated: 2024/05/27 09:33:23 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lista;

	lista = (t_list *)malloc(sizeof(t_list));
	if (lista == NULL)
		return (NULL);
	lista->content = content;
	lista->next = NULL;
	return (lista);
}
