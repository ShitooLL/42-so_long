/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:06:00 by laliao            #+#    #+#             */
/*   Updated: 2021/12/21 21:28:42 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_up_window_2(t_render *render, t_game *game)
{
	int		screen_width;
	int		screen_height;

	screen_width = 20 * game->map_length;
	screen_height = 20 * game->map_height;
	printf("x : %d, y : %d\n", game->map_length, game->map_height);
	render->window = mlx_new_window(render->mlx, screen_width, screen_height, "so_long");
	return (1);
}


/*
int	check_wall_x(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i])
	{
		if (line[i] != 1)
			return (-1);
		i++;
	}
	return (0);
}

t_point	*ft_init_value(t_point *screen)
{
	screen->y = 0;
	screen->x = 0;
	return (screen);
}

int	check_value(t_point *screen, char *line)
{
	if ((screen->y == 0 && check_wall_x(line) == -1) ||
		(line[0] != 1 || line[ft_strlen(line) - 1] != 1) ||
		(screen->y == 1 && check_wall_x(line) == 0))
		return (1);
	if (screen->x < 2)
		return (1);
	return (0);
}

t_point	*check_map(char *argv, t_point *screen)
{
	int		fd;
	char	*line;
	int i = 0;

	screen->y = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_init_value(screen));
	line = get_next_line(fd);
	screen->x = ft_strlen(line);
	while (i++ < 8)
	{
		if (check_value(screen, line))
			return (ft_init_value(screen));
		if (screen->y > 1 && check_wall_x(line) == 0)
			break ;
		free(line);
		line = get_next_line(fd);
		screen->y++;
	}
	if (check_wall_x(line) == -1)
		return (ft_init_value(screen));
	free(line);
	close (fd);
	return (screen);
}

void	*set_up_window(void *mlx, t_point *screen)
{
	void	*window;
	int		screen_width;
	int		screen_height;

	screen_width = 20 * screen->x;
	screen_height = 20 * screen->y;
	printf("x : %d, y : %d\n", screen->x, screen->y);
	window = mlx_new_window(mlx, screen_width, screen_height, "so_long");
	return (window);
}*/
