#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    line = get_next_line(fd);
    printf("First [%s] \n", line ? line : "NULL");
    free(line);

    line = get_next_line(fd);
    printf("second [%s] \n", line ? line : "NULL");
    free(line);

    line = get_next_line(fd);
    printf("third [%s] \n", line ? line : "NULL");
    free(line);

    close(fd);
    return (0);
}
// while(line != NULL)
// {
//     printf("%s", line);
//     free(line);
//     line = get_next_line(fd);
// }