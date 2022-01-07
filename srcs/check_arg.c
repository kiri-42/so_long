/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:49:00 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/08 00:09:45 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to check if a map file has a .ber extension */
static void	is_ber_extension(char *map_file)
{
	char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4))
		finish_error("the map file could not be loaded");
}

/* Function to check if command line arguments are in the correct format */
void	check_arg(int ac, char **av)
{
	if (ac != 2)
		finish_error("the number of arguments is different");
	is_ber_extension(av[1]);
}
