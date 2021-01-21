/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:09:24 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 17:38:26 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     update()
{
    keys_loop();
    move();
    render();
    mlx_destroy_image(g_mlx.mlx, g_img.img);
    g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.w);
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
        g_player.hlfpi    = - PI / 2;
    }
    if (keycode == D_KEY)
    {
        g_player.vir_dir = 1;
        g_player.hlfpi    = PI / 2;
    }
    if (keycode == S_KEY)
        g_player.vir_dir = -1;
    if (keycode == W_KEY)
        g_player.vir_dir = 1;
    if (keycode == L_ARR)
        g_player.turndir = -1;
    if (keycode == R_ARR)
        g_player.turndir = 1;
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
    return 0;
}