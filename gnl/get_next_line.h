/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 23:34:36 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:27:35 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "so_long.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_read_lines(char *s_line, int fd);
char	*ft_get_read_line(char *s);
char	*ft_remove_read_line(char *s);
char	*get_next_line(int fd);

#endif
