/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:10:49 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 14:05:23 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_pos(char nb, char *base)
{
	int	pos;

	pos = 0;
	while (base[pos])
	{
		if (nb == base[pos])
			return (pos);
		pos++;
	}
	return (-1);
}

static t_bool	ft_valid_number(char *nbr, char *base)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
		i++;
	if (!nbr[i])
		return (FALSE);
	while (nbr[i])
	{
		if (ft_base_pos(nbr[i], base) == -1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	ft_skipper(char *nbr, int *i, int *sign)
{
	while (nbr[*i] == ' ' || (nbr[*i] >= 9 && nbr[*i] <= 13))
		(*i)++;
	while (nbr[*i] == '-' || nbr[*i] == '+')
	{
		if (nbr[*i] == '-')
			*sign = -*sign;
		(*i)++;
	}
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	sign;
	int	re;
	int	i;
	int	pos;
	int	base_len;

	if (ft_incorrect_base(base) || !ft_valid_number(nbr, base))
		return (ATOI_BASE_ERROR);
	i = 0;
	re = 0;
	sign = 1;
	ft_skipper(nbr, &i, &sign);
	base_len = ft_strlen(base);
	while (nbr[i])
	{
		pos = ft_base_pos(nbr[i], base);
		re = re * base_len + pos;
		i++;
	}
	return (re * sign);
}
