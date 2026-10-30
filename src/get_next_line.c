/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:27:14 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/21 10:27:16 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*extract_ln(char **rest, ssize_t new_l, size_t *pos)
{
	char	*line;
	size_t	i;
	size_t	y;

	if (!rest || !*rest || new_l < 0)
		return (NULL);
	line = ft_substr(*rest, 0, new_l);
	if (!line)
		return (NULL);
	i = new_l;
	y = 0;
	while ((*rest)[i])
	{
		(*rest)[y] = (*rest)[i];
		y++;
		i++;
	}
	(*rest)[y] = '\0';
	*pos = y;
	return (line);
}

static ssize_t	read_line(int fd, t_st_data *state)
{
	char	*tmp;
	ssize_t	bytes;
	char	*buffer;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_join_n(buffer, bytes, state);
		if (!tmp)
			bytes = -1;
		if (bytes == -1)
			break ;
		state->rest = tmp;
		if (find_newl(state->rest) != -1)
			break ;
	}
	free(buffer);
	return (bytes);
}

static char	*get_line(t_st_data *state, ssize_t bytes, ssize_t new_l, char *l)
{
	if (state->rest)
		new_l = find_newl(state->rest);
	if (new_l != -1 && bytes > 0)
	{
		l = extract_ln(&state->rest, new_l, &state->pos);
		if (l == NULL)
		{
			return (NULL);
		}
		return (l);
	}
	else if (new_l == -1 && bytes == 0)
	{
		if (!state->rest || !state->rest[0])
		{
			free(state->rest);
			state->rest = NULL;
			return (NULL);
		}
		l = state->rest;
		state->rest = NULL;
	}
	free(state->rest);
	state->rest = NULL;
	return (l);
}

char	*get_next_line(int fd)
{
	static t_st_data	state;
	char				*line;
	ssize_t				bytes;
	ssize_t				new_l;

	line = NULL;
	new_l = -1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (state.capacity == 0)
		state.capacity = BUFFER_SIZE;
	if (state.rest)
		new_l = find_newl(state.rest);
	if (new_l != -1)
		return (extract_ln(&state.rest, new_l, &state.pos));
	bytes = read_line(fd, &state);
	if (bytes == -1)
	{
		free(state.rest);
		state.rest = NULL;
		free(line);
		return (NULL);
	}
	return (get_line(&state, bytes, new_l, line));
}
