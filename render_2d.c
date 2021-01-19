/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/19 19:22:19 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     is_corner(int x, int y);
void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void draw_stripes();
void    draw_ver(int x, int start, int end, int clr);

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

void    render_map()
{
    int i;
    int j;
    int empty   = 0x00344966;
    int wall    = 0x00B4CDED;
    i = 0;
    while(i < g_prm.nwlcnt + 2)
    {
        j = 0;
        while(j < g_prm.lnglin + 1)
        {
            if(g_prm.map[i][j] == '1' || g_prm.map[i][j] == '2')
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, wall );
            else if(is_player(g_prm.map[i][j]))
            {
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, empty);
                if (!g_player.x || !g_player.y)
                {
                    g_player.x = j * g_img.tile_size;
                    g_player.y = i * g_img.tile_size;
                }
            }
            else if (g_prm.map[i][j] == '0')
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
    int playerclr   = 0x00BFCC94;
    int sprite      = 0x000D1821;
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
    int xc = x + g_img.tile_size / 2;
    int yc = y + g_img.tile_size / 2;
    //int h = 10 * cos(deg2rad(g_player.rotang));
    //int v = 10 * sin(deg2rad(g_player.rotang));
    int r = g_player.radius;
    //draw_ray();
    while(r >= 0)
    {
        circleBres(xc, yc, r, clr);
        r--;
    }
    draw_ray();
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

void    draw_ray()
{
    int i;
    int xc = g_player.x + g_img.tile_size / 2;
    int yc = g_player.y + g_img.tile_size / 2;
    //int h = 10 * cos(deg2rad(g_player.rotang));
    //int v = 10 * sin(deg2rad(g_player.rotang));
    int j = 0;
    float inc = deg2rad(60.0f / g_prm.w);
    //float f = 0.02;
    float _start_angle = g_player.rotang - deg2rad(30);
    //printf("%f\n", inc);
    while(j < g_prm.w)
    {
        i = 1;
        _start_angle += inc;
        while (i < g_prm.w * g_prm.h)
        {
            //float ang = deg2rad(g_player.rotang) + ((float)j * deg2rad(60.0f / g_prm.w));
            int h = i * cos(_start_angle);
            int v = i * sin(_start_angle);
            if ((xc + h) % (g_img.tile_size) == 0 || (xc + h + 1) % (g_img.tile_size) == 0 || (yc + v) % (g_img.tile_size) == 0 || (yc + v + 1) % (g_img.tile_size) == 0)
                if ((g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == '1') || (g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == ' ')) 
                    break;
            if (is_corner(xc + h, yc + v))
                break;
            //this is going to change
            my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x00F0F4EF);//0x0068ee13
            i++;
        }
        g_rays_dis[j] = ((i * cos(_start_angle)) - xc) + ((i * sin(_start_angle)) - yc);
        g_rays_dis[j] *= g_rays_dis[j];
        j++;
    }
}


int     is_corner(int x, int y)
{
    if (!((x + 1) % 32) && !((y + 1) % 32)
    && (g_prm.map[(y - 2) / 32][(x - 2) / 32] == '1'
    && g_prm.map[(y + 2) / 32][(x + 2) / 32] == '1'))
        return (1);
    if (!((x) % 32) && !((y + 1) % 32)
    && (g_prm.map[(y - 2) / 32][(x + 2) / 32] == '1'
    && g_prm.map[(y + 2) / 32][(x - 2) / 32] == '1'))
        return (1);
    if (!((x) % 32) && !((y) % 32)
    && (g_prm.map[(y - 2) / 32][(x + 2) / 32] == '1'
    && g_prm.map[(y + 2) / 32][(x - 2) / 32] == '1'))
        return (1);
    if (!((x + 1) % 32) && !((y) % 32)
    && (g_prm.map[(y - 2) / 32][(x - 2) / 32] == '1'
    && g_prm.map[(y + 2) / 32][(x + 2) / 32] == '1'))
        return (1);
    return (0);
}

void draw_stripes()
{
    int i;
    int lineHeight;
    
    i = 0;
    while(i < g_prm.w)
    {
        lineHeight = (int)(g_prm.h / g_rays_dis[i]);
        
        int drawStart = -lineHeight / 2 + g_prm.h / 2;
        if(drawStart < 0)
            drawStart = 0;
        
        int drawEnd = lineHeight / 2 + g_prm.h / 2;
        if(drawEnd >= g_prm.h)
            drawEnd = g_prm.h - 1;
        
        draw_ver(i, drawStart, drawEnd, 0);
        i++;
            //my_mlx_pixel_put(&g_img, i, j++, 0x00F0F4EF);//0x0068ee13
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