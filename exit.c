/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 19:03:55 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 20:40:43 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	ft_exit(t_game *game)
{
	mlx_destroy_image(game->render.mlx, game->img_0);
	mlx_destroy_image(game->render.mlx, game->img_1);
	mlx_destroy_image(game->render.mlx, game->img_c);
	mlx_destroy_image(game->render.mlx, game->img_e);
	mlx_destroy_image(game->render.mlx, game->img_e2);
	mlx_destroy_image(game->render.mlx, game->img_p);
	mlx_destroy_window(game->render.mlx, game->render.win);
	mlx_destroy_display(game->render.mlx);
	mlx_loop_end(game->render.mlx);
	free(game->render.mlx);
	ft_free_map_data(game->map_data);
	exit(0);
}

int	ft_exit_redcross(t_game *game)
{
	ft_exit(game);
	return (0);
}

int	ft_error(char *err_msg)
{
	printf("Error\n");
	printf("%s\n", err_msg);
	return (0);
}
