/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:06:00 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 20:25:45 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	set_up_window_2(t_game *game)
{
	int		screen_width;
	int		screen_height;

	screen_width = TILE * game->map_length;
	screen_height = TILE * game->map_height;
	game->render.win = mlx_new_window(game->render.mlx,
			screen_width, screen_height, "so_long");
	return (1);
}
