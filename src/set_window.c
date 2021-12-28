/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:06:00 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 21:19:41 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	set_up_window(t_game *game)
{
	int		screen_width;
	int		screen_height;

	screen_width = TILE * game->map_length;
	screen_height = TILE * game->map_height;
	game->render.win = mlx_new_window(game->render.mlx,
			screen_width, screen_height, "so_long");
	if (!game->render.win)
	{
		free(game->render.mlx);
		ft_free_map_data(game->map_data);
		return (0);
	}
	return (1);
}
