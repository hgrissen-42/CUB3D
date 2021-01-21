/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:11:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 17:42:53 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move()
{
    g_player.rotang     += g_player.turndir * deg2rad(g_player.turnspeed);
    g_player.x          += (g_player.vir_dir * g_player.movespeed) * cos(g_player.rotang + g_player.hlfpi);
    g_player.y          += (g_player.vir_dir * g_player.movespeed) * sin(g_player.rotang + g_player.hlfpi);
    collision();
}

void collision()
{
    int xpos;
    int ypos;
    float ts;

    ts = g_img.tile_size;
    ypos = (int)(g_player.y + (ts / 2))/ ts;
    xpos = (int)(g_player.x + (ts / 2))/ ts;
    if (g_prm.map[ypos][xpos] == '1' || g_prm.map[ypos][xpos] == '2') 
    {
        g_player.x -= (g_player.vir_dir * g_player.movespeed)
        * cos(g_player.rotang + g_player.hlfpi);
        g_player.y -= (g_player.vir_dir * g_player.movespeed)
        * sin(g_player.rotang + g_player.hlfpi);
    }
}