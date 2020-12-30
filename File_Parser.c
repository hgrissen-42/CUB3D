/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_Parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:42 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/30 19:00:57 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main()
{   
    prm_init();
    err_init();
    get_file();
    //print_struct_elemts();
    print_errs();
    return 0;
}

void   get_file()
{
    int     fd;
    char*   line;

    fd = open("map.cub", O_RDONLY);
    while(get_next_line(fd, &line))
    {
        treat_file(line);
    }
    treat_file(line);
}

void    treat_file(char*    line)
{
    char c;

    c = line[0];
    if (c == 'R')
        get_res(line);
    else if (c == 'F' || c == 'C')
    {
        c == 'F' ? get_rgb(line, 'F') : get_rgb(line, 'C');
        g_prm.inc++;
    }
    else if (c == 'W'|| c == 'E' || c == 'N' || c == 'S')
    {
        if(c == 'S')
            line[1] == 'O' ? get_path(++line, 'O') : get_path(line, 'S');
        else
            get_path(++line, c);
    }
    else if (line[0] && g_prm.inc <= 8)
        printf("%s\n", line);
    else
        printf("shi 7aja wierd");
}