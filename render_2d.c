/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:05:07 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 18:05:12 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    if (y >= 0 && y < g_prm.h && x >= 0 && x < g_prm.w)
    {
        dst = data->addr + (y * data->ll + x * (data->bpp / 8));
        *(unsigned int*)dst = color;
    }
}
// void    draw_stripes();
// float   distance(float x, float x1, float y, float y1);
char    side_hit(float x, float y);
// int     is_wall(int x, int y);
//int     change_ray_clr(float x, float y);

void    render_map()
{
    int i;
    int j;
    int empty   = 0x00344966;
    int wall    = 0x00F59038;//B4CDED;
    int sprite  = 0x00FFFFFF;
    i = 1;
    while(i < g_prm.nwlcnt + 1)
    {
        j = 1;
        while(j < g_prm.lnglin + 1)
        {
            if(g_prm.map[i][j] == '2')
                draw_rect(j * TILE_SIZE / MINI_MAP, i * TILE_SIZE / MINI_MAP, sprite);
            else if (g_prm.map[i][j] == '1')
                 draw_rect(j * TILE_SIZE / MINI_MAP, i * TILE_SIZE /MINI_MAP, wall );
            else
                draw_rect(j * TILE_SIZE / MINI_MAP, i * TILE_SIZE / MINI_MAP, empty);
            j++;
        }
        i++;
    }
}

void    draw_player(int x, int y, int clr)
{
    int xc = x;
    int yc = y;
    ///////////afcwecwe/////
    int r = P_RADIUS;
    xc /= MINI_MAP;
    yc /= MINI_MAP;
    draw_ray();
    while(r >= 0)
    {
        circleBres(xc, yc, r, clr);
        r--;
    }
}


void    draw_ray()
{
    int j;
    int i;
    //int k;
    int xc = g_p.x;// + TILE_SIZE / 2;
    int yc = g_p.y;// + TILE_SIZE / 2;
    float inc;
    float start_angle;

    j = 0;
    inc = d2r(60.0f / g_prm.w);
    start_angle = g_p.rotang - d2r(30);
    while(j < g_prm.w)
    {
        i = 1;
        start_angle += inc;
        while (i < g_prm.w * g_prm.h)
        {
            int h = i * cos(start_angle);
            int v = i * sin(start_angle);
            //if (change_ray_clr(xc +h, yc +v))
            if (side_hit(xc + h, yc + v) || is_corner(xc + h, yc + v))
                break;
            //this is going to change
            my_mlx_pixel_put(&g_img, (xc + h) / MINI_MAP, (yc + v) / MINI_MAP, 0x00F0F400);//0x0068ee13
            i++;
        }
        //add_ray(j, start_angle);
        j++;
    }
    //draw_stripes();
}

// float   distance(float x, float x1, float y, float y1)
// {
//     return (sqrt(pow(x1 - x, 2) + pow(y1 - y, 2)));
// }

char    side_hit(float x, float y)
{
    if ((int)(x) % (TILE_SIZE) == 0 && is_wall(x, y))
        return ('W');
    else if ((int)(x + 1) % (TILE_SIZE) == 0 && is_wall(x, y))
        return ('E');
    else if ((int)(y) % (TILE_SIZE) == 0 && is_wall(x, y))
         return ('N');
    else if ((int)(y + 1) % (TILE_SIZE) == 0 && is_wall(x, y))
        return ('S');
    else
        return (0);
                 
}



// int     change_ray_clr(float x, float y)
// {
//     if (is_corner(x, y))
//     {
//         return 1;
//     }
    
//     if (side_hit(x, y) == 'N' && !is_corner(x, y))
//     {
//         return (1);   
//     }
//     else if (side_hit(x, y) == 'S' && !is_corner(x, y))
//     {
//         //rayclr = 0x0000FF00;
//         return (1);   
//     }
//     else if (side_hit(x, y) == 'E' && !is_corner(x, y))
//     {
//         //rayclr = 0x000000FF;
//         return (1);   
//     }
//     else if (side_hit(x, y) == 'W' && !is_corner(x, y))
//     {
//         //rayclr = 0x00FFFFFF;
//         return (1);
//     }
//     else
//         return (0);
    
// }
int     is_corner(int x, int y)
{
    if (!((x + 1) % TILE_SIZE) && !((y + 1) % TILE_SIZE)
    && (g_prm.map[(y - 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'
    && g_prm.map[(y + 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'))
        return (1);
    if (!((x) % TILE_SIZE) && !((y + 1) % TILE_SIZE)
    && (g_prm.map[(y - 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'
    && g_prm.map[(y + 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'))
        return (1);
    if (!((x) % TILE_SIZE) && !((y) % TILE_SIZE)
    && (g_prm.map[(y - 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'
    && g_prm.map[(y + 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'))
        return (1);
    if (!((x + 1) % TILE_SIZE) && !((y) % TILE_SIZE)
    && (g_prm.map[(y - 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'
    && g_prm.map[(y + 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'))
        return (1);
    return (0);
}

// void draw_stripes()
// {
//     int i;
//     int lineHeight;
    
//     i = 0;
//     while(i < g_prm.w)
//     {
//         lineHeight = (int)(g_prm.h / 10);///////g_rays_dis[i]);
        
//         int drawStart = -lineHeight / 2 + g_prm.h / 2;
//         if(drawStart < 0)
//             drawStart = 0;
        
//         int drawEnd = lineHeight / 2 + g_prm.h / 2;
//         if(drawEnd >= g_prm.h)
//             drawEnd = g_prm.h - 1;
        
//         draw_ver(i, drawStart, drawEnd, 0x00F59038);
//         i++;
//     }
// }
