/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:50:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 02:25:08 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	ft_check_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 2)
		return (0);
	if (!ft_strnstr(argv[1],".ber", ft_strlen(argv[1])))
		return (0);
	return (1);
}
