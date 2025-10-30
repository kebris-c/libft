/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:18:18 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 19:34:05 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, size_t start, size_t end)
{
	char	*arr;
	size_t	i;
	size_t	str_len;
	size_t	len;

	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	len = end + 1;
	if (end >= str_len)
		len = str_len + 1;
	arr = ft_calloc(sizeof(char), len);
	if (!arr)
		return (NULL);
	i = 0;
	while (end-- > 0 && str[start + i])
	{
		arr[i] = str[start + i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
