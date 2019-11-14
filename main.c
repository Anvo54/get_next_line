#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h> // remove


int main()
{
    int fd;
    char *test;

    fd = open("test", O_RDONLY);
    get_next_line(fd, &test);
    printf("%s", test);
    get_next_line(fd, &test);
    printf("%s", test);
/*
    for (size_t i = 0; i < 3; i++)
    {
        get_next_line(fd, &test);
        printf("%s", test);
    }
*/    

    return(0);
}