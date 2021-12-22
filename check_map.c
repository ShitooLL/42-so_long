/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:39:22 by laliao            #+#    #+#             */
/*   Updated: 2021/12/22 19:10:03 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"

int	ft_file_linecount(char *file)
{
	int		linecount;
	int		readcount;
	int		fd;
	char	c;

	fd = open (file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (true)
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

void	ft_free_map_data(t_game *game)
{
	int i;
	char **map;

	map = game->map_data;
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
	if ((*y) <= 0)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * ((*y) + 1));
	if (!map)
		return (NULL);
	map[i] = get_next_line(fd);
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
	if (!ft_valid_char(map, x, y))
		return (0);
	else if (!ft_map_length(map, x, y))
		return (0);
	else if (!ft_check_map_char(map, y))
		return (0);
	else if (!ft_line_wall(map, x, y))
		return (0);
	else if (!ft_side_wall(map, x, y))
		return (0);
	return (1);
}

char	**ft_get_map(int argc, char **argv, t_game *game)
{
	int	x;
	int	y;
	char **map;

	if (!ft_check_args(argc, argv))
		return (NULL);
	map = ft_read_map(argv[1], &x, &y);
	if (map == NULL)
		return (NULL);
	if (!ft_check_map_value(map, x, y))
		return(NULL);
	printf("x = %d, y = %d\n", x, y);
	game->map_height = y;
	game->map_length = x;
	return (map);
}
