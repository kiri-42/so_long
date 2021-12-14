/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:07:01 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:07:02 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	get_head_trimlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
			i++;
		else
			break ;
	}
	return (i);
}

static size_t	get_end_trimlen(char const *s1, char const *set, size_t len)
{
	size_t	i;
	size_t	j;

	i = len - 1;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (s1[i] == set[j])
			i--;
		else
			break ;
	}
	return (len - 1 - i);
}

static char	*ft_strtrim_set(char *p, char const *s1, size_t len,
							size_t head_trimlen)
{
	size_t	i;

	i = 0;
	while (i < len)
		p[i++] = s1[head_trimlen++];
	p[i] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	len;
	size_t	head_trimlen;
	size_t	end_trimlen;

	len = ft_strlen(s1);
	head_trimlen = get_head_trimlen(s1, set);
	if (len == head_trimlen)
	{
		p = (char *)malloc(1);
		if (p == NULL)
			return (NULL);
		p[0] = '\0';
		return (p);
	}
	end_trimlen = get_end_trimlen(s1, set, len);
	len = len - head_trimlen - end_trimlen;
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	return (ft_strtrim_set(p, s1, len, head_trimlen));
}
