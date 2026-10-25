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

// #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c])
		c++;
	return (c);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_sz;
	size_t	s2_sz;
	char	*res;

	i = 0;
	s1_sz = ft_strlen(s1);
	s2_sz = ft_strlen(s2);
	res = malloc(s1_sz + s2_sz + 1);
	if (!res)
		return (NULL);
	while (i < s1_sz + s2_sz)
	{
		if (i < s1_sz)
			res[i] = s1[i];
		else
			res[i] = s2[i - s1_sz];
		i++;
	}
	res[i] = '\0';
	return (res);
}

ssize_t find_newl(char *buffer, ssize_t bytes)
{
    ssize_t i;

    i = 0;
    while (i < bytes)
    {
        if (buffer[i] == '\n')
            return (i + 1);
        i++;
    }
    return (-1);
}

char *get_next_line(int fd)
{
    int i = 0;
    int fd;
    char *buffer;
    static char *rest;
    char *line;
    ssize_t bytes = 1;
    ssize_t new_l;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return NULL;

    bytes = read(fd, buffer, BUFFER_SIZE);
    while(bytes > 0)
    {   
        buffer[bytes] = '\0';

        if (rest == NULL)
            ft_strjoin(rest, buffer);
        
        new_l = find_newl(rest, BUFFER_SIZE);
        if (new_l == -1)
        {
            rest = ft_strjoin(rest, buffer);
        }
        else
        {
            read(fd, buffer, BUFFER_SIZE);
            rest = ft_strjoin(rest, buffer);
        }
        bytes = read(fd, buffer, BUFFER_SIZE);

        printf("READ %s\n", buffer);
        printf("Bytes: %zd\n", bytes);
        printf("position: %d\n\n", new_l);
    }


    close(fd);
    free(buffer);
    return (line);
}
