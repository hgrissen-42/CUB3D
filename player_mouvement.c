/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:11:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/09 09:25:08 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    move()
{
    // float	newx;
	// float	newy;
	// float	move_step;
    
    g_player.rotang     += g_player.turndir * deg2rad(g_player.turnspeed);
    g_player.x          += (g_player.vir_dir * g_player.movespeed) * cos(g_player.rotang + g_player.hlfpi);
    g_player.y          += (g_player.vir_dir * g_player.movespeed) * sin(g_player.rotang + g_player.hlfpi);

    // g_player.rotang += (g_player.turndir * g_player.turnspeed);
	// move_step = g_player.vir_dir * g_player.movespeed;
	// newx = cos(g_player.rotang + g_player.hlfpi) * (move_step);
	// newy = sin(g_player.rotang + g_player.hlfpi) * (move_step);
	// if ((!is_wall(g_player.x, newy)) && (!is_wall(g_player.x, newy)))
	//  	g_player.y = newy;
	// if ((!is_wall(newx, g_player.y)) && (!is_wall(newx, g_player.y)))
	//   	g_player.x = newx;
    
    //g_player.x += newx;
    //g_player.y += newy;
    
    collision();
}

void collision()
{
    int xpos;
    int ypos;
    float ts;
    float	move_step;
    
    move_step = g_player.vir_dir * g_player.movespeed;
    ts = TILE_SIZE;
    ypos = (int)(g_player.y + (ts / 2))/ ts;
    xpos = (int)(g_player.x + (ts / 2))/ ts;
    // if ((!is_wall(g_player.x, g_player.y + 10)) && (!is_wall(g_player.x, g_player.y - 10)))
	//   	g_player.y = newy;
	//  if ((!is_wall(newx + 10, g_player.y)) && (!is_wall(newx - 10, g_player.y)))
	//    	g_player.x = newx;
    // if (g_prm.map[ypos][xpos] == '1' || g_prm.map[ypos][xpos] == '2') 
    // {
    //     // g_player.x -= (g_player.vir_dir * g_player.movespeed)
    //     // * cos(g_player.rotang + g_player.hlfpi);
    //     // g_player.y -= (g_player.vir_dir * g_player.movespeed)
    //     // * sin(g_player.rotang + g_player.hlfpi);
    //     g_player.x -= cos(g_player.rotang + g_player.hlfpi) * (move_step);
    //     g_player.y -= sin(g_player.rotang + g_player.hlfpi) * (move_step);
    // }
}