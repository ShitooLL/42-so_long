/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_mech_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:13:42 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 20:14:27 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "libft.h"

int	ft_check_col(t_game *game)
{
	int	i;
	int	j;

	j = 1;
	while (j < game->map_height - 1)
	{
		i = 1;
		while (i < game->map_length - 1)
		{
			if (game->map_data[j][i] == 'C')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_exit_open(t_game *game)
{
	int	i;
	int	j;

	j = 1;
	while (j < game->map_height - 1)
	{
		i = 1;
		while (i < game->map_length - 1)
		{
			if (game->map_data[j][i] == 'E')
				mlx_put_image_to_window(game->render.mlx, game->render.win,
					game->img_e2, i * TILE, j * TILE);
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_collectible(t_game *game)
{
	if (game->map_data[game->player.p_y][game->player.p_x] == 'C')
	{
		game->map_data[game->player.p_y][game->player.p_x] = '0';
		if (ft_check_col(game))
		{
			game->exit = 1;
			ft_exit_open(game);
		}
	}
}

int	ft_eaten(t_game *game)
{
	char	player_pos;

	player_pos = game->map_data[game->player.p_y][game->player.p_x];
	if (game->enemy.eaten == 1)
		return (1);
	if (player_pos == 'V' || player_pos == 'U' || player_pos == 'H'
		|| player_pos == 'G')
	{
		mlx_put_image_to_window(game->render.mlx, game->render.win,
			game->img_eat, game->player.p_x * TILE, game->player.p_y * TILE);
		game->enemy.eaten = 1;
		return (1);
	}
	return (0);
}
