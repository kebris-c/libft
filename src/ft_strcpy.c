/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:21:45 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 16:55:32 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	k;

	i = 0;
	while (tab[i] && k < size)
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
