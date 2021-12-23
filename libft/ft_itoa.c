/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 21:56:35 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:36:11 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	ft_abs(int n)
{
	long int	nb;

	nb = n;
	if (n < 0)
		return (-nb);
	return (nb);
}

static char	*ft_strrev(char *dest)
{
	size_t		i;
	char		tmp;

	i = 0;
	while (i < ft_strlen(dest) / 2)
	{
		tmp = dest[i];
		dest[i] = dest[ft_strlen(dest) - i - 1];
		dest[ft_strlen(dest) - i - 1] = tmp;
		i++;
	}
	return (dest);
}

static size_t	ft_intlen(int n)
{
	size_t		i;
	long int	tmp;

	i = 1;
	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		i++;
	}
	while (tmp > 9)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		len;
	char		*dest;
	long int	tmp;

	i = 0;
	tmp = ft_abs(n);
	len = ft_intlen(n);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (tmp > 9)
	{
		dest[i] = tmp % 10 + '0';
		tmp = tmp / 10;
		i++;
	}
	dest[i] = tmp + '0';
	if (n < 0)
		dest[len - 1] = '-';
	dest[len] = '\0';
	ft_strrev(dest);
	return (dest);
}
