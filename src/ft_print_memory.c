/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:28:14 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 13:12:36 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_addr(unsigned long addr, char *base)
{
	char	*hex;
	char	hex_addr[17];
	int		i;

	hex = base;
	hex_addr[16] = 0;
	i = 15;
	while (i >= 0)
	{
		hex_addr[i--] = hex[addr % 16];
		addr /= 16;
	}
	ft_putstr(hex_addr);
	ft_putstr(": ");
}

static void	ft_print_memory_content(unsigned char *ptr, int size, char *base)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < size)
		{
			ft_putnbr_base(ptr[i], base);
			if (i % 2)
				ft_putchar(' ');
		}
		else
			ft_putstr("  ");
		i++;
	}
}

static void	ft_print_ascii(unsigned char *ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ptr[i] >= 32 && ptr[i] <= 126)
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, int size)
{
	int				i;
	int				line_size;
	unsigned char	*ptr;
	char			*base;

	i = 0;
	ptr = (unsigned char *)addr;
	base = "0123456789abcdef";
	while (i < size)
	{
		if (size - i >= 16)
			line_size = 16;
		else
			line_size = size - i;
		ft_print_addr((unsigned long)(ptr + i), base);
		ft_print_memory_content(ptr + i, line_size, base);
		ft_print_ascii(ptr + i, line_size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
