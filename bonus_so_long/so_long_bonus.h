/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:46:40 by laliao            #+#    #+#             */
/*   Updated: 2021/12/27 22:59:53 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define WALL "../asset/wall.xpm"
# define GROUND "../asset/ground.xpm"
# define EXIT "../asset/exit.xpm"
# define EXIT2 "../asset/exit2.xpm"
# define COL "../asset/col.xpm"
# define P1 "../asset/sheep1.xpm"
# define P2 "../asset/sheep2.xpm"
# define P4 "../asset/sheep4.xpm"
# define END "../asset/end.xpm"
# define ENE "../asset/enemy.xpm"
# define EN2 "../asset/enemy2.xpm"
# define EN4 "../asset/enemy4.xpm"
# define EAT "../asset/eaten.xpm"

# define TILE 25
# define KEY_W 119 
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307
# define FRAME 15000
# define SPEED 35000

typedef struct s_render
{
	void		*mlx;
	void		*win;
}	t_render;

typedef struct s_p_pos
{
	int			p_x;
	int			p_y;
	int			p1;
	int			curr;
	void		*img_curr;
}	t_p_pos;

typedef struct s_enemy
{
	int			eaten;
	int			w;
	int			a;
	int			s;
	int			d;
	int			curr;
	int			counter;
	void		*img_curr;
}	t_enemy;

typedef struct s_game
{
	int			map_height;
	int			map_length;
	char		**map_data;
	void		*img_c;
	void		*img_e;
	void		*img_e2;
	void		*img_1;
	void		*img_0;
	void		*img_p;
	void		*img_p2;
	void		*img_p4;
	void		*img_end;
	void		*img_ene;
	void		*img_ene2;
	void		*img_ene4;
	void		*img_eat;
	int			exit;
	int			move;
	int			counter;
	int			speed;
	t_p_pos		player;
	t_enemy		enemy;
	t_render	render;
}	t_game;

void	ft_display_texture(t_game *game, int x, int y);
void	ft_load_texture(t_game **game);
void	ft_init_map(t_game *game);
int		set_up_window(t_game *game);
char	**ft_get_map(int argc, char **argv, t_game *game);
int		ft_check_map_value(char **map, int x, int y);
char	**ft_read_map(char *map_file, int *x, int *y);
int		ft_line_wall(char **map, int x, int y);
int		ft_side_wall(char **map, int x, int y);
int		ft_map_length(char **map, int x, int y);
int		ft_valid_char(char **map, int x, int y);
int		ft_check_map_char(char **map, int y);
void	ft_free_map_data(char **game_map);
int		ft_file_linecount(char *file);

int		ft_key_event(int keycode, t_game *game);
void	ft_move_player(int keycode, t_game *game);
int		ft_check_move(int keycode, t_game *game);
int		ft_check_col(t_game *game);
int		ft_exit_open(t_game *game);
void	ft_collectible(t_game *game);
void	ft_exit(t_game *game);
int		ft_exit_redcross(t_game *game);
int		ft_error(char *err_msg);
void	ft_display_move(t_game *game);

int		ft_loop_hook(t_game *game);

void	ft_move_enemy_w(t_game *game, int x, int y);
void	ft_move_enemy_s(t_game *game, int x, int y);
void	ft_move_enemy_a(t_game *game, int x, int y);
void	ft_move_enemy_d(t_game *game, int x, int y);
void	ft_enemy(t_game *game);
int		ft_eaten(t_game *game);

void	ft_ani_enemy_2(t_game *game);
void	ft_ani_enemy_1(t_game *game);

int		ft_check_args(int argc, char **argv);

#endif
