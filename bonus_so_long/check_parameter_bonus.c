/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:50:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 20:09:20 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (ft_error("Number of argument invalid"));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_error("Map format invalid"));
	return (1);
}
