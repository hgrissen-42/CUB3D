/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:39:28 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 17:35:29 by hgrissen         ###   ########.fr       */
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
    if (g_player.spawn_dir == 'N')
        return (-PI / 2);
    else if (g_player.spawn_dir == 'W')
        return (PI);
    else if (g_player.spawn_dir == 'S')
        return (PI / 2);
    else if (g_player.spawn_dir == 'E')
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