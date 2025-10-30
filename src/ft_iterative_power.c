/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:35:30 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 14:25:49 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_power(int nb, int power)
{
	int	re;
	int	i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	i = 0;
	re = 1;
	while (i < power)
	{
		re *= nb;
		i++;
	}
	return (re);
}
