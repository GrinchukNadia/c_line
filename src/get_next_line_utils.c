/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:27:27 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/21 10:27:28 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	substr_len(size_t sz_s, unsigned int start, size_t len)
{
	size_t	sz_c;

	if (start >= sz_s)
		return (0);
	if (sz_s - start < len)
		sz_c = sz_s - start;
	else
		sz_c = len;
	return (sz_c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sz_s;
	size_t	sz_c;
	char	*res;

	i = 0;
	sz_s = 0;
	while (s[c])
		sz_c++;
	sz_c = substr_len(sz_s, start, len);
	res = malloc(sz_c + 1);
	if (!res)
		return (NULL);
	while (i < sz_c)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*copy_line(char *rest, char *new)
{
	int	i;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i])
	{
		new[i] = rest[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_join_n(char *rest, const char *buffer,
	size_t bytes, size_t *capacity, size_t *pos)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (rest == NULL)
		*pos = 0;
	while (*pos + bytes > *capacity)
		*capacity *= 2;
	temp = rest;
	rest = malloc(*capacity +1);
	if (!rest)
		return (NULL);
	rest = copy_line(temp, rest);
	free(temp);
	if (!rest)
	{
		rest = malloc(*capacity + 1);
		if (!rest)
			return (NULL);
	}
	if (rest != NULL)
	{
		while (i < bytes)
		{
			rest[*pos] = buffer[i];
			i++;
			(*pos)++;
		}
	}
	rest[*pos] = '\0';
	return (rest);
}

ssize_t	find_newl(char *buffer)
{
	ssize_t	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}
