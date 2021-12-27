/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:55:07 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 04:35:22 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_ani_player_1(t_game *game)
{
	if (game->counter > FRAME && game->player.curr == 0)
	{
		game->player.img_curr = game->img_p;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
			game->player.p_x * TILE, game->player.p_y * TILE);
		game->player.curr = 1;
	}
	else if (game->counter > FRAME * 2 && game->player.curr == 1)
	{
		game->player.img_curr = game->img_p2;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p2,
			game->player.p_x * TILE, game->player.p_y * TILE);
		game->player.curr = 2;
	}
}

void	ft_ani_player_2(t_game *game)
{
	if (game->counter > FRAME * 3 && game->player.curr == 2)
	{	
		game->player.img_curr = game->img_p;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
			game->player.p_x * TILE, game->player.p_y * TILE);
		game->player.curr = 3;
	}
	else if (game->counter > FRAME * 4 && game->player.curr == 3)
	{
		game->player.img_curr = game->img_p4;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p4,
			game->player.p_x * TILE, game->player.p_y * TILE);
		game->player.curr = 0;
		game->counter = 0;
	}
}

int	ft_loop_hook(t_game *game)
{
	if (game->map_data[game->player.p_y][game->player.p_x] == 'V' ||
		game->map_data[game->player.p_y][game->player.p_x] == 'H' ||
		game->enemy.eaten == 1)
	{
		mlx_put_image_to_window(game->render.mlx, game->render.win,
			game->img_eat, game->player.p_x * TILE, game->player.p_y * TILE);	
		game->enemy.eaten = 1;
		return (0);
	}
	ft_enemy(game);
	game->speed++;
	if (game->exit && game->map_data[game->player.p_y][game->player.p_x] == 'E')
		return (0);
	else if (game->player.curr < 2)
		ft_ani_player_1(game);
	else
		ft_ani_player_2(game);
	game->counter++;
	return (0);
}
