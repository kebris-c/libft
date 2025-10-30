/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:37:32 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 15:46:17 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	guess;
	int	next_guess;

	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (nb);
	guess = (nb / 2) + 1;
	next_guess = (guess + (nb / guess)) / 2;
	while (guess != next_guess)
	{
		guess = next_guess;
		next_guess = (guess + (nb / guess)) / 2;
	}
	if (next_guess * next_guess == nb)
		return (next_guess);
	return (0);
}
