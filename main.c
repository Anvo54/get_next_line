#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h> // remove


int main()
{
    int fd;
    char *test;
    int i = 0;

    fd = open("test2", O_RDONLY);
    // printf("fd: %i\n" ,fd);
    // get_next_line(fd, &test);
    // printf("%s\n", test);
    // get_next_line(fd, &test);
    // printf("%s\n", test);

    while (i < 9)
    {
        printf("%i",get_next_line(fd, &test));
        printf("%s\n", test);
        i++;
    }
    return(0);
}