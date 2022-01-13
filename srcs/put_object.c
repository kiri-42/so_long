/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:55:12 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/09 14:34:36 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* Function to draw an object in a window */
void	put_object(t_game_data *gdata, size_t x, size_t y, void *object)
{
	mlx_put_image_to_window(gdata->mlx, gdata->win, \
	object, gdata->width * x, gdata->height * y);
}
