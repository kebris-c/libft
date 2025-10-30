/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:08:46 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 15:30:28 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	if (ft_incorrect_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr_base(-nbr, base);
		return ;
	}
	if (nbr > 9)
		ft_putnbr_base(nbr / base_len, base);
	ft_putchar(base[nbr % base_len]);
}
