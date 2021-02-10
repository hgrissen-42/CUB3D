/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:36:01 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 10:48:59 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int		shadow(unsigned int color, int col)
{
	unsigned		r,g,b;
	float			fact;
	unsigned int	dark;
	col=0;

	fact = 25 / g_col.perp_dist;
	if (fact > 1)
		return(color);
	
	r = (((color >> 16) & 0xFF)) * fact;
	g = (((color >> 8) & 0xFF)) * fact;
	b= ((color) & (0xFF)) * fact;
	dark = rgb_to_int(r, g, b);
	if (dark > color)
	 	dark = color;
	return (dark);
}

int		shadedcolor(int r, int g, int b, float percent)
{
	r = clamp_clr(r - floorf(r * percent));
	g = clamp_clr(g - floorf(g * percent));
	b = clamp_clr(b - floorf(b * percent));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		shade(int i, int wall, char x)
{
	float percent;
	int crouch;
	
	crouch = g_player.iscrouch ? CROUCH : 0;
	if (wall != 0)
	{
		percent = ((g_col.perp_dist) / (g_prm.h / 2));
		percent = clamp_percent(percent);
		return (shadedcolor(g_red, g_green, g_blue, percent));
	}
	else
	{
		if (x == 'c')
		{
			percent = ((float)i + crouch) / (g_prm.h / 2);
			return (shadedcolor(g_prm.cr, g_prm.cg, g_prm.cb, percent));
		}
		else
		{
			percent = ((float)i + crouch) - (g_prm.h / 2);
			percent /= (g_prm.h - (g_prm.h / 2));
			percent = 1 - percent;
			return (shadedcolor(g_prm.fr, g_prm.fg, g_prm.fb, percent));
		}
	}
	
}

void    render_flr_cei()
{
	int i;
	int j;
	int fc;
	int cc;
	int crouch;
	
	crouch = g_player.iscrouch ? CROUCH * 2 : 0;
	i = -1;
	while (++i < g_prm.h)
	{
		fc = shade(i, 0, 'f');
		cc = shade(i, 0, 'c');
		j = -1;
		while (++j < g_prm.w)
		{
			if (i > (g_prm.h - crouch) / 2)
				my_mlx_pixel_put(&g_img, j, i, fc);
			else
			 	my_mlx_pixel_put(&g_img, j, i, cc);
		}
	}
}




