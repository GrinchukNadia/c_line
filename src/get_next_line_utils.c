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