/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 23:49:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 22:59:14 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_move_enemy_w(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->enemy.img_curr, x * TILE, (y - 1) * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y - 1][x] = 'V';
}

void	ft_move_enemy_s(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->enemy.img_curr, x * TILE, (y + 1) * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y + 1][x] = 'U';
}

void	ft_move_enemy_a(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->enemy.img_curr, (x - 1) * TILE, y * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y][x - 1] = 'H';
}

void	ft_move_enemy_d(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->enemy.img_curr, (x + 1) * TILE, y * TILE);
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
		x * TILE, y * TILE);
	game->map_data[y][x] = '0';
	game->map_data[y][x + 1] = 'G';
}
