/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:50:58 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/29 15:43:58 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(t_printf *printf)
{
	char	*str;

	str = va_arg(printf->args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		printf->count += 6;
		return (printf->count);
	}
	printf->count += ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printf->count);
}

void	ft_print_base(unsigned long long ptr, t_printf *printf, char *base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (ptr >= base_len)
		ft_print_base(ptr / base_len, printf, base);
	write(1, &base[ptr % base_len], 1);
	printf->count++;
}

int	ft_print_hex_prefix(t_printf *printf, int is_ptr)
{
	if (is_ptr)
	{
		write(1, "0x", 2);
		printf->count += 2;
	}
	return (printf->count);
}
