/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:11:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/15 18:11:23 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	damage(int newx, int newy)
{
	if ((is_sprite(g_p.x, newy) || is_sprite(newx, g_p.y)) && g_damageable)
	{
		g_dmg += DMG;
		g_damageable = 0;
		if (g_dmg >= g_healthmax)
		{
			printf("GAME OVER!!!!!!");
			ft_quit();
			g_post = 1;
		}
	}
	else
		g_damageable = 1;
}

void	move(void)
{
	float	newx;
	float	newy;
	float	move_step;

	g_p.rotang += (g_p.turndir * g_p.turnspeed);
	move_step = g_p.vir_dir * g_p.movespeed;
	newx = g_p.x + cos(g_p.rotang + g_p.hlfpi) * (move_step);
	newy = g_p.y + sin(g_p.rotang + g_p.hlfpi) * (move_step);
	if (g_x && g_p.iscrouch)
	{
		g_p.crouch += CROUCH;
		g_x = 0;
	}
	if (!g_p.iscrouch && !g_x)
	{
		g_p.crouch -= CROUCH;
		g_x = 1;
	}
	collision(newx, newy);
	if (BON)
		damage(newx, newy);
}

void	collision(float newx, float newy)
{
	if ((!is_wall(g_p.x, newy + 10)) && (!is_wall(g_p.x, newy - 10))
		&& !is_sprite(g_p.x, newy))
		g_p.y = newy;
	if ((!is_wall(newx + 10, g_p.y)) && (!is_wall(newx - 10, g_p.y))
		&& !is_sprite(newx, g_p.y))
		g_p.x = newx;
}
