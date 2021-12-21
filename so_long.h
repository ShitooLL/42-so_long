/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:46:40 by laliao            #+#    #+#             */
/*   Updated: 2021/12/21 20:12:03 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# include "get_next_line.h"

# define WALL "./asset/bush.xpm"
# define GROUND "./asset/ground.xpm"
# define EXIT "./asset/exit.xpm"
# define COL "./asset/col.xpm"
/*
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
*/

typedef struct s_game
{
	int		map_height;
	int		map_length;
	int		tile;
	char	**map_data;
	void	*img_c;
	void	*img_e;
	void	*img_1;
	void	*img_0;
}	t_game;

typedef struct s_render
{
	void	*mlx;
	void	*window;
}	t_render;

/*
void	init_map(void *mlx, void *window, int fd);
int	display_wall(void *mlx, void *window, char *map_line, int y);
int	display_ground(void *mlx, void *window, char *map_line, int y);
void	*set_up_window(void *mlx, t_point *screen);
t_point	*check_map(char *argv, t_point *screen);
int	check_value(t_point *screen, char *line);
t_point	*ft_init_value(t_point *screen);
int	check_wall_x(char *line);
*/

void	ft_display_texture(t_render *render,t_game *game, int x, int y);
void	ft_load_texture(t_render *render, t_game *game);
void	ft_init_map_2(t_render *render, t_game *game);
int	set_up_window_2(t_render *render, t_game *game);
char	**ft_get_map(int argc, char **argv, t_game *game);
int	ft_check_map_value(t_game *game, int x, int y);
char	**ft_read_map(char *map_file, int *x, int *y);
int	ft_line_wall(t_game *game, int x, int y);
int	ft_side_wall(t_game *game, int x, int y);
int	ft_map_length(t_game *game, int x, int y);
int	ft_valid_char(t_game *game, int x, int y);
int	ft_check_map_char(t_game *game, int y);
void	ft_free_map_data(t_game *game);
int	ft_file_linecount(char *file);

int	ft_check_args(int argc, char **argv);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int	ft_strlen(const char *s);

void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_realloc(void **src, size_t size);

#endif

