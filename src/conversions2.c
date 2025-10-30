/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:47:18 by kebris-c          #+#    #+#             */
/*   Updated: 2025/08/19 19:17:11 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digits(t_printf *printf)
{
	int	nb;

	nb = va_arg(printf->args, int);
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		printf->count += 11;
		return (printf->count);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		printf->count++;
		nb = -nb;
	}
	ft_print_base((unsigned long long)nb, printf, DEC);
	return (printf->count);
}

int	ft_print_unsigned(t_printf *printf)
{
	unsigned int	nb;

	nb = va_arg(printf->args, unsigned int);
	ft_print_base((unsigned long long)nb, printf, DEC);
	return (printf->count);
}

int	ft_print_ptr(t_printf *printf)
{
	void	*ptr;

	ptr = va_arg(printf->args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		printf->count += 5;
		return (printf->count);
	}
	ft_print_hex_prefix(printf, 1);
	ft_print_base((unsigned long long)ptr, printf, HEX);
	return (printf->count);
}
