/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:36 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:37 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*char_dest;
	unsigned char		*char_src;
	size_t				i;

	char_dest = (unsigned char *)dest;
	char_src = (unsigned char *)src;
	i = 0;
	while (len-- > 0)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
