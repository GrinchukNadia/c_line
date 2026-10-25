// #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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

int main()
{
    int i = 0;
    int fd;
    char buffer[6];
    static char *rest;
    ssize_t bytes = 1;
    ssize_t new_l;

    fd = open("test.txt", O_RDONLY);
    if(fd == -1)
        return (1);


    bytes = read(fd, buffer, 5);
    while(bytes > 0)
    {
        if (bytes == -1)
            return (close(fd), 1);
        
        buffer[bytes] = '\0';

        new_l = find_newl(buffer, 5)
        if (new_l != -1)
        {
            while (buffer[new_l])
            {
                rest[i] = buffer[new_l];
                i++;
                new_l++;
            }
        }
        bytes = read(fd, buffer, 5);

        printf("READ %s\n", buffer);
        printf("Bytes: %zd\n", bytes);
        printf("position: %d\n\n", new_l);
    }


    close(fd);
    return (0);
}