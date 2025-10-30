/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:44:35 by kebris-c          #+#    #+#             */
/*   Updated: 2025/08/22 13:27:31 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	i;
	size_t	src_len;

	if (!src)
		return (NULL);
	src_len = ft_strlen(src);
	dup = malloc(sizeof(char) * (src_len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
