/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/18 19:24:20 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void dda();

void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
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
            else if(is_player(g_prm.map[i][j]))
            {
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, empty);
                if (!g_player.x || !g_player.y)
                {
                    g_player.x = j * g_img.tile_size;
                    g_player.y = i * g_img.tile_size;
                }
            }
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
    int xc = x + g_img.tile_size / 2;
    int yc = y + g_img.tile_size / 2;
    //int h = 10 * cos(deg2rad(g_player.rotang));
    //int v = 10 * sin(deg2rad(g_player.rotang));
    int r = g_player.radius;
    draw_ray();
    while(r >= 0)
    {
        circleBres(xc, yc, r, clr);
        r--;
    }

    //dda();
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
        while (i < 100000)
        {
            //float ang = deg2rad(g_player.rotang) + ((float)j * deg2rad(60.0f / g_prm.w));
            int h = i * cos(_start_angle);
            int v = i * sin(_start_angle);
            if ((xc + h) % (g_img.tile_size) == 0 || (xc + h + 1) % (g_img.tile_size) == 0 || (yc + v) % (g_img.tile_size) == 0 || (yc + v + 1) % (g_img.tile_size) == 0)
                if ((g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == '1') || (g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == ' ')) 
                    break;
            my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x0068ee13);
            i++;
        }
        j++;
    }
}

//DDA Function for line generation
void dda()
{
    int xc = g_player.x + g_img.tile_size / 2;
    int yc = g_player.y + g_img.tile_size / 2;
    int h = 10 * cos(deg2rad(g_player.rotang));
    int v = 10 * sin(deg2rad(g_player.rotang));
    // calculate dx & dy
    int dx = cos(g_player.rotang) - xc;
    int dy = sin(g_player.rotang) - yc;

    // calculate steps required for generating pixels
    int steps = fabs((float)dx) > fabs((float)dy) ? fabs((float)dx) : fabs((float)dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = xc;
    float Y = yc;
    for (int i = 0; i <= steps; i++)
    {
        if ((xc + h) % (g_img.tile_size) == 0 || (xc + h + 1) % (g_img.tile_size) == 0 || (yc + v) % (g_img.tile_size) == 0 || (yc + v + 1) % (g_img.tile_size) == 0)
                if ((g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == '1') || (g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == ' ')) 
                    break;
        my_mlx_pixel_put(&g_img, X, Y, 0x0068ee13);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        //delay(100);          // for visualization of line-
                             // generation step by step
    }
}
