/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:18:26 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 19:39:11 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_game		game_data;

	ft_bzero(&game_data, sizeof(game_data));	
	game_data.map_data = ft_get_map(argc, argv, &game_data);
	if (game_data.map_data == NULL)
		return (-1);
	game_data.render.mlx = mlx_init();
	if (!(set_up_window_2(&game_data)))
		return (-1);
	ft_init_map_2(&game_data);
	printf("player x : %d\n", game_data.player.p_x);
	printf("player y : %d\n", game_data.player.p_y);
	mlx_key_hook(game_data.render.win, ft_key_event, &game_data);
	mlx_loop(game_data.render.mlx);
	return (0);
}
