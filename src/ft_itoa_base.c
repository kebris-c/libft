/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:56:58 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 17:20:23 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int nb, int base_len)
{
	int		len;
	long	temp;

	len = 0;
	temp = (long)nb;
	if (nb < 0)
	{
		len++;
		temp = -(long)nb;
	}
	while (temp)
	{
		temp /= base_len;
		len++;
	}
	return (len);
}

static char	*ft_strdup_char(char c)
{
	char	*dup;

	dup = (char *)malloc(sizeof(char) * 2);
	if (!dup)
		return (NULL);
	dup[0] = c;
	dup[1] = 0;
	return (dup);
}

char	*ft_itoa_base(int nb, char *base)
{
	int		base_len;
	int		len;
	char	*nbr;

	if (ft_incorrect_base(base))
		return (NULL);
	base_len = ft_strlen(base);
	if (nb == 0)
		return (ft_strdup_char(base[0]));
	len = ft_itoa_len(nb, base_len);
	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = 0;
	if (nb < 0)
		nbr[0] = '-';
	while (nb)
	{
		nbr[--len] = base[nb % base_len];
		nb /= base_len;
	}
	return (nbr);
}
