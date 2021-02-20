/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:09:24 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/20 15:41:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		update(void)
{
	mlx_hook(g_mlx.mlx_win, 2, 0, key_pressed, &g_mlx);
	mlx_hook(g_mlx.mlx_win, 3, 0, key_released, &g_mlx);
	mlx_hook(g_mlx.mlx_win, 17, 0, ft_quit, &g_mlx);
	move();
	render();
	return (0);
}

void	refresh(void)
{
	mlx_destroy_image(g_mlx.mlx, g_img.img);
	g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.h);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
	&g_img.ll, &g_img.end);
}

int		key_pressed(int keycode)
{
	if (keycode == ESC_KEY)
		ft_quit();
	wasd_p_events(keycode);
	arrow_p_events(keycode);
	bonus_events(keycode, 1);
	return (0);
}

int		key_released(int keycode)
{
	wasd_r_events(keycode);
	arrow_r_events(keycode);
	bonus_events(keycode, 0);
	return (0);
}

int		render(void)
{
	cast_rays();
	render_flr_cei();
	walls3d();
	sprites_conf();
	if (!g_save && BON == 1 && g_p.ismap)
	{
		render_map();
		draw_player(g_p.x, g_p.y, 0x00FF00FF);
	}
	if (BON)
	{
		red_post();
		health_bg();
		health_bar();
	}
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_img.img, 0, 0);
	if (g_save)
		screenshot();
	refresh();
	return (0);
}
