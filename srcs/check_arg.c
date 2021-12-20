/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:49:00 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/20 16:42:55 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* コマンドライン引数から受け取ったマップファイルが正しい拡張子か確認する関数 */
static void	check_extension(char *map_file)
{
	char	*extension;

	extension = ft_strrchr(map_file, '.');
	if (!extension || ft_strncmp(extension, ".ber", 4))
		exit_and_put_error("the map file could not be loaded.");
}

/* コマンドライン引数が正しい形式になっているか確認する関数 */
void	check_arg(int ac, char **av)
{
	if (ac != 2)
		exit_and_put_error("the number of arguments is different");
	check_extension(av[1]);
}
