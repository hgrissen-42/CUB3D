/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:52:49 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/07 14:34:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		vert_ray(float angle)
{
	g_r.xstep = TILE_SIZE;
	g_r.xstep *= g_is_left ? -1 : 1;
	g_r.ystep = TILE_SIZE * tan(angle);
	g_r.ystep *= (g_is_up && g_r.ystep > 0) ? -1 : 1;
	g_r.ystep *= (g_is_down && g_r.ystep < 0) ? -1 : 1;
	g_r.nvx = g_r.x_intercept;
	g_r.nvy = g_r.y_intercept;
	while (g_r.nvx >= 0 && g_r.nvx <= g_prm.lnglin * 64 &&
			g_r.nvy >= 0 && g_r.nvy <= g_prm.nwlcnt * 64)
	{
		g_r.xcheck = g_r.nvx + (g_is_left ? -1 : 0);
		g_r.ycheck = g_r.nvy;
		if (is_wall(g_r.xcheck, g_r.ycheck))
		{
			g_r.vert_hitx = g_r.nvx;
			g_r.vert_hity = g_r.nvy;
			g_r.found_verthit = 1;
			break ;
		}
		else
		{
			g_r.nvx += g_r.xstep;
			g_r.nvy += g_r.ystep;
		}
	}
}

void		horz_ray(float angle)
{
	g_r.ystep = TILE_SIZE;
	g_r.ystep *= g_is_up ? -1 : 1;
	g_r.xstep = TILE_SIZE / tan(angle);
	g_r.xstep *= (g_is_left && g_r.xstep > 0) ? -1 : 1;
	g_r.xstep *= (g_is_right && g_r.xstep < 0) ? -1 : 1;
	g_r.nhx = g_r.x_intercept;
	g_r.nhy = g_r.y_intercept;
	while (g_r.nhx >= 0 && g_r.nhx <= g_prm.lnglin * 64 &&
		g_r.nhy >= 0 && g_r.nhy <= g_prm.nwlcnt * 64)
	{
		g_r.xcheck = g_r.nhx;
		g_r.ycheck = g_r.nhy + (g_is_up ? -1 : 0);
		if (is_wall(g_r.xcheck, g_r.ycheck))
		{
			g_r.horz_hitx = g_r.nhx;
			g_r.horz_hity = g_r.nhy;
			g_r.found_horzhit = 1;
			break ;
		}
		else
		{
			g_r.nhx += g_r.xstep;
			g_r.nhy += g_r.ystep;
		}
	}
}

void		push_ray(int strip_id)
{
	if (g_r.found_horzhit)
		g_r.hdist = dis_pts(g_player.x, g_player.y, g_r.horz_hitx, g_r.horz_hity);
	else
		g_r.hdist = FLT_MAX;
	if (g_r.found_verthit)
		g_r.vdist = dis_pts(g_player.x, g_player.y, g_r.vert_hitx, g_r.vert_hity);
	else
		g_r.vdist = FLT_MAX;
	if (g_r.vdist < g_r.hdist)
	{
		g_rays[strip_id].dist = g_r.vdist;
		g_rays[strip_id].hitx = g_r.vert_hitx;
		g_rays[strip_id].hity = g_r.vert_hity;
		g_rays[strip_id].hit_v = 1;
	}
	else
	{
		g_rays[strip_id].dist = g_r.hdist;
		g_rays[strip_id].hitx = g_r.horz_hitx;
		g_rays[strip_id].hity = g_r.horz_hity;
		g_rays[strip_id].hit_v = 0;
	}
}
void		cast_ray(int strip_id, float angle)
{
	angle = normalize_ang(angle);
	g_is_down = angle > 0 && angle < M_PI;
	g_is_up = !g_is_down;
	g_is_right = angle < (M_PI_2) || angle > (1.5 * M_PI);
	g_is_left = !g_is_right;
	g_r.found_horzhit = 0;
	g_r.horz_hitx = 0;
	g_r.horz_hity = 0;
	g_r.y_intercept = floor(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_r.y_intercept += g_is_down ? TILE_SIZE : 0;
	g_r.x_intercept = g_player.x + (g_r.y_intercept - g_player.y) / tan(angle);
	horz_ray(angle);
	g_r.found_verthit = 0;
	g_r.vert_hitx = 0;
	g_r.vert_hity = 0;
	g_r.x_intercept = floor(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_r.x_intercept += g_is_right ? TILE_SIZE : 0;
	g_r.y_intercept = g_player.y + (g_r.x_intercept - g_player.x) * tan(angle);
	vert_ray(angle);
	push_ray(strip_id);
	g_rays[strip_id].angle = angle;
	g_rays[strip_id].is_down = g_is_down;
	g_rays[strip_id].is_up = g_is_up;
	g_rays[strip_id].is_right = g_is_right;
	g_rays[strip_id].is_left = g_is_left;
}

void		cast_rays(void)
{
	float	ray_angle;
	int		strip_id;

	strip_id = 0;
	ray_angle = g_player.rotang - (FOV / 2);
	while (strip_id < g_prm.w)
	{
		cast_ray(strip_id, ray_angle);
		ray_angle += FOV / g_prm.w;
		strip_id++;
	}
}
