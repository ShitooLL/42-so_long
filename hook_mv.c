/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:45:55 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 20:46:02 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	ft_key_event(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D)
	{
		ft_move_player(keycode, game);
		if (game->exit == 0)
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
	if (game->map_data[game->player.p_y][game->player.p_x] == 'E'
			&& game->exit)
		return (0);
	if (keycode == KEY_W
		&& game->map_data[game->player.p_y - 1][game->player.p_x] != '1')
		return (KEY_W);
	else if (keycode == KEY_A
		&& game->map_data[game->player.p_y][game->player.p_x - 1] != '1')
		return (KEY_A);
	else if (keycode == KEY_S
		&& game->map_data[game->player.p_y + 1][game->player.p_x] != '1')
		return (KEY_S);
	else if (keycode == KEY_D
		&& game->map_data[game->player.p_y][game->player.p_x + 1] != '1')
		return (KEY_D);
	return (0);
}
