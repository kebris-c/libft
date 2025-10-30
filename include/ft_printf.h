/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:51:23 by kebris-c          #+#    #+#             */
/*   Updated: 2025/10/29 15:44:19 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

typedef struct s_printf
{
	va_list			args;
	int				count;
}	t_printf;

int		ft_printf(const char *format, ...);
int		ft_print_str(t_printf *printf);
int		ft_print_digits(t_printf *printf);
int		ft_print_unsigned(t_printf *printf);
int		ft_print_ptr(t_printf *printf);
int		ft_print_hex_prefix(t_printf *printf, int is_ptr);
void	ft_print_base(unsigned long long ptr, t_printf *printf, char *base);

#endif
