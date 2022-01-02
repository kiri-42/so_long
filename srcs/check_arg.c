/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:49:00 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/02 22:41:26 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* マップファイルが.ber拡張子か確認する関数 */
static void	is_ber_extension(char *map_file)
{
	char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4))
		finish_error("the map file could not be loaded.");
}

/* Function to check if command line arguments are in the correct format */
void	check_arg(int ac, char **av)
{
	if (ac != 2)
		finish_error("the number of arguments is different.");
	is_ber_extension(av[1]);
}
