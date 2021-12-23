/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:55:22 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 18:28:30 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	ft_move_W(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
		game->player.p_x * TILE, (game->player.p_y - 1) * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_y -= 1;
}

void	ft_move_A(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
		(game->player.p_x - 1) * TILE, game->player.p_y * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_x -= 1;
}

void	ft_move_S(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
		game->player.p_x * TILE, (game->player.p_y + 1) * TILE);
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			game->player.p_x * TILE, game->player.p_y * TILE);
	else
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			game->player.p_x * TILE, game->player.p_y * TILE);
	game->player.p_y += 1;
}

void	ft_move_D(t_game *game)
{
	mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
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
	int	move;

	move = ft_check_move(keycode, game);
	if (move)
	{
		if (move == KEY_W)
			ft_move_W(game);
		else if (move == KEY_A)
			ft_move_A(game);
		else if (move == KEY_S)
			ft_move_S(game);
		else if (move == KEY_D)
			ft_move_D(game);
		game->move++;
		printf("Number of move : %d\n", game->move);
	}
}
