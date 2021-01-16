/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:57:14 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/16 19:29:21 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int             closef(int keycode);
int             render();
int main()
{  
    prm_init();
    err_init();
    get_file();
    if (g_err.map_bgn)
    { 
        build_map();
        map_chk_opn();
    }
    //print_struct_elemts();
    Ch_fil_err();


    canvas_init();
    
    
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    
    //mlx_key_hook(g_mlx.mlx_win, closef, &g_mlx);
    mlx_loop_hook(g_mlx.mlx, update, &g_mlx);
    mlx_loop(g_mlx.mlx);

    return 0;
}
int     update()
{
    keys_loop();
    move();
    render();
    return (0);
}

void     keys_loop()
{
    mlx_hook(g_mlx.mlx_win,2,0,key_pressed, &g_mlx);
    mlx_hook(g_mlx.mlx_win,3,0,key_released, &g_mlx);
}

int     render()
{
    int playerclr   = 0x0068ee13;
    render_map();
    draw_player(g_player.x, g_player.y, playerclr);
    mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_img.img, 0, 0);
    return 0;
}
int             key_pressed(int keycode)
{
    if (keycode == 53)
        exit (0);
    if (keycode == 0)
        g_player.hor_dir = -1;
    if (keycode == 2)
        g_player.hor_dir = 1;
    if (keycode == 1)
        g_player.vir_dir = 1;
    if (keycode == 13)
        g_player.vir_dir = -1;
    if (keycode == 123)
        g_player.turndir = 1;
    if (keycode == 124)
        g_player.turndir = -1;
    
    return 0;
}
int             key_released(int keycode)
{

    if (keycode == 0)
        g_player.hor_dir = 0;
    if (keycode == 2)
        g_player.hor_dir = 0;
    if (keycode == 1)
        g_player.vir_dir = 0;
    if (keycode == 13)
        g_player.vir_dir = 0;
    if (keycode == 123)
        g_player.turndir = 0;
    if (keycode == 124)
        g_player.turndir = 0;
    
    return 0;
}

void    move()
{
    g_player.x          += g_player.hor_dir * g_player.movespeed;
    g_player.y          += g_player.vir_dir * g_player.movespeed;
    g_player.rotang     += g_player.turndir * g_player.turnspeed;
}