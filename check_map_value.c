/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:19:12 by laliao            #+#    #+#             */
/*   Updated: 2021/12/21 00:56:12 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_wall(t_game *game, int x, int y)
{
	int i;

	i = 0;
	while (i <= x)
	{
		if (game->map_data[0][i] != '1')
			return (0);
		if (game->map_data[y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_side_wall(t_game *game, int x, int y)
{
	int i;

	i = 0;
	while (i <= y)
	{
		if (game->map_data[i][0] != '1')
			return (0);
		if (game->map_data[i][x] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_map_length(t_game *game, int x, int y)
{
	int i;

	i = 0;
	while (i <= y)
	{
		if (ft_strlen(game->map_data[i]) != x)
			return (0);
		i++;
	}
	return (1);
}

int	ft_valid_char(t_game *game, int x, int y)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (j <= y)
	{
		while (i <= x)
		{
			if ((game->map_data[j][i] != '1') && 
				(game->map_data[j][i] != '0') &&
				(game->map_data[j][i] != 'C') &&
				(game->map_data[j][i] != 'P') &&
				(game->map_data[j][i] != 'E'))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	ft_check_map_char(t_game *game, int y)
{
	int	c;
	int	p;
	int	e;
	int	i;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i <= y)
	{
		if (!(ft_strchr(game->map_data[i], 'C')) && c == 0)
			c = 1;
		if (!(ft_strchr(game->map_data[i], 'P')) && p == 0)
			p = 1;
		if (!(ft_strchr(game->map_data[i], 'E')) && e == 0)
			e = 1;
		if (e == 1 && p == 1 && c == 1)
			return (1);
		i++;
	}
	return (0);
}
