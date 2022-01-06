/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:55:12 by tkirihar          #+#    #+#             */
/*   Updated: 2022/01/06 14:55:40 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_object(t_data *game_data, size_t x, size_t y, void *object)
{
	mlx_put_image_to_window(game_data->mlx, game_data->win, \
	object, game_data->width * x, game_data->height * y);
}
