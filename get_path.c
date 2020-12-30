/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:40:51 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/30 15:48:31 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_path(char* line, int c)
{
    int     i;
    int     j;
    char    s[1000];

    i = 1;
    j = 0;
    i += white_space(&line[i]);
    while (line[i])
    {
        while (ft_isprint(line[i]) && !ft_isspace(line[i]))
        {
            s[j++] = line[i++];
            s[j] = '\0';
        }
        ft_isspace(line[i]) ? i += white_space(&line[i]) : 0;
        line[i] != '\0' ? g_err.elm_inv = 1 : 0; 
    }
    path_rout(s, c);
    g_prm.inc++;
}

void path_rout(char* s, int c)
{
    if (c == 'N')
        g_prm.no = ft_strdup(s);
    else if (c == 'O')
        g_prm.so = ft_strdup(s);
    else if (c == 'E')
        g_prm.ea = ft_strdup(s);
    else if (c == 'W')
        g_prm.we = ft_strdup(s);
    else if (c == 'S')
        g_prm.s = ft_strdup(s);
}