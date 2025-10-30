/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:33:34 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 14:25:12 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	re;

	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	i = nb;
	re = 1;
	while (i > 1)
	{
		re *= i;
		i--;
	}
	return (re);
}
