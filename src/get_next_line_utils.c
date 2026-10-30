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
	while (s[sz_s])
		sz_s++;
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

int	expand_rest(t_st_data *state, size_t bytes)
{
	char	*temp;

	if (state->rest == NULL)
		state->pos = 0;
	if (state->pos + bytes > state->capacity)
	{
		state->capacity *= 2;
		temp = state->rest;
		state->rest = malloc(state->capacity +1);
		if (!state->rest)
			return (0);
		state->rest = copy_line(temp, state->rest);
		free(temp);
	}
	return (1);
}

char	*ft_join_n(const char *buffer, size_t bytes, t_st_data *state)
{
	size_t	i;

	i = 0;
	if (!expand_rest(state, bytes))
		return (NULL);
	if (!state->rest)
	{
		state->rest = malloc(state->capacity + 1);
		if (!state->rest)
			return (NULL);
	}
	if (state->rest != NULL)
	{
		while (i < bytes)
		{
			state->rest[state->pos] = buffer[i];
			i++;
			(state->pos)++;
		}
	}
	state->rest[state->pos] = '\0';
	return (state->rest);
}
