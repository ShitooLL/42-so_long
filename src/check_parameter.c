/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:50:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/28 22:12:27 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	ft_check_args(int argc, char **argv, t_game *game)
{
	if (argc != 2)
	{
		free(game->render.mlx);
		return (ft_error("Number of argument invalid"));
	}
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		free(game->render.mlx);
		return (ft_error("Map format invalid"));
	}
	return (1);
}
