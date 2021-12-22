/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:55:18 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/23 01:01:59 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* エラーメッセージを出力してプログラムを終了させる関数 */
void	finish_error(char *error_message)
{
	ft_putstr_fd("\x1b[31mError\n\x1b[39m", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
	exit(1);
}
