/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:32:02 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 18:11:35 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	ft_init_map_2(t_game *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	ft_load_texture(&game);
	while (j < game->map_height)
	{
		while (i < game->map_length)
		{
			ft_display_texture(game, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_load_texture(t_game **game)
{
	int	res;

	res = 25;
	(*game)->img_0 = mlx_xpm_file_to_image((*game)->render.mlx, GROUND, &res, &res);
	(*game)->img_1 = mlx_xpm_file_to_image((*game)->render.mlx, WALL, &res, &res);
	(*game)->img_c = mlx_xpm_file_to_image((*game)->render.mlx, COL, &res, &res);
	(*game)->img_e = mlx_xpm_file_to_image((*game)->render.mlx, EXIT, &res, &res);
	(*game)->img_e2 = mlx_xpm_file_to_image((*game)->render.mlx, EXIT2, &res, &res);
	(*game)->img_p = mlx_xpm_file_to_image((*game)->render.mlx, P1, &res, &res);
}

void	ft_display_texture(t_game *game, int x, int y)
{
	if (game->map_data[y][x] == '1')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_1, x * TILE, y * TILE);			
	else if (game->map_data[y][x] == '0')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0, x * TILE, y * TILE);
	else if (game->map_data[y][x] == 'C')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_c, x * TILE, y * TILE);
	else if	(game->map_data[y][x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e, x * TILE, y * TILE);
	else if	(game->map_data[y][x] == 'P')
	{
		game->player.p_x = x;
		game->player.p_y = y;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p, x * TILE, y * TILE);
	}
}
