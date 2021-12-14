/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:20 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:21 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	nbrlen(int	n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*exception_handling(char *p, int *n, size_t *len)
{
	if (*n == -2147483648)
	{
		p[0] = '-';
		p[(*len)-- - 1] = '8';
		*n /= 10;
		*n *= -1;
	}
	else if (*n < 0)
	{
		p[0] = '-';
		*n *= -1;
	}
	else if (*n == 0)
	{
		p[0] = '0';
		p[1] = '\0';
		return (p);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*p;
	size_t	len;
	size_t	len2;
	size_t	tmp;

	len = nbrlen(n);
	len2 = len;
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	if (NULL != exception_handling(p, &n, &len))
		return (p);
	while (n != 0)
	{
		tmp = n % 10;
		p[len-- - 1] = '0' + tmp;
		n /= 10;
	}
	p[len2] = '\0';
	return (p);
}
