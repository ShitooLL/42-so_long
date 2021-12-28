/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:39:22 by laliao            #+#    #+#             */
/*   Updated: 2021/12/28 21:54:02 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

int	ft_file_linecount(char *file)
{
	int		linecount;
	int		readcount;
	int		fd;
	char	c;

	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (-1);
	linecount = 1;
	while (1)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close (fd);
	return (linecount);
}

void	ft_free_map_data(char **game_map)
{
	int		i;
	char	**map;

	map = game_map;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

char	**ft_read_map(char *map_file, int *x, int *y)
{
	int		fd;
	int		i;
	char	**map;

	i = 0;
	*y = ft_file_linecount(map_file);
	fd = open(map_file, O_RDONLY);
	if ((*y) <= 0 || (fd < 0))
		return (NULL);
	map = malloc(sizeof(char *) * ((*y) + 1));
	if (!map)
		return (NULL);
	map[i] = get_next_line(fd);
	if (!(map[i]))
		return (NULL);
	*x = ft_strlen(map[i]) - 1;
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	close(fd);
	return (map);
}

int	ft_check_map_value(char **map, int x, int y)
{
	if (!ft_map_length(map, x, y))
		return (ft_error("Unvalid map length"));
	else if (!ft_valid_char(map, x, y))
		return (ft_error("Unvalid character"));
	else if (!ft_check_map_char(map, y))
		return (ft_error("Need atleast 1 exit, 1 collectable and 1 start"));
	else if (!ft_line_wall(map, x, y))
		return (ft_error("Unvalid line wall"));
	else if (!ft_side_wall(map, x, y))
		return (ft_error("Unvalid side wall\n"));
	return (1);
}

char	**ft_get_map(int argc, char **argv, t_game *game)
{
	int		x;
	int		y;
	char	**map;

	if (!ft_check_args(argc, argv))
		return (NULL);
	map = ft_read_map(argv[1], &x, &y);
	if (map == NULL)
		return (NULL);
	if (!ft_check_map_value(map, x, y))
	{
		free(game->render.mlx);
		ft_free_map_data(map);
		return (NULL);
	}
	game->map_height = y;
	game->map_length = x;
	return (map);
}
