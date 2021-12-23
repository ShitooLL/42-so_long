/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:18:26 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 02:25:04 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game		game_data;
	t_render	render;

	ft_bzero(&game_data, sizeof(game_data));
	ft_bzero(&render, sizeof(render));
	game_data.map_data = ft_get_map(argc, argv, &game_data);
	if (game_data.map_data == NULL)
		return (-1);
	render.mlx = mlx_init();
	if (!(set_up_window_2(&render, &game_data)))
		return (-1);
	ft_init_map_2(&render, &game_data);
	ft_free_map_data(game_data.map_data);
	mlx_loop(render.mlx);
	return (0);
}
