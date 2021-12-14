/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:49 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:50 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(size_t len1, size_t len2, size_t size)
{
	if (size < len1)
		return (len2 + size);
	else
		return (len2 + len1);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = ft_strlen(dest);
	len1 = i;
	j = ft_strlen(src);
	len2 = j;
	j = 0;
	while (src[j] != '\0' && size > len1 + j + 1)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (check(len1, len2, size));
}
