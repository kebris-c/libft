/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:12:55 by kebris-c          #+#    #+#             */
/*   Updated: 2025/08/22 16:39:12 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newNode)
{
	t_list	*node;

	if (!lst || !newNode)
		return ;
	else if (*lst == NULL)
		*lst = newNode;
	else
	{
		node = *lst;
		while (node->next != NULL)
			node = node->next;
		node->next = newNode;
	}
}
