/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:50:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/28 03:06:19 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

int	ft_check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Number of argument invalid"));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_error("Map format invalid"));
	return (1);
}
