#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h> // remove


int main()
{
    int fd;
    char *test;
    int i = 0;

    fd = open("test2", O_RDONLY);

    while (i < 9)
    {
        printf("Result value is: %i\n",get_next_line(fd, &test));
        printf("text is: %s\n", test);
        if (test == NULL)
            printf("NULL\n");
        else
            printf("NOT NULL\n");
        i++;
    }

    test = NULL;

    while (i < 4)
    {
        printf("Result value is: %i\n",get_next_line(fd, &test));
        printf("text is: %s\n", test);
        if (test == NULL)
            printf("NULL\n");
        else
            printf("NOT NULL\n");
        i++;
    }

    return(0);
}