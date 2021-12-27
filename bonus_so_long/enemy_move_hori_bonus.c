/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_hori_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 01:36:01 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 03:56:30 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_move_enemy_a(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_ene,
		(x - 1) * TILE, y * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y][x - 1] = 'H';
}

void	ft_move_enemy_d(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_ene,
		(x + 1) * TILE, y * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y][x + 1] = 'H';
}
