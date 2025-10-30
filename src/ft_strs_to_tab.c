/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:56:43 by kebris-c          #+#    #+#             */
/*   Updated: 2025/09/02 15:03:27 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_struct(t_stock_str **tab)
{
	if ((*tab)->str)
		free((*tab)->str);
	if ((*tab)->copy)
		free((*tab)->copy);
	if (*tab)
		free(*tab);
	if (tab)
		free(tab);
	tab = NULL;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(tab[i].str);
		if (!tab[i].copy)
		{
			ft_free_struct(&tab);
			return (NULL);
		}
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
