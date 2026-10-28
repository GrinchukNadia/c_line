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

static size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

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
	sz_s = ft_strlen(s);
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


static	char *ft_join_n(char *rest, const char *buffer, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	y;
	char *res;

	i = 0;
	x = 0;
	y = 0;
	if (rest == NULL)
		x = 0;
	else
	{
		x = ft_strlen(rest);
	}

	while (i < size && buffer[i])
		i++;
	res = malloc(x + i + 1);
	if (!res)
		return (NULL);
	i = 0;
	if (rest != NULL)
	{
		while (rest[i])
		{
			res[i] = rest[i];
			i++;
		}
	}
	while (y < size && buffer[y])
	{
	 
		res[i] = buffer[y];
		y++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

ssize_t find_newl(char *buffer)
{
	ssize_t i;
	
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

char *handle_err(char **rest, char *buffer, char *line)
{
	free(rest);
	*rest = NULL;
	free(buffer);
	free(line);
	return (NULL);
}

static char *extract_ln(char **rest, ssize_t new_l)
{
	char *line;
	if (new_l != -1)
	{
		line = ft_substr(*rest, 0, new_l);
		if (!line)
		{
			free(rest);
			*rest = NULL;
			free(line);
			return (NULL);
		}
		tmp = ft_substr(rest, new_l, ft_strlen(rest) - new_l);
		if (!tmp)
		{
			free(line);
			free(*rest);
			*rest = NULL;
			return (NULL)
		}
		free(*rest);
		*rest = tmp;
		return (line);
	}
}

char *get_next_line(int fd)
{
	static char *rest;
	char		*buffer;
	char		*line;
	char		*tmp;
	ssize_t		bytes = 1;
	ssize_t		new_l;
	
	line = NULL;
	new_l = -1;
	// если размер буфера равен нулю или нет файл дескриптора
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	//  allocate memory for buffer
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;

	// extract a complete line from previously saved data, if available.
	if (rest)
	{ 
		new_l = find_newl(rest);
		return (extract_ln(&rest, new_l));
		// new_l = find_newl(rest);
		// if (new_l != -1)
		// {
		// 	line = ft_substr(rest, 0, new_l);
		// 	if (!line)
		// 		return (handle_err(&rest, buffer, line));
		// 	tmp = ft_substr(rest, new_l, ft_strlen(rest) - new_l);
		// 	if (!tmp)
		// 		return (handle_err(&rest, buffer, line));
		// 	free(rest);
		// 	rest = tmp;
		// 	free(buffer);
		// 	return (line);
		// }
	}

	// пока нет брейка читаю и записывать все в рест
	while (new_l == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (handle_err(&rest, buffer, line));
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';

		// записываю в рест весь буффер
		tmp = ft_join_n(rest, buffer, bytes);
		if (!tmp)
			return (handle_err(&rest, buffer, line));
		free(rest);
		rest = tmp;

		//смотрим есть ли брейк в rest
		new_l = find_newl(rest);
	}

	// как только нашли брейк и это не конец файла формируем строку и остаток реста
	if (new_l != -1 && bytes > 0)
	{
		new_l = find_newl(rest);
		return (extract_ln(&rest, new_l));
		// line = ft_substr(rest, 0, new_l);
		// if (!line)
		// 	line = ft_substr(rest, 0, new_l);
		// tmp = ft_substr(rest, new_l, ft_strlen(rest) - new_l);
		// if (!tmp)
		// 	line = ft_substr(rest, 0, new_l);
		// free(rest);
		// rest = tmp;
	}

	// если это конец файла и рест пустой то все освобождаем
	else if(new_l == -1 && bytes == 0)
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
