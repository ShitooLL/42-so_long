/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 21:31:03 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 22:57:37 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long_bonus.h"

void	ft_ani_enemy_1(t_game *game)
{
	if (game->enemy.counter > SPEED && game->enemy.curr == 0)
	{
		game->enemy.img_curr = game->img_ene;
		game->enemy.curr = 1;
	}
	else if (game->enemy.counter > SPEED * 2 && game->enemy.curr == 1)
	{
		game->enemy.img_curr = game->img_ene2;
		game->enemy.curr = 2;
	}
}

void	ft_ani_enemy_2(t_game *game)
{
	if (game->enemy.counter > SPEED * 3 && game->enemy.curr == 2)
	{
		game->enemy.img_curr = game->img_ene;
		game->enemy.curr = 3;
	}
	else if (game->enemy.counter > SPEED * 4 && game->enemy.curr == 3)
	{
		game->enemy.img_curr = game->img_ene4;
		game->enemy.curr = 0;
		game->enemy.counter = 0;
	}
}
