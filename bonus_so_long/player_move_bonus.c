/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:55:22 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 01:53:20 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

void	ft_move_w(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->player.img_curr,
		game->player.p_x * TILE, (game->player.p_y - 1) * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_y -= 1;
}

void	ft_move_a(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->player.img_curr,
		(game->player.p_x - 1) * TILE, game->player.p_y * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_x -= 1;
}

void	ft_move_s(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->player.img_curr,
		game->player.p_x * TILE, (game->player.p_y + 1) * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_y += 1;
}

void	ft_move_d(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->player.img_curr,
		(game->player.p_x + 1) * TILE, game->player.p_y * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_x += 1;
}

void	ft_move_player(int keycode, t_game *game)
{
	int		move;

	move = ft_check_move(keycode, game);
	if (move)
	{
		if (move == KEY_W)
			ft_move_w(game);
		else if (move == KEY_A)
			ft_move_a(game);
		else if (move == KEY_S)
			ft_move_s(game);
		else if (move == KEY_D)
			ft_move_d(game);
		game->move++;
		ft_display_move(game);
	}
}
