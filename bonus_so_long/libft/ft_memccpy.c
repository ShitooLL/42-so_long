/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:49:49 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:18:54 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*tmpdest;
	const unsigned char	*tmpsrc;

	if (!dest && !src)
		return (NULL);
	tmpdest = (unsigned char *)dest;
	tmpsrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*tmpdest = *tmpsrc;
		i++;
		if (*tmpsrc == (unsigned char)c)
		{
			return (dest + i);
		}
		tmpdest++;
		tmpsrc++;
	}
	return (NULL);
}
