/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:33:33 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 04:12:31 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_vertical_enemy(t_game *game, int x, int y)
{
	if (game->enemy.dir_v == 0)
	{
		if (game->map_data[y - 1][x] == '0')
			ft_move_enemy_w(game, x, y);
		else
			game->enemy.dir_v = 1;
	}
	else if (game->enemy.dir_v == 1)
	{
		if (game->map_data[y + 1][x] == '0')
			ft_move_enemy_s(game, x, y);
		else
			game->enemy.dir_v = 0;
	}
}

void	ft_horizontal_enemy(t_game *game, int x, int y)
{
	if (game->enemy.dir_h == 0)
	{
		if (game->map_data[y][x - 1] == '0')
			ft_move_enemy_a(game, x, y);
		else
			game->enemy.dir_h = 1;
	}
	else if (game->enemy.dir_h == 1)
	{
		if (game->map_data[y][x + 1] == '0')
			ft_move_enemy_d(game, x, y);
		else
			game->enemy.dir_h = 0;
	}
}

void	ft_check_vert_enemy(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	while (x < game->map_length - 1)
	{
		y = 1;
		while (y < game->map_height - 1)
		{
			if (game->map_data[y][x] == 'V')
			{
				ft_vertical_enemy(game, x, y);
				if (game->enemy.dir_v == 1)
					y++;
			}
			y++;
		}
		x++;
	}
}

void	ft_check_hori_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 1;
	while (y < game->map_height - 1)
	{
		x = 1;
		while (x < game->map_length - 1)
		{
			if (game->map_data[y][x] == 'H')
			{
				ft_horizontal_enemy(game, x, y);
				if (game->enemy.dir_h == 1)
					x++;
			}
			x++;
		}
		y++;
	}
}


void	ft_enemy(t_game *game)
{
	if (game->speed > FRAME * 3)
	{
		ft_check_vert_enemy(game);
		ft_check_hori_enemy(game);
		game->speed = 0;
	}
}
