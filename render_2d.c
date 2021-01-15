/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/15 18:50:19 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

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
            my_mlx_pixel_put(&g_img, i, j, clr);
            j++;
        }
        i++;
    }
}

void    render_map()
{
    int i;
    int j;
    int wall        = 0x001ecbe1;
    int empty       = 0x00813329;
    i = 0;
    while(i < g_prm.nwlcnt + 2)
    {
        j = 0;
        while(j < g_prm.lnglin + 4)
        {
            if(g_prm.map[i][j] == '1' || g_prm.map[i][j] == ' ')
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, wall );
            else
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, empty);
            j++;
        }
        i++;
    }
}

void    render_player()
{
    int i;
    int j;
    int playerclr   = 0x0068ee13;
    int sprite      = 0x00ff7402;
    i = 0;
    while(i < g_prm.nwlcnt + 2)
    {
        j = 0;
        while(j < g_prm.lnglin + 4)
        {
            
            if(is_player(g_prm.map[i][j]))
            {
                draw_player(j * g_img.tile_size, i * g_img.tile_size, playerclr);
            }
            else if(g_prm.map[i][j] == '2')
            {
                draw_player(j * g_img.tile_size, i * g_img.tile_size, sprite);
            }
            j++;
        }
        i++;
    }
}

void    draw_player(int x, int y, int clr)
{
    int xc = x + g_img.tile_size / 2, yc = y + g_img.tile_size / 2, r = 5;
    while(r >= 0)
    {
        circleBres(xc, yc, r, clr);
        r--;
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
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, clr); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
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

void    draw_ray(int x, int y, int clr)
{
    clr = x + y;
    x = clr;
}