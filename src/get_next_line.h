/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrinchu <ngrinchu@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 10:29:01 by ngrinchu          #+#    #+#             */
/*   Updated: 2026/10/21 10:29:04 by ngrinchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_st_data
{
	char	*rest;
	size_t	capacity;
	size_t	pos;
}			t_st_data;

char	*get_next_line(int fd);
ssize_t	find_newl(char *buffer);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_join_n(const char *buffer, size_t bytes, t_st_data *state);

#endif
