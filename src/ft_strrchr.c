/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:04:38 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 17:08:08 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*value;
	size_t	len;

	value = NULL;
	len = ft_strlen(str);
	str = str + len;
	if ((char)c == '\0')
		return ((char *)str);
	while (len--)
	{
		str--;
		if (*str == (char)c)
			return ((char *)str);
	}
	return (NULL);
}
