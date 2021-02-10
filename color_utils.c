/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:19:12 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 19:35:01 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	clamp_clr(float clr)
{
	clr = (clr < 0) ? 0 : clr;
	clr = (clr > 255) ? 255 : clr;
	return clr;
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}


int		rgb_to_int(int t, int r, int g, int b)
{
	//return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return (t << 24 | r << 16 | g << 8 | b);
}