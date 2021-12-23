/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:32:02 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:19:33 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_map_2(t_render *render, t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	ft_load_texture(render, &game);
	while (j < game->map_height)
	{
		while (i < game->map_length)
		{
			ft_display_texture(render, game, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_load_texture(t_render *render, t_game **game)
{
	int	res;

	res = 20;
	(*game)->img_0 = mlx_xpm_file_to_image(render->mlx, GROUND, &res, &res);
	(*game)->img_1 = mlx_xpm_file_to_image(render->mlx, WALL, &res, &res);
	(*game)->img_c = mlx_xpm_file_to_image(render->mlx, COL, &res, &res);
	(*game)->img_e = mlx_xpm_file_to_image(render->mlx, EXIT, &res, &res);
}

void	ft_display_texture(t_render *render,t_game *game, int x, int y)
{
	if (game->map_data[y][x] == '1')
		mlx_put_image_to_window(render->mlx, render->window, game->img_1, x * 25, y * 25);			
	else if (game->map_data[y][x] == '0')
		mlx_put_image_to_window(render->mlx, render->window, game->img_0, x * 25, y * 25);
	else if (game->map_data[y][x] == 'C')
		mlx_put_image_to_window(render->mlx, render->window, game->img_c, x * 25, y * 25);
	else if	(game->map_data[y][x] == 'E')
		mlx_put_image_to_window(render->mlx, render->window, game->img_e, x * 25, y * 25);
}
