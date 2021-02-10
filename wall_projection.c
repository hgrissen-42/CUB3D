/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:08:43 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 17:50:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void		walls3d(void)
{
	int		i;
	int		y;

	i = 0;
	
	init_textures();
	while (i < g_prm.w)
	{
		ray_norm(i);
		y = g_col.walltop;
    
		while (y < g_col.wallbot)
		{
			g_col.dist = y + (g_col.strip_h / 2) - (g_prm.h / 2);
			g_col.dist += g_p.iscrouch ? CROUCH : 0;
			g_col.yoff = (int)(g_col.dist * ((float)TILE_SIZE / g_col.strip_h));
			my_mlx_pixel_put(&g_img, i, y, assign_textures(i));
			y++;
		}
		i++;
	}
}

void		ray_norm(int i)
{
	g_col.perp_dist = g_rays[i].dist * cos(g_rays[i].angle - g_p.rotang);
	g_col.distproj = (g_prm.w / 2) / tan(FOV / 2);
	g_col.projwallh = (TILE_SIZE / g_col.perp_dist) * g_col.distproj;
	g_col.strip_h = (int)g_col.projwallh;
	g_col.walltop = (g_prm.h / 2) - (g_col.strip_h / 2);
	g_col.walltop -= g_p.iscrouch ? CROUCH : 0;
	g_col.walltop = g_col.walltop < 0 ? 0 : g_col.walltop;
	g_col.wallbot = (g_prm.h / 2) + (g_col.strip_h / 2);
	g_col.wallbot -= g_p.iscrouch ? CROUCH : 0;
	g_col.wallbot = (g_col.wallbot > g_prm.h) ? g_prm.h : g_col.wallbot;
	if (g_rays[i].hit_v)
		g_col.xoff = (int)g_rays[i].hity % TILE_SIZE;
	else
		g_col.xoff = (int)g_rays[i].hitx % TILE_SIZE;
}

int			assign_textures(int i)
{
	int		*txtarr[4];
	int		dst;

	txtarr[0] = (int*)g_no.addr;
	txtarr[1] = (int*)g_so.addr;
	txtarr[2] = (int*)g_we.addr;
	txtarr[3] = (int*)g_ea.addr;
	if (g_rays[i].is_up && !g_rays[i].hit_v)
		dst = txtarr[1][TILE_SIZE * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_left && g_rays[i].hit_v)
		dst = txtarr[0][TILE_SIZE * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_down && !g_rays[i].hit_v)
		dst = txtarr[3][TILE_SIZE * g_col.yoff + g_col.xoff];
	if (g_rays[i].is_right && g_rays[i].hit_v)
		dst = txtarr[2][TILE_SIZE * g_col.yoff + g_col.xoff];
	return (shadow((unsigned int)dst, i));
}

void		init_textures(void)
{
	int		w;
	int		h;

	if (!(g_no.img))
		if (!(g_no.img = mlx_xpm_file_to_image(g_mlx.mlx, g_prm.no, &w, &h)))
			texture_error(1);
	if (!(g_no.addr))
		g_no.addr = mlx_get_data_addr(g_no.img, &g_no.bpp, &g_no.ll, &g_no.end);
	if (!(g_so.img))
		if (!(g_so.img = mlx_xpm_file_to_image(g_mlx.mlx, g_prm.so, &w, &h)))
			texture_error(2);
	if (!(g_so.addr))
		g_so.addr = mlx_get_data_addr(g_so.img, &g_so.bpp, &g_so.ll, &g_so.end);
	if (!(g_we.img))
		if (!(g_we.img = mlx_xpm_file_to_image(g_mlx.mlx, g_prm.we, &w, &h)))
			texture_error(3);
	if (!(g_we.addr))
		g_we.addr = mlx_get_data_addr(g_we.img, &g_we.bpp, &g_we.ll, &g_we.end);
	if (!(g_ea.img))
		if (!(g_ea.img = mlx_xpm_file_to_image(g_mlx.mlx, g_prm.ea, &w, &h)))
			texture_error(4);
	if (!(g_ea.addr))
		g_ea.addr = mlx_get_data_addr(g_ea.img, &g_ea.bpp, &g_ea.ll, &g_ea.end);
}

void	texture_error(int error)
{
	if (error == 1)
		printf("Error:\ninvalid north texture!\n");
	else if (error == 2)
		printf("Error:\ninvalid south texture!\n");
	else if (error == 3)
		printf("Error:\ninvalid west texture!\n");
	else if (error == 4)
		printf("Error:\ninvalid east texture!\n");
	else if (error == 5)
		printf("Error:\ninvalid sprite texture!\n");
	exit(0);
}