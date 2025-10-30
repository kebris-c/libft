/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:42:39 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/24 17:19:07 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_display_file(char *filename, size_t size)
{
	char	*buffer;
	int		bytes_read;
	int		fd;

	buffer = malloc(sizeof(char) * size);
	fd = open(filename, O_RDONLY);
	bytes_read = 0;
	if (ft_check_open_read_close(bytes_read, fd) == -1)
		return (-1);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		buffer[bytes_read] = '\0';
		ft_putstr(buffer);
	}
	free(buffer);
	if (ft_check_open_read_close(bytes_read, fd) == -1)
		return (-1);
	else
		return (0);
}
