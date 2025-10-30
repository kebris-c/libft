/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:28:24 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 18:26:25 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ndl_len;

	ndl_len = ft_strlen(needle);
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char *)haystack);
	if (ndl_len > len)
		return (NULL);
	while (*haystack && len >= ndl_len)
	{
		i = 0;
		while (haystack[i] == needle[i] && needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
