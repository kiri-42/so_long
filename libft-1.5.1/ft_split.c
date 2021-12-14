/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirihar <tkirihar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:06:44 by tkirihar          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:45 by tkirihar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_split_space_count(char const *s, char c)
{
	size_t			i;
	size_t			split_space;
	size_t			back;
	unsigned int	current;

	i = 0;
	split_space = 0;
	back = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			current = 1;
		else
			current = 0;
		if (back == 1 && current == 0)
			split_space++;
		back = current;
		i++;
	}
	return (split_space);
}

static char	*ft_split_space_set(char const *s, size_t start,
								size_t end, unsigned int current)
{
	size_t	i;
	char	*p;

	if (s[end + 1] == '\0' && current == 0)
		end++;
	p = (char *)malloc(sizeof(char) * ((end - start) + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	*ft_strset(char const *s, char c, size_t *split_index)
{
	size_t			start;
	size_t			end;
	size_t			back;
	unsigned int	current;

	start = 0;
	end = 0;
	back = 1;
	while (s[*split_index] != '\0')
	{
		current = 0;
		if (s[*split_index] == c)
			current = 1;
		if (back == 1 && current == 0)
			start = *split_index;
		if ((back == 0 && current == 1) || (s[*split_index + 1] == '\0'))
		{
			end = *split_index;
			break ;
		}
		back = current;
		*split_index += 1;
	}
	return (ft_split_space_set(s, start, end, current));
}

static void	*all_free(char **p, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(p[i++]);
	free(p);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**p;
	size_t		split_space;
	size_t		i;
	size_t		split_index;

	split_space = ft_split_space_count(s, c);
	p = (char **)malloc(sizeof(char *) * (split_space + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	split_index = 0;
	while (split_space > i)
	{
		p[i] = ft_strset(s, c, &split_index);
		if (p[i] == NULL)
		{
			all_free(p, i);
			return (NULL);
		}
		i++;
	}
	p[split_space] = NULL;
	return (p);
}
