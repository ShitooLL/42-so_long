/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 23:46:41 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:28:59 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
