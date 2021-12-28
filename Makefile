# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laliao <laliao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 19:13:44 by laliao            #+#    #+#              #
#    Updated: 2021/12/28 17:37:57 by laliao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
INCLUDE			= include
SRC_DIR			= src/
SRC_BONUS_DIR	= src/bonus/
CC				= gcc
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror

SRC				= check_map_value.c check_map.c check_parameter.c exit.c \
					game_mech.c hook_mv.c map_load.c player_move.c set_window.c \
					main.c


SRC_BONUS		= animation_bonus.c check_map_bonus.c check_map_value_bonus.c \
					check_parameter_bonus.c enemy_animation_bonus.c \
					enemy_bonus.c enemy_move_bonus.c exit_bonus.c \
					game_mech_bonus.c hook_mv_bonus.c main_bonus.c \
					map_load_bonus.c player_move_bonus.c set_window_bonus.c



OBJ				= $(addprefix ${SRC_DIR}, $(SRC:.c=.o))

OBJ_BONUS		= $(addprefix ${SRC_BONUS_DIR}, $(SRC_BONUS:.c=.o))


LD_FLAGS		= -L libft -L minilibx

MLX_FLAGS		= -lmlx_Linux -lXext -lX11

HEADER			= -I ${INCLUDE} -I libft -I minilibx

.c.o			:
					${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

${NAME}:		${OBJ}
					make -C libft
					make -C minilibx
					${CC} ${FLAGS} ${LD_FLAGS} ${OBJ} -o ${NAME} -lft ${MLX_FLAGS}

all:			${NAME}

bonus:			${OBJ_BONUS}
					make -C libft
					make -C minilibx
					${CC} -g3 ${FLAGS} ${LD_FLAGS} ${OBJ_BONUS} -o ${NAME} -lft ${MLX_FLAGS}

clean:
					make clean -C libft
					make clean -C minilibx
					${RM} ${OBJ} ${OBJ_BONUS}

fclean:			clean
					make fclean -C libft
					${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re bonus
