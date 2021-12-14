/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 22:02:47 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/12 22:03:20 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	join_save_to_line(char **line, char **save)
{
	char	*newline;
	char	*temp;

	newline = ft_strchr(*save, '\n');
	if (newline != NULL)
	{
		free(*line);
		*line = ft_substr(*save, 0, newline - *save + 1);
		if (*line == NULL)
			return (-1);
		temp = *save;
		*save = ft_substr(newline + 1, 0, ft_strlen(newline) + 1);
		free(temp);
		if (*save == NULL)
			return (-1);
		return (1);
	}
	else
	{
		free(*line);
		*line = *save;
		*save = NULL;
		return (0);
	}
}

static char	*split_newline(char **line, char **save, char *buf)
{
	char	*current_line;
	char	*newline;
	char	*temp;

	newline = ft_strchr(buf, '\n');
	current_line = ft_substr(buf, 0, newline - buf + 1);
	if (current_line == NULL)
		return (free_and_return(buf));
	temp = ft_strjoin(*line, current_line);
	free(current_line);
	free(*line);
	if (temp == NULL)
		return (free_and_return(buf));
	*line = temp;
	temp = NULL;
	*save = ft_substr(newline + 1, 0, ft_strlen(newline) + 1);
	free(buf);
	if (save == NULL)
		return (NULL);
	else if (**save == '\0')
	{
		free(*save);
		*save = NULL;
	}
	return (*line);
}

static void	join_buf_to_line(char **line, char *buf)
{
	char	*temp;

	temp = ft_strjoin(*line, buf);
	if (temp == NULL)
		return ;
	free(*line);
	*line = temp;
	temp = NULL;
	return ;
}

static char	*read_file(int fd, char *line, char **save, int check_line)
{
	char		*buf;
	ssize_t		rc;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		rc = read(fd, buf, BUFFER_SIZE);
		if (rc <= 0)
			break ;
		buf[rc] = '\0';
		check_line = 0;
		if (ft_strchr(buf, '\n'))
			return (split_newline(&line, save, buf));
		join_buf_to_line(&line, buf);
	}
	free(buf);
	if (line[0] == '\0')
		line = free_and_return(line);
	if (rc == 0 && check_line == 0)
		return (line);
	return (free_and_return(line));
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			check_read;

	line = (char *)malloc(1);
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
		return (free_and_return(line));
	line[0] = '\0';
	check_read = 1;
	if (save != NULL)
	{
		check_read = join_save_to_line(&line, &save);
		if (check_read == 1)
			return (line);
		else if (check_read == -1)
			return (free_and_return(line));
	}
	return (read_file(fd, line, &save, check_read));
}
