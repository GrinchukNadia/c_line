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

static char	*handle_err(char **rest, char *buffer, char *line)
{
	free(*rest);
	*rest = NULL;
	free(buffer);
	free(line);
	return (NULL);
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

char	*get_next_line(int fd)
{
	static char		*rest;
	static size_t	capacity;
	static size_t	pos;
	char			*buffer;
	char			*line;
	char			*tmp;
	ssize_t			bytes;
	ssize_t			new_l;

	line = NULL;
	new_l = -1;
	bytes = 1;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (capacity == 0)
		capacity = BUFFER_SIZE;
	if (rest)
	{
		new_l = find_newl(rest);
		if (new_l != -1)
		{
			line = extract_ln(&rest, new_l, &pos);
			return (line);
		}
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (new_l == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (handle_err(&rest, buffer, line));
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		tmp = ft_join_n(rest, buffer, bytes, &capacity, &pos);
		if (!tmp)
			return (handle_err(&rest, buffer, line));
		rest = tmp;
		new_l = find_newl(rest);
	}
	if (new_l != -1 && bytes > 0)
	{
		new_l = find_newl(rest);
		line = extract_ln(&rest, new_l, &pos);
		if (line == NULL)
		{
			free(buffer);
			return (NULL);
		}
		free(buffer);
		return (line);
	}
	else if (new_l == -1 && bytes == 0)
	{
		free(buffer);
		if (!rest || !rest[0])
		{
			free(rest);
			rest = NULL;
			return (NULL);
		}
		line = rest;
		rest = NULL;
		return (line);
	}
	free(buffer);
	return (line);
}
