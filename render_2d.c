/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 17:33:07 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (y >= 0 && y < g_prm.h && x >= 0 && x < g_prm.w)
	{
		dst = data->addr + (y * data->ll + x * (data->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	render_map(void)
{
	int i;
	int j;
	int mini_w;
	int mini_h;

	mini_h = TILE_SIZE / MINI_MAP;
	mini_w = TILE_SIZE / MINI_MAP;
	i = 1;
	while (i < g_prm.nwlcnt + 1)
	{
		j = 1;
		while (j < g_prm.lnglin + 1)
		{
			if (g_prm.map[i][j] == '2')
				draw_rect(j * mini_w, i * mini_h, C_SPRITE);
			else if (g_prm.map[i][j] == '1')
				draw_rect(j * mini_w, i * mini_h, C_WALL);
			else
				draw_rect(j * mini_w, i * mini_h, C_EMPTY);
			j++;
		}
		i++;
	}
}

void	draw_player(int x, int y, int clr)
{
	int xc;
	int yc;
	int r;

	xc = x;
	yc = y;
	r = P_RADIUS;
	xc /= MINI_MAP;
	yc /= MINI_MAP;
	draw_ray();
	while (r >= 0)
	{
		circlebres(xc, yc, r, clr);
		r--;
	}
}

void	draw_ray(void)
{
	int j;
	int i;

	g_xc = g_p.x;
	g_yc = g_p.y;
	j = 0;
	g_inc = d2r(60.0f / g_prm.w);
	g_str_ang = g_p.rotang - d2r(30);
	while (j < g_prm.w)
	{
		i = 1;
		g_str_ang += g_inc;
		while (i < g_prm.w * g_prm.h)
		{
			g_h = i * cos(g_str_ang);
			g_v = i * sin(g_str_ang);
			if (side_hit(g_xc + g_h, g_yc + g_v) ||
			is_corner(g_xc + g_h, g_yc + g_v))
				break ;
			my_mlx_pixel_put(&g_img, (g_xc + g_h)
			/ MINI_MAP, (g_yc + g_v) / MINI_MAP, C_RAY);
			i++;
		}
		j++;
	}
}
