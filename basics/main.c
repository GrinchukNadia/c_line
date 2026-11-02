#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    line = get_next_line(fd);
    while(line != NULL)
    {
        printf("%s", line ? line : "NULL");
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
