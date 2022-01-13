/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:35:33 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:33:07 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to free map_data */
void	free_map_data(t_game_data *gdata)
{
	size_t	i;

	i = 0;
	while (i < (size_t)gdata->map_height)
	{
		free(gdata->map_data[i]);
		i++;
	}
	free(gdata->map_data);
}
