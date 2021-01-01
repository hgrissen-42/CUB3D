/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 15:21:32 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/01 15:35:14 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void get_map(char* line)
{
    int i;
    i = 0;
    while(line[i])
    {
        if(is_map(line[i]))
        {
            g_err.map_bgn = 1;
            if(is_player(line[i]))
                g_err.plr_cnt++;
        }
        else
            g_err.map_inv = 1;
        i++;
    }
}