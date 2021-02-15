/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:10:45 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/15 16:47:34 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	arrow_p_events(int keycode)
{
	if (keycode == L_ARR)
		g_p.turndir = -1;
	if (keycode == R_ARR)
		g_p.turndir = 1;
}

void	wasd_p_events(int keycode)
{
	if (keycode == A_KEY)
	{
		g_p.hlfpi = -M_PI_2;
		g_p.vir_dir = 1;
	}
	if (keycode == D_KEY)
	{
		g_p.hlfpi = M_PI_2;
		g_p.vir_dir = 1;
	}
	if (keycode == S_KEY)
		g_p.vir_dir = -1;
	if (keycode == W_KEY)
		g_p.vir_dir = 1;
}

void	arrow_r_events(int keycode)
{
	if (keycode == L_ARR)
		g_p.turndir = 0;
	if (keycode == R_ARR)
		g_p.turndir = 0;
}

void	wasd_r_events(int keycode)
{
	if (keycode == A_KEY)
	{
		g_p.hlfpi = 0;
		g_p.vir_dir = 0;
	}
	if (keycode == D_KEY)
	{
		g_p.hlfpi = 0;
		g_p.vir_dir = 0;
	}
	if (keycode == S_KEY)
		g_p.vir_dir = 0;
	if (keycode == W_KEY)
		g_p.vir_dir = 0;
}

void	bonus_events(int keycode, int pr)
{
	if (keycode == SPACE && BON == 1 && g_p.crouch < 100 + CROUCH && !pr)
		g_p.iscrouch = 0;
	if (keycode == SPACE && BON == 1 && g_p.crouch < 100 && pr)
		g_p.iscrouch = 1;
	if (keycode == D_ARR && g_p.crouch < 280 && BON && pr)
		g_p.crouch += 20;
	if (keycode == U_ARR && g_p.crouch > -280 && BON && pr)
		g_p.crouch -= 20;
	if (keycode == TAB && pr)
		g_p.ismap = 1;
	if (keycode == TAB && !pr)
		g_p.ismap = 0;
}
