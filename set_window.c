/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:06:00 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:20:13 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_up_window_2(t_render *render, t_game *game)
{
	int		screen_width;
	int		screen_height;

	screen_width = 25 * game->map_length;
	screen_height = 25 * game->map_height;
	printf("x : %d, y : %d\n", game->map_length, game->map_height);
	render->window = mlx_new_window(render->mlx, screen_width, screen_height, "so_long");
	return (1);
}
