/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_OpenReadClose.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:23:34 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 14:10:06 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_open_read_close(ssize_t bytes_read, int fd)
{
	const char	*o_err_msg;
	const char	*r_err_msg;
	const char	*c_err_msg;

	o_err_msg = "Cannot open file.\n";
	r_err_msg = "Error reading file.\n";
	c_err_msg = "Error closing file.\n";
	if (fd == -1)
	{
		ft_putstr_fd((char *)o_err_msg, 2);
		close(fd);
		if (close(fd) == -1)
			ft_putstr_fd((char *)c_err_msg, 2);
	}
	else if (bytes_read == -1)
	{
		ft_putstr_fd((char *)r_err_msg, 2);
		close(fd);
	}
	else if (close(fd) == -1)
		ft_putstr_fd((char *)c_err_msg, 2);
	else
		return (0);
	return (-1);
}
