/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sprite_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:36:38 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 19:09:15 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_sprite(void)
{
	int i;
	int j;
	int k;
	int w;
	int h;

	k = 0;
	i = -1;
	g_sp = malloc(sizeof(t_sprite) * (g_s_count + 1));
	if (!(g_si.img = mlx_xpm_file_to_image(g_mlx.mlx, g_prm.s, &w, &h)))
		texture_error(5);
	g_si.addr = mlx_get_data_addr(g_si.img, &g_si.bpp, &g_si.ll, &g_si.end);
	while (g_prm.map[++i] && (j = -1) && (k < g_s_count))
	{
		while (g_prm.map[i][++j] && (k < g_s_count))
			if (g_prm.map[i][j] == '2')
			{
				g_sp[k].x = (float)((j + 0.5) * TILE_SIZE);
				g_sp[k].y = (float)((i + 0.5) * TILE_SIZE);
				g_sp[k].dist = sqrtf(((g_sp[k].x) - g_p.x) * ((g_sp[k].x)
					- g_p.x) + ((g_sp[k].y) - g_p.y) * ((g_sp[k].y) - g_p.y));
				k++;
			}
	}
}

void	to_sort(void)
{
	int				i;
	int				j;
	t_sprite		tmp;

	i = 0;
	while (i < g_s_count - 1)
	{
		j = i;
		while (j < g_s_count - 1)
		{
			if (g_sp[j].dist < g_sp[j + 1].dist)
			{
				tmp = g_sp[j];
				g_sp[j] = g_sp[j + 1];
				g_sp[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	to_sprite(void)
{
	float	angle;
	int		k;

	k = -1;
	to_sort();
	angle = 0;
	while (++k < g_s_count)
	{
		g_sp[k].dist = sqrtf(((g_sp[k].x) - g_p.x) * ((g_sp[k].x)
					- g_p.x) + ((g_sp[k].y) - g_p.y) * ((g_sp[k].y) - g_p.y));
		angle = atan2f(g_sp[k].y - g_p.y, g_sp[k].x - g_p.x);
		while (angle - g_p.rotang > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_p.rotang < -M_PI)
			angle += 2 * M_PI;
		g_sp[k].size = (float)((g_prm.w / g_sp[k].dist) * TILE_SIZE);
		g_sp[k].yof = (float)(g_prm.h / 2 - g_sp[k].size / 2);
		g_sp[k].xof = (float)(((deg(angle) - deg(g_p.rotang)) * g_prm.w)
		/ TILE_SIZE + ((g_prm.w / 2) - (int)g_sp[k].size / 2));
		draw_sprite(k);
	}
}

void	draw_sprite(int id)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	g_sz = g_sp[id].size;
	g_spad = (int*)g_si.addr;
	while (++i < g_sz - 1 && (j = -1))
	{
		if (g_sp[id].xof + i <= 0 || g_sp[id].xof + i > g_prm.w - 1)
			continue ;
		if (g_rays[(int)(g_sp[id].xof + i)].dist <= g_sp[id].dist)
			continue ;
		while (++j < g_sz - 1)
		{
			if (g_sp[id].yof + j <= 0 || g_sp[id].yof + j > g_prm.h - 1)
				continue ;
			c = g_spad[(int)((TILE_SIZE) * (TILE_SIZE * j / (int)g_sz)
			+ (TILE_SIZE * i / (int)g_sz))];
			if (c != g_spad[0])
				my_mlx_pixel_put(&g_img, i + g_sp[id].xof, j + g_sp[id].yof
				- (g_p.iscrouch * CROUCH), c);
		}
	}
}
