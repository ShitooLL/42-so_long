/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mv_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:45:55 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 04:37:03 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

int	ft_key_event(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_A ||
		keycode == KEY_S || keycode == KEY_D)
	{
		ft_move_player(keycode, game);
		ft_collectible(game);
	}
	else if (keycode == ESC)
		ft_exit(game);
	if (game->exit && game->map_data[game->player.p_y][game->player.p_x] == 'E')
	{
		mlx_put_image_to_window(game->render.mlx, game->render.win,
			game->img_end, game->player.p_x * TILE, game->player.p_y * TILE);
	}
	return (0);
}

int	ft_check_move(int keycode, t_game *game)
{
	if ((game->exit && game->map_data[game->player.p_y][game->player.p_x] == 'E') ||
		(game->enemy.eaten == 1))
		return 0;
	else if (keycode == KEY_W &&
		game->map_data[game->player.p_y - 1][game->player.p_x] != '1')
		return (KEY_W);
	else if (keycode == KEY_A &&
		game->map_data[game->player.p_y][game->player.p_x - 1] != '1')
		return (KEY_A);
	else if (keycode == KEY_S &&
		game->map_data[game->player.p_y + 1][game->player.p_x] != '1')
		return (KEY_S);
	else if (keycode == KEY_D &&
		game->map_data[game->player.p_y][game->player.p_x + 1] != '1')
		return (KEY_D);
	return (0);
}

void	ft_display_move(t_game *game)
{
	char	*move;
	char	*tmp;

	tmp = ft_itoa(game->move);
	move = ft_strjoin("move : ", tmp);
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->img_1, 2 * TILE, 0);
	mlx_put_image_to_window(game->render.mlx, game->render.win,
		game->img_1, 3 * TILE, 0);
	mlx_string_put(game->render.mlx, game->render.win, 12, 16,
		0x0000FF, move);
	free(tmp);
	free(move);
}
