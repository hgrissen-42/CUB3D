/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:19:12 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/20 15:24:47 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	clamp_clr(float clr)
{
	clr = (clr < 0) ? 0 : clr;
	clr = (clr > 255) ? 255 : clr;
	return (clr);
}

int		get_r(int clr)
{
	return (clr & (0xFF << 16));
}

int		get_g(int clr)
{
	return (clr & (0xFF << 8));
}

int		get_b(int clr)
{
	return (clr & 0xFF);
}

int		rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
