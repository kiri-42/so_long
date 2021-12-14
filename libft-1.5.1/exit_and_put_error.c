/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_and_put_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:10:11 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/14 21:38:27 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	exit_and_put_error(char *error_message)
{
	ft_putstr_fd("\x1b[31mError: \x1b[39m", STDERR_FILENO);
	ft_putendl_fd(error_message, STDOUT_FILENO);
	exit(1);
}
