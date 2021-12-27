/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:07:40 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:36:31 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbrprc(long int n, int fd)
{
	if (n > 9)
	{
		ft_nbrprc(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	tmp;

	tmp = n;
	if (tmp < 0)
	{
		tmp = -tmp;
		ft_putchar_fd('-', fd);
	}
	ft_nbrprc(tmp, fd);
}
