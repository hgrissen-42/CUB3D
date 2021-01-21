/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shapes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:46:46 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 17:57:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_rect(int x, int y, int clr)
{
    int i;
    int j;
    i = x;
    while(i < x + g_img.tile_size)
    {
        j = y;
        while(j < y + g_img.tile_size)
        {
            if (i % (x + g_img.tile_size) == 0 || (i + 1) % (x + g_img.tile_size) == 0 || j % (y + g_img.tile_size) == 0 || (j + 1) % (y + g_img.tile_size) == 0)
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

void    drawCircle(int xc, int yc, int x, int y, int clr)
{
    my_mlx_pixel_put(&g_img, xc+x, yc+y, clr);
    my_mlx_pixel_put(&g_img, xc-x, yc+y, clr);
    my_mlx_pixel_put(&g_img, xc+x, yc-y, clr);
    my_mlx_pixel_put(&g_img, xc-x, yc-y, clr);
    my_mlx_pixel_put(&g_img, xc+y, yc+x, clr);
    my_mlx_pixel_put(&g_img, xc-y, yc+x, clr);
    my_mlx_pixel_put(&g_img, xc+y, yc-x, clr);
    my_mlx_pixel_put(&g_img, xc-y, yc-x, clr);
}

void    circleBres(int xc, int yc, int r, int clr)
{
    int x;
    int y;
    int d;

    x = 0;
    y = r;
    d = 3 - 2 * r;
    drawCircle(xc, yc, x, y, clr);
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
        drawCircle(xc, yc, x, y, clr);
    }
}

void    draw_ver(int x, int start, int end, int clr)
{
    int i;

    clr = 0x00FFFFFF;
    i = start;
    while(i < end)
    {
        my_mlx_pixel_put(&g_img, x, i, clr);
        i++;
    }
}