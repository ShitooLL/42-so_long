/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:32:02 by laliao            #+#    #+#             */
/*   Updated: 2021/12/22 20:46:23 by laliao           ###   ########.fr       */
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
		mlx_put_image_to_window(render->mlx, render->window, game->img_1, x * 20, y * 20);			
	else if (game->map_data[y][x] == '0')
		mlx_put_image_to_window(render->mlx, render->window, game->img_0, x * 20, y * 20);
	else if (game->map_data[y][x] == 'C')
		mlx_put_image_to_window(render->mlx, render->window, game->img_c, x * 20, y * 20);
	else if	(game->map_data[y][x] == 'E')
		mlx_put_image_to_window(render->mlx, render->window, game->img_e, x * 20, y * 20);
}

/*
int	display_ground(void *mlx, void *window, char *map_line, int y)
{
	int i;
	int	x;
	char *path;
	void	*img_ground;
	int	reso;

	i = 0;
	x = 0;
	reso = 20;
	path ="./asset/ground.xpm";
	img_ground = mlx_xpm_file_to_image(mlx, path, &reso, &reso);
	while (map_line[i])
	{
		mlx_put_image_to_window(mlx, window, img_ground, x, y);
		i++;
		x += 20;
	}
	return (0);
}

int	display_wall(void *mlx, void *window, char *map_line, int y)
{
	int	i;
	int	x;
	void	*img_bush;
	char	*path;
	int	reso;

	i = 0;
	x = 0;
	reso = 20;
	path = "./asset/bush.xpm";
	img_bush = mlx_xpm_file_to_image(mlx, path, &reso, &reso);
	while (map_line[i])
	{
		if (map_line[i] == 1)
			mlx_put_image_to_window(mlx, window, img_bush, x, y);
		i++;
		x += 20;
	}
	return (0);
}

void	init_map(void *mlx, void *window, int fd)
{
	char	*map_line;
	int		y;
	int		i = 0;

	y = 0;
	map_line = get_next_line(fd);
	while (i++ < 8)
	{
		display_ground(mlx, window, map_line, y);
		display_wall(mlx, window, map_line, y);
		free(map_line);
		map_line = get_next_line(fd);
		y += 20;
	}
	free(map_line);
}
*/
