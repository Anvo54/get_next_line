#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h> // remove


int main()
{
    int fd;
    char *test;
    int i = 0;

    fd = open("test2", O_RDONLY);


    test = NULL;

    printf("\n--------First test--------\n\n\n\n");
    while (i < 3)
    {
        printf("Result value is: %i\n",get_next_line(fd, &test));
        printf("text is: %s\n", test);
        if (test == NULL)
            printf("NULL\n");
        else
            printf("NOT NULL\n");
        i++;
    }
    printf("\n--------Second test--------\n--------Making list null---\n\n\n");

    test = NULL;
//    ft_strdel(&test);

    if (test == NULL)
        printf("NULL\n");
    else
        printf("NOT NULL\n");
    i = 0;
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

	char		*line;
	int			ret;
	char		*filename;

	filename = "test3.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		if (close(fd) == 0)
		{
			line = NULL;
			ret = get_next_line(fd, &line);
			if (ret != -1)
				printf("-> must have returned '-1' when receiving a closed file descriptor\n");
			else
				printf("OK\n");
		}
		else
		{
			printf("An error occured while closing file descriptor associated with file %s\n", filename);
			return (0);
		}
	}
	else
		printf("An error occured while opening file %s\n", filename);

    return(0);
}