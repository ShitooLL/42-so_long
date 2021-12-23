/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:35:37 by laliao            #+#    #+#             */
/*   Updated: 2021/01/11 03:30:00 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int nb, size_t n)
{
	size_t			i;
	unsigned char	*tmpptr;

	tmpptr = ptr;
	i = 0;
	while (i < n)
	{
		*(tmpptr + i) = (unsigned char)nb;
		i++;
	}
	return (ptr);
}
