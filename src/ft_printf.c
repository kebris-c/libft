/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:51:05 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/29 16:00:14 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_parse_flags(char const *format, t_printf *printf)
{
	int	c;

	if (*format == 'c')
	{
		c = va_arg(printf->args, int);
		write(1, &c, 1);
		printf->count++;
	}
	else if (*format == 's')
		ft_print_str(printf);
	else if (*format == 'p')
		ft_print_ptr(printf);
	else if (*format == 'x')
		ft_print_base(va_arg(printf->args, unsigned int), printf, HEX);
	else if (*format == 'd' || *format == 'i')
		ft_print_digits(printf);
	else if (*format == 'u')
		ft_print_unsigned(printf);
	else if (*format == 'X')
		ft_print_base(va_arg(printf->args, unsigned int), printf, HEXUP);
	else if (*format == '%')
		printf->count += write(1, "%", 1);
	else
		return (FALSE);
	return (TRUE);
}

int	ft_printf(char const *format, ...)
{
	t_printf	printf;
	char		c;

	if (!format)
		return (-1);
	printf.count = 0;
	va_start(printf.args, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			if (ft_parse_flags(format + 1, &printf))
			{
				format += 2;
				continue ;
			}
		}
		c = *format;
		write(1, &c, 1);
		printf.count++;
		format++;
	}
	va_end(printf.args);
	return (printf.count);
}
