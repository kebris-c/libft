/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:12:24 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 15:29:02 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_combn_aux(char *nb)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		nb[i] = i + '0';
		ft_putchar(nb[i]);
		if (i + 1 != 10)
			ft_putstr(", ");
		else if (i + 1 == 10)
			ft_putchar('\n');
		i++;
	}
	nb[i] = 0;
}

static void	ft_print_combn_aux2(char *nb, int n)
{
	int	i;

	i = 1;
	while (i < n && nb[i] && i > 0 && i < 10)
	{
		nb[i] = nb[i - 1] + 1;
		ft_putstr(nb);
		if (i + 1 != 10)
			ft_putstr(", ");
		else if (i + 1 == 10)
			ft_putchar('\n');
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	*nb;

	if (n <= 0 || n >= 10)
		return ;
	else if (n == 1)
	{
		nb = (char *)malloc(sizeof(char) * 10);
		ft_print_combn_aux(nb);
		free(nb);
		return ;
	}
	nb = (char *)malloc(sizeof(char) * 10);
	nb[0] = 0;
	ft_print_combn_aux2(nb, n);
	free(nb);
}
