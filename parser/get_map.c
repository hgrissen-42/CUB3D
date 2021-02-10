/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:21:32 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 17:50:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_map(char* line)
{
    int i;
    int gd;

    gd = 0;
    i = 0;
    while(line[i])
    {
        if(is_map(line[i]))
        {
            g_err.map_bgn = 1;
            if(is_player(line[i]) && (g_p.spawn_dir = line[i]))
                g_err.plr_cnt++;
            if (is_notspace(line[i]))
                gd = 1;
        }
        else
            g_err.map_inv = 1;
        i++;
    }
    if (gd == 0 && line[0])
        g_err.map_spc = 1;
    line[0] ? addline(line) : 0;
}

void addline(char *line)
{
    char *nwl;
    char *tmp;

    nwl = ft_strdup("\n");
    if (g_prm.str == NULL)
    {
        g_prm.str = ft_strdup(line);
    }
    else
    {
        tmp = g_prm.str; 
        g_prm.str = ft_strjoin(g_prm.str, line);
        free(tmp);
    }
    tmp = g_prm.str; 
    g_prm.str = ft_strjoin(g_prm.str, nwl);
    free(nwl);
    free(tmp);
}