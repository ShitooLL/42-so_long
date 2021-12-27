/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:33:33 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 20:09:41 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_vertical_enemy(t_game *game, int x, int y, char dir)
{
	if (dir == 'V')
	{
		if (game->map_data[y - 1][x] == '0')
			ft_move_enemy_w(game, x, y);
		else
			game->map_data[y][x] = 'U';
	}
	else if (dir == 'U')
	{
		if (game->map_data[y + 1][x] == '0')
			ft_move_enemy_s(game, x, y);
		else
			game->map_data[y][x] = 'V';
	}
}

void	ft_horizontal_enemy(t_game *game, int x, int y, char dir)
{
	if (dir == 'H')
	{
		if (game->map_data[y][x - 1] == '0')
			ft_move_enemy_a(game, x, y);
		else
			game->map_data[y][x] = 'G';
	}
	else if (dir == 'G')
	{
		if (game->map_data[y][x + 1] == '0')
			ft_move_enemy_d(game, x, y);
		else
			game->map_data[y][x] = 'H';
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
			if (game->map_data[y][x] == 'V' || game->map_data[y][x] == 'U')
			{
				ft_vertical_enemy(game, x, y, game->map_data[y][x]);
				if (game->map_data[y + 1][x] == 'U')
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
			if (game->map_data[y][x] == 'H' || game->map_data[y][x] == 'G')
			{
				ft_horizontal_enemy(game, x, y, game->map_data[y][x]);
				if (game->map_data[y][x + 1] == 'G')
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
