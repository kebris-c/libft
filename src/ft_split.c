/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kebris-c <kebris-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:01:19 by kebris-c          #+#    #+#             */
/*   Updated: 2025/04/17 16:16:42 by kebris-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wcount(const char *str, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			len++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (len);
}

static size_t	ft_wlen(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static void	*ft_free(char **tab, int j)
{
	while (j-- > 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

static char	**ft_fill(char **split, const char *str, char c)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (!str[i])
			break ;
		len = ft_wlen(&str[i], c);
		split[j] = malloc(sizeof(char) * (len + 1));
		if (!split[j])
			return (ft_free(split, j));
		len = 0;
		while (str[i] && str[i] != c)
			split[j][len++] = str[i++];
		split[j++][len] = '\0';
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *str, char c)
{
	char	**split;
	size_t	count;

	if (!str)
		return (NULL);
	count = ft_wcount(str, c);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	return (ft_fill(split, str, c));
}
