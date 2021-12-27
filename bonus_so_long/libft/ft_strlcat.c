/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 22:31:20 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:40:58 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;

	src_len = 0;
	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[src_len])
		src_len++;
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[j] && j + i + 1 < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + src_len);
}
