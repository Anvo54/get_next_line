#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h> // remove


int main()
{
    int fd;
    char *test;

    fd = open("test", O_RDONLY);
    printf("fd: %i\n" ,fd);
    get_next_line(fd, &test);
    printf("%s\n", test);
    get_next_line(fd, &test);
    printf("%s\n", test);
/*
    for (size_t i = 0; i < 3; i++)
    {
        get_next_line(fd, &test);
        printf("%s", test);
    }
*/    

    return(0);
}