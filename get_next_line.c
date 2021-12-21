/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 01:37:47 by laliao            #+#    #+#             */
/*   Updated: 2021/11/17 21:35:52 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*ft_read_lines(char *s_line, int fd)
{
	ssize_t		r;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	r = 1;
	while (!ft_strchr(s_line, '\n') && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[r] = '\0';
		s_line = ft_strjoin(s_line, buffer);
	}
	free(buffer);
	return (s_line);
}

char	*ft_get_read_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\n' && s[i])
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remove_read_line(char *s)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!tmp)
		return (NULL);
	j = 0;
	i++;
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*s_line = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s_line = ft_read_lines(s_line, fd);
	if (!s_line)
		return (NULL);
	line = ft_get_read_line(s_line);
	s_line = ft_remove_read_line(s_line);
	return (line);
}
