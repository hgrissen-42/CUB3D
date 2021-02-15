/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/15 16:31:59 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < g_prm.w && x >= 0 && y < g_prm.h && y >= 0)
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

	mini_h = (TILE_SIZE) / MINI_MAP;
	mini_w = (TILE_SIZE) / MINI_MAP;
	i = 0;
	while (i < g_prm.nwlcnt + 2)
	{
		j = 0;
		while (j < g_prm.lnglin + 2)
		{
			if (g_prm.map[i][j] == '2')
				draw_rect(j * mini_w, i * mini_h, C_SPRITE);
			else if (g_prm.map[i][j] == '1')
				draw_rect(j * mini_w, i * mini_h, C_WALL);
			else if (g_prm.map[i][j] == '0' || is_player(g_prm.map[i][j]))
				draw_rect(j * mini_w, i * mini_h, C_EMPTY);
			j++;
		}
		i++;
	}
}

void	draw_player(int x, int y, int clr)
{
	float	xc;
	float	yc;

	xc = ((x) / TILE_SIZE);
	yc = ((y) / TILE_SIZE);
	xc *= (TILE_SIZE) / MINI_MAP;
	yc *= (TILE_SIZE) / MINI_MAP;
	draw_rect(xc, yc, C_PLAYER);
	clr = 0;
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
