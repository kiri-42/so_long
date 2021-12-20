/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:07:23 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/21 00:54:40 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	int		fd;

	check_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_and_put_error("The file could not be opened.");
	read_map_file(fd);
	close(fd);
	return (0);
}
