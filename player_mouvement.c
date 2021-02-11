/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:11:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 16:20:37 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(void)
{
	float	newx;
	float	newy;
	float	move_step;

	g_p.rotang += (g_p.turndir * g_p.turnspeed);
	move_step = g_p.vir_dir * g_p.movespeed;
	newx = g_p.x + cos(g_p.rotang + g_p.hlfpi) * (move_step);
	newy = g_p.y + sin(g_p.rotang + g_p.hlfpi) * (move_step);
	if ((!is_wall(g_p.x, newy + 20)) && (!is_wall(g_p.x, newy - 20))
		&& !is_sprite(g_p.x, newy))
		g_p.y = newy;
	if ((!is_wall(newx + 20, g_p.y)) && (!is_wall(newx - 20, g_p.y))
		&& !is_sprite(newx, g_p.y))
		g_p.x = newx;
}

void	collision(void)
{
}
