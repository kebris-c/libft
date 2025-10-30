/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:37:23 by kebris-c          #+#    #+#             */
/*   Updated: 2025/08/22 12:59:32 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd_node	*find_or_create_node(t_fd_node **head, int fd)
{
	t_fd_node	*current;
	t_fd_node	*new_node;

	current = *head;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	new_node = malloc(sizeof(t_fd_node));
	if (!new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->stash = NULL;
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

static char	*extract_line(char *stash)
{
	char	*newline_pos;
	char	*line;
	int		line_len;
	int		i;

	if (!stash || !*stash)
		return (NULL);
	newline_pos = ft_strchr(stash, '\n');
	if (newline_pos)
		line_len = newline_pos - stash + 1;
	else
		line_len = ft_strlen(stash);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *old_stash)
{
	char	*newline_pos;
	char	*new_stash;

	newline_pos = ft_strchr(old_stash, '\n');
	if (!newline_pos)
	{
		free(old_stash);
		return (NULL);
	}
	if (!(*(newline_pos + 1)))
	{
		free(old_stash);
		return (NULL);
	}
	new_stash = ft_strdup(newline_pos + 1);
	free(old_stash);
	return (new_stash);
}

static int	read_and_stash(t_fd_node *node, t_aux *aux, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(node->stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), -1);
		buffer[bytes_read] = '\0';
		if (!node->stash)
			node->stash = ft_strdup(buffer);
		else
		{
			aux->tmp = ft_strjoin(node->stash, buffer);
			free(node->stash);
			node->stash = aux->tmp;
		}
		if (!node->stash)
			return (free(buffer), -1);
	}
	return (free(buffer), 0);
}

char	*get_next_line(int fd)
{
	static t_fd_node	*fd_list;
	t_fd_node			*current;
	t_aux				*aux;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd)
			ft_delete_node(&fd_list, fd);
		return (NULL);
	}
	current = find_or_create_node(&fd_list, fd);
	aux = malloc(sizeof(t_aux));
	if (!current || !aux)
		return (NULL);
	if (read_and_stash(current, aux, fd) < 0)
		return (free(aux), ft_delete_node(&fd_list, fd), NULL);
	free(aux);
	line = extract_line(current->stash);
	if (!line)
		return (ft_delete_node(&fd_list, fd), NULL);
	current->stash = update_stash(current->stash);
	if (!current->stash)
		ft_delete_node(&fd_list, fd);
	return (line);
}
