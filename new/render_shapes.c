/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:46:46 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/15 16:34:27 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rect(int x, int y, int clr)
{
	int i;
	int j;

	i = x;
	while (i < x + (TILE_SIZE / MINI_MAP))
	{
		j = y;
		while (j < y + (TILE_SIZE / MINI_MAP))
		{
			if (i % (x + TILE_SIZE / MINI_MAP) == 0 || (i + 1)
			% (x + TILE_SIZE / MINI_MAP) == 0
			|| j % (y + TILE_SIZE / MINI_MAP) == 0
			|| (j + 1) % (y + TILE_SIZE / MINI_MAP) == 0)
			{
				my_mlx_pixel_put(&g_img, i, j, 0x000000);
			}
			else
				my_mlx_pixel_put(&g_img, i, j, clr);
			j++;
		}
		i++;
	}
}

void	drawcircle(int xc, int yc, int x, int y)
{
	my_mlx_pixel_put(&g_img, xc + x, yc + y, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc - x, yc + y, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc + x, yc - y, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc - x, yc - y, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc + y, yc + x, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc - y, yc + x, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc + y, yc - x, C_SPRITE);
	my_mlx_pixel_put(&g_img, xc - y, yc - x, C_SPRITE);
}

void	circlebres(int xc, int yc, int r, int clr)
{
	int x;
	int y;
	int d;

	x = 0;
	y = r;
	clr = 0;
	d = 3 - 2 * r;
	drawcircle(xc, yc, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawcircle(xc, yc, x, y);
	}
}

void	draw_ver(int x, int start, int end, int clr)
{
	int i;

	i = start;
	while (i < end)
	{
		my_mlx_pixel_put(&g_img, x, i, clr);
		i++;
	}
}
