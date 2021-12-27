/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 03:27:59 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:34:55 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	count;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
			word = 1;
		if ((s[i] == c || s[i + 1] == '\0') && word == 1)
		{
			count++;
			word = 0;
		}
		i++;
	}
	return (count);
}

static void	*ft_free_split(char **dest, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
	return (NULL);
}

static void	*ft_strsplit(char **dest, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] == c)
			start++;
		else
		{
			end = 0;
			while (s[start + end] != c && s[start + end])
				end++;
			dest[i] = ft_substr(s, start, end);
			if (!(dest[i]))
				return (ft_free_split(dest, ft_countwords(s, c) + 1));
			i++;
			start += end;
		}
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * ft_countwords(s, c) + 1);
	if (!dest)
		return (NULL);
	dest = ft_strsplit(dest, s, c);
	if (!dest)
		return (NULL);
	dest[ft_countwords(s, c)] = 0;
	return (dest);
}
