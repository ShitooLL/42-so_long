/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:32:02 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 04:33:57 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
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
	mlx_string_put(game->render.mlx, game->render.win, 12, 16,
		0x0000FF, "move : 0");
}

void	ft_load_texture(t_game **game)
{
	int	r;

	r = 25;
	(*game)->img_0 = mlx_xpm_file_to_image((*game)->render.mlx, GROUND, &r, &r);
	(*game)->img_1 = mlx_xpm_file_to_image((*game)->render.mlx, WALL, &r, &r);
	(*game)->img_c = mlx_xpm_file_to_image((*game)->render.mlx, COL, &r, &r);
	(*game)->img_e = mlx_xpm_file_to_image((*game)->render.mlx, EXIT, &r, &r);
	(*game)->img_e2 = mlx_xpm_file_to_image((*game)->render.mlx, EXIT2, &r, &r);
	(*game)->img_p = mlx_xpm_file_to_image((*game)->render.mlx, P1, &r, &r);
	(*game)->img_p2 = mlx_xpm_file_to_image((*game)->render.mlx, P2, &r, &r);
	(*game)->img_p4 = mlx_xpm_file_to_image((*game)->render.mlx, P4, &r, &r);
	(*game)->img_end = mlx_xpm_file_to_image((*game)->render.mlx, END, &r, &r);
	(*game)->img_ene = mlx_xpm_file_to_image((*game)->render.mlx, ENE, &r, &r);
	(*game)->img_eat = mlx_xpm_file_to_image((*game)->render.mlx, EAT, &r, &r);
}

void	ft_display_texture(t_game *game, int x, int y)
{
	if (game->map_data[y][x] == '1')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_1,
			x * TILE, y * TILE);			
	else if (game->map_data[y][x] == '0')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			x * TILE, y * TILE);
	else if (game->map_data[y][x] == 'C')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_c,
			x * TILE, y * TILE);
	else if	(game->map_data[y][x] == 'E')
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_e,
			x * TILE, y * TILE);
	else if	(game->map_data[y][x] == 'P' && game->player.p1 == 0)
	{
		game->player.p1 = 1;
		game->player.p_x = x;
		game->player.p_y = y;
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_p,
			x * TILE, y * TILE);
	}
	else if (game->map_data[y][x] == 'P' && game->player.p1 == 1)	
		mlx_put_image_to_window(game->render.mlx, game->render.win, game->img_0,
			x * TILE, y * TILE);
	else if (game->map_data[y][x] == 'H' || game->map_data[y][x] == 'V')
		mlx_put_image_to_window(game->render.mlx, game->render.win,
			game->img_ene, x * TILE, y * TILE);
}
