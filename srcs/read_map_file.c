/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:23:36 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/08 00:09:53 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to count the number of lines in a map file */
static void	count_line(t_data *game_data, char *map_file)
{
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		finish_error("The file could not be opened");
	game_data->map_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		game_data->map_height++;
	}
	close(fd);
}

/* Function to initialize the map data based on the map file */
static void	init_map_data(t_data *game_data, char *map_file)
{
	char	*line;
	int		fd;
	size_t	i;

	game_data->map_data = (char **)malloc(sizeof(char *) * \
	game_data->map_height);
	if (game_data->map_data == NULL)
		finish_error("failed to allocate memory for map_data.");
	fd = open(map_file, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game_data->map_data[i] = line;
		i++;
	}
}

/* Function to remove newline characters at the end of a line */
static void	remove_newline(t_data *game_data)
{
	size_t	i;
	size_t	end_i;

	i = 0;
	while (i < (size_t)game_data->map_height)
	{
		end_i = ft_strlen(game_data->map_data[i]) - 1;
		if (game_data->map_data[i][end_i] == '\n')
			game_data->map_data[i][end_i] = '\0';
		i++;
	}
}

/* Function to read a map file */
void	read_map_file(t_data *game_data, char *map_file)
{
	count_line(game_data, map_file);
	init_map_data(game_data, map_file);
	remove_newline(game_data);
	game_data->map_width = ft_strlen(game_data->map_data[0]);
	check_map_data(game_data);
}
