# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laliao <laliao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 19:13:44 by laliao            #+#    #+#              #
#    Updated: 2021/12/27 19:30:29 by laliao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long.a
INCLUDE			= include
SRC_DIR			= src/
SRC_BONUS_DIR	= src/bonus/
CC				= gcc
RM				= rm -f
AR				= ar rcs
FLAGS			= -Wall -Wextra -Werror

SRC_FILES		= check_map_value check_map check_parameter exit game_mech hook_mv \
				map_load player_move set_window main

SRC_BONUS_FILES	= 

SRC				= $(addprefix $(SRC_FILES), $(addsuffix .c, $(SRC_FILES)))
OBJ				= $(addsuffix .c, $(SRC_FILES))

all:			${NAME}

${NAME}:		${OBJ}
					${AR} ${NAME} ${OBJ}

${SRC_DIR}.c.o:
				${CC} -c ${FLAGS} -I ${INCLUDE} $< -o $@