/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:17:16 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 15:45:17 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < size)
	{
		k = i + 1;
		while (tab[k])
		{
			if (tab[i] > tab[k])
				ft_swap(&tab[i], &tab[k]);
			k++;
		}
		i++;
	}
}
