/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:39:45 by kebris-c          #+#    #+#             */
/*   Updated: 2025/09/08 20:50:39 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_fd_node
{
	int					fd;
	char				*stash;
	struct s_fd_node	*next;
}	t_fd_node;

typedef struct s_aux
{
	char	*tmp;
}	t_aux;

char	*get_next_line(int fd);
void	ft_delete_node(t_fd_node **head, int fd);

#endif
