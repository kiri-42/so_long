/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:35:33 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 18:03:01 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to free map_data */
void	free_map_data(t_data *game_data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)game_data->map_height)
	{
		free(game_data->map_data[i]);
		i++;
	}
	free(game_data->map_data);
	// (void)game_data;
	// system("leaks so_long");
}
