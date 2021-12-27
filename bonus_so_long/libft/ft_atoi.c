/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 01:19:44 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:56:23 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_nb(int neg, unsigned long int nb)
{
	if (neg > 0)
		nb = -1;
	else
		nb = 0;
	return (nb);
}

int	ft_atoi(const char *s1)
{
	int					i;
	int					neg;
	unsigned long int	nb;

	neg = 1;
	i = 0;
	while (s1[i] && (s1[i] == '\t' || s1[i] == '\f' || s1[i] == '\v'
			|| s1[i] == '\n' || s1[i] == '\r' || s1[i] == ' '))
		i++;
	if (s1[i] == '-' || s1[i] == '+')
	{
		if (s1[i] == '-')
			neg = -neg;
		i++;
	}
	nb = 0;
	while (s1[i] && s1[i] >= '0' && s1[i] <= '9')
	{
		nb = nb * 10 + s1[i] - '0';
		i++;
	}
	if ((nb > LONG_MAX && neg > 0) || nb > (unsigned long int)LONG_MIN)
		nb = ft_nb(neg, nb);
	return (nb * neg);
}
