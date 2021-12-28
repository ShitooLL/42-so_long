/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:19:12 by laliao            #+#    #+#             */
/*   Updated: 2021/12/28 22:38:35 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	ft_valid_char(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (i < x)
		{
			if ((map[j][i] != '1') && (map[j][i] != '0') &&
				(map[j][i] != 'C') && (map[j][i] != 'P') &&
				(map[j][i] != 'E'))
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_map_length(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < (y - 1))
	{
		if ((ft_strlen(map[i]) - 1) != (size_t)x)
			return (0);
		i++;
	}
	if (ft_strlen(map[i]) != (size_t)x)
		return (0);
	return (1);
}

int	ft_check_map_char(char **map, int y)
{
	int	c;
	int	p;
	int	e;
	int	i;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i < y)
	{
		if ((ft_strchr(map[i], 'C')) && c == 0)
			c = 1;
		if ((ft_strchr(map[i], 'P')) && p == 0)
			p = 1;
		if ((ft_strchr(map[i], 'E')) && e == 0)
			e = 1;
		if (e == 1 && p == 1 && c == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_line_wall(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[0][i] != '1')
			return (0);
		if (map[y - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_side_wall(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (map[i][0] != '1')
			return (0);
		if (map[i][x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
