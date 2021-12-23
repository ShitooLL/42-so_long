/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 02:28:24 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:42:48 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	k = 0;
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	while (j > i && ft_isset(s1[j - 1], set))
		j--;
	dest = malloc(sizeof(*s1) * (j - i) + 1);
	if (!dest)
		return (NULL);
	while (k + i < j)
	{
		dest[k] = s1[k + i];
		k++;
	}
	dest[k] = '\0';
	return (dest);
}
