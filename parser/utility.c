/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:39:28 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 17:50:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int white_space(char *line)
{
    int i;

    i = 0;
    while (ft_isspace(line[i]))
		    i++;
    return (i);
}

float   spawn_direction()
{
    if (g_p.spawn_dir == 'N')
        return (-M_PI / 2);
    else if (g_p.spawn_dir == 'W')
        return (M_PI);
    else if (g_p.spawn_dir == 'S')
        return (M_PI / 2);
    else if (g_p.spawn_dir == 'E')
        return (0);
    else
        exit(0);
}

void spc2wal()
{
    int i = 0;
    int j = 0;
    while(i <= g_prm.nwlcnt + 1)
    {
        j = 0;
        while(j <= g_prm.lnglin + 1)
        {
            if (g_prm.map[i][j] == ' ')
                g_prm.map[i][j] = '1';
            j++;
        }
        i++;
    }
}