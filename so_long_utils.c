/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:05:06 by laliao            #+#    #+#             */
/*   Updated: 2021/12/22 15:39:41 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(ft_strlen(s2)))
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] && i + j < len)
		{
			if (s2[j + 1] == '\0')
				return ((char *)s1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*ft_realloc(void **src, size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (!dst)
	{
		free((*src));
		return (NULL);
	}
	if (!(*src))
	{
		free(dst);
		return (NULL);
	}
	ft_memmove(dst, (*src), size);
	free((*src));
	(*src) = NULL;
	return (dst);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmpdest;
	const char	*tmpsrc;

	if (!dest && !src)
		return (NULL);
	tmpdest = dest;
	tmpsrc = src;
	i = 0;
	while (i < n)
	{
		*tmpdest++ = *tmpsrc++;
		i++;
	}
	return (dest);
}


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmpdest;
	const char	*tmpsrc;

	if (!dest && !src)
		return (NULL);
	tmpdest = dest;
	tmpsrc = src;
	if (dest <= src)
		ft_memcpy(tmpdest, tmpsrc, n);
	else
		while (n--)
			tmpdest[n] = tmpsrc[n];
	return (dest);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;
	char	*tmpptr;

	tmpptr = ptr;
	i = 0;
	while (i < n)
	{
		*(tmpptr + i) = '\0';
		i++;
	}
}
