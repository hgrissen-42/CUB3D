/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/23 19:05:49 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}
void    draw_stripes();
float   distance(float x, float x1, float y, float y1);
char    side_hit(float x, float y);
int     is_wall(int x, int y);
int     change_ray_clr(float x, float y);

void    render_map()
{
    int i;
    int j;
    int empty   = 0x00344966;
    int wall    = 0x00F59038;//B4CDED;
    i = 0;
    while(i < g_prm.nwlcnt + 2)
    {
        j = 0;
        while(j < g_prm.lnglin + 2)
        {
            if(is_player(g_prm.map[i][j]))
            {
                draw_rect(j * g_img.tile_size, i * g_img.tile_size, empty);
                if (!g_player.x || !g_player.y)
                {
                    g_player.x = j * g_img.tile_size;
                    g_player.y = i * g_img.tile_size;
                }
            }
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
    //draw_ray();
}



void    draw_ray()
{
    int j;
    int i;
    int k;
    int xc = g_player.x + g_img.tile_size / 2;
    int yc = g_player.y + g_img.tile_size / 2;
    float inc;
    float start_angle;

    j = 0;
    inc = deg2rad(60.0f / g_prm.w);
    start_angle = g_player.rotang - deg2rad(30);
    while(j < g_prm.w)
    {
        i = 1;
        start_angle += inc;
        while (i < g_prm.w * g_prm.h)
        {
            int h = i * cos(start_angle);
            int v = i * sin(start_angle);
            // if ((xc + h) % (g_img.tile_size) == 0 || (xc + h + 1) % (g_img.tile_size) == 0 || (yc + v) % (g_img.tile_size) == 0 || (yc + v + 1) % (g_img.tile_size) == 0)
            //     if (g_prm.map[(yc + v) / (g_img.tile_size)][(xc + h) / (g_img.tile_size)] == '1' 
            //     || is_corner(xc + h, yc + v))
            //     {
            //         if ((int)(xc + h) % (g_img.tile_size) == 0 && is_wall(xc + h, yc + v))
            //             my_mlx_pixel_put(&g_img, xc + h, yc + v, 0xff0000);//0x0068ee13
            //         else if ((int)(xc + h + 1) % (g_img.tile_size) == 0 && is_wall(xc+h, yc + v))
            //             my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x00ff00);//0x0068ee13
            //         else if ((int)(yc + v) % (g_img.tile_size) == 0 && is_wall(xc + h, yc + v))
            //             my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x0000ff);//0x0068ee13
            //         else if ((int)(yc + v + 1) % (g_img.tile_size) == 0 && is_wall(xc + h, yc  + v))
            //             my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x00FFFFFF);//0x0068ee13
            //         break;                    
            //     }
             if (change_ray_clr(xc +h, yc +v))
                     break;
            //this is going to change
            //my_mlx_pixel_put(&g_img, xc + h, yc + v, 0x00F0F400);//0x0068ee13
            i++;
        }
        k = 0;
        while(k < i)
        {
            int h = k * cos(start_angle);
            int v = k * sin(start_angle);
            my_mlx_pixel_put(&g_img, xc + h, yc + v, rayclr);
            k++;
        }
        g_rays_dis[j] = distance(xc, i * cos(start_angle), yc, i * sin(start_angle));
        j++;
    }
    //draw_stripes();
}

float   distance(float x, float x1, float y, float y1)
{
    return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
}

char    side_hit(float x, float y)
{
    if ((int)(x) % (g_img.tile_size) == 0 && is_wall(x, y) && !is_corner(x, y))
        return ('W');
    else if ((int)(x + 1) % (g_img.tile_size) == 0 && is_wall(x, y) && !is_corner(x, y))
        return ('E');
    else if ((int)(y) % (g_img.tile_size) == 0 && is_wall(x, y) && !is_corner(x, y))
         return ('N');
    else if ((int)(y + 1) % (g_img.tile_size) == 0 && is_wall(x, y) && !is_corner(x, y))
        return ('S');
    else
        return (0);
                 
}

int     is_wall(int x, int y)
{
    if (g_prm.map[(y) / (g_img.tile_size)][(x) / (g_img.tile_size)] == '1' || is_corner(x , y))
        return (1);
    else
        return (0);
    
}

int     change_ray_clr(float x, float y)
{
    if (is_corner(x, y))
    {
        return 1;
    }
    
    if (side_hit(x, y) == 'N' && !is_corner(x, y))
    {
        rayclr = 0x00FF0000;
        return (1);   
    }
    else if (side_hit(x, y) == 'S' && !is_corner(x, y))
    {
        rayclr = 0x0000FF00;
        return (1);   
    }
    else if (side_hit(x, y) == 'E' && !is_corner(x, y))
    {
        rayclr = 0x000000FF;
        return (1);   
    }
    else if (side_hit(x, y) == 'W' && !is_corner(x, y))
    {
        rayclr = 0x00FFFFFF;
        return (1);
    }
    else
        return (0);
    
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
        
        draw_ver(i, drawStart, drawEnd, 0x00F59038);
        i++;
    }
}

