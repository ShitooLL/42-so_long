/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:40:37 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:29:30 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
