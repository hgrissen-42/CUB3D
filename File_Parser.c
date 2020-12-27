#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "GNL/get_next_line.h"
#include "LIBFT/libft.h"

char*   file;
char*   get_file();
int main()
{   
    char* f;
    f = get_file();
    //dup = ft_strdup(line);
    printf("%s\n", f);
    return 0;
}

char*   get_file()
{
    int     fd;
    char*   line;
    char*   tmp_line;
    //open tmp_line .cub
    fd = open("map.cub", O_RDONLY);
    while(get_next_line(fd, &line))
    {
        tmp_line = ft_strjoin(tmp_line, line);
        tmp_line = ft_strjoin(tmp_line, "\n");
       //printf("%s\n", line);
    }
    //printf("%s\n", line);
    tmp_line = ft_strjoin(tmp_line, line);
    tmp_line = ft_strjoin(tmp_line, "\n");
    return tmp_line;
    //file = ft_strdup(tmp_line);
}