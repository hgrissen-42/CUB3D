/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:09:24 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 11:09:01 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int             key_pressed(int keycode)
{
    if (keycode == ESc_KEY)
        exit (0);
    if (keycode == A_KEY)
    {
        g_player.vir_dir = 1;
        g_player.hlfpi    = - M_PI / 2;
    }
    if (keycode == D_KEY)
    {
        g_player.vir_dir = 1;
        g_player.hlfpi    = M_PI / 2;
    }
    if (keycode == S_KEY)
        g_player.vir_dir = -1;
    if (keycode == W_KEY)
        g_player.vir_dir = 1;
    if (keycode == L_ARR)
        g_player.turndir = -1;
    if (keycode == R_ARR)
        g_player.turndir = 1;
    if (keycode == SPACE)
        g_player.iscrouch = 1;
    return 0;
}

int             key_released(int keycode)
{

    if (keycode == A_KEY)
    {
        g_player.vir_dir = 0;
        g_player.hlfpi    = 0;
    }
    if (keycode == D_KEY)
    {
        g_player.vir_dir = 0;
        g_player.hlfpi    = 0;
    }
    if (keycode == S_KEY)
        g_player.vir_dir = 0;
    if (keycode == W_KEY)
        g_player.vir_dir = 0;
    if (keycode == L_ARR)
        g_player.turndir = 0;
    if (keycode == R_ARR)
        g_player.turndir = 0;
    if (keycode == SPACE)
        g_player.iscrouch = 0;
    
    return 0;
}

int     render()
{
    //cast_all_rays();
    //draw_ray();
    cast_rays();
    render_flr_cei();
    walls3d();

    render_map();
    draw_player(g_player.x, g_player.y, 0x00FFFFFF);
    mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_img.img, 0, 0);
    mlx_destroy_image(g_mlx.mlx, g_img.img);
    g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.h);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
    &g_img.ll, &g_img.end);
    return 0;
}