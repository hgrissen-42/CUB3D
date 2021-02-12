/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:58:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/12 11:18:47 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int		shdo_x(int color)
{
	int		r;
	int		g;
	int		b;
	int		dark;
	float	fact;

	fact = LGHT / g_col.perp_dist;
	if (fact > 1)
		return (color);
	r = (((color >> 16) & 0xFF)) * fact;
	g = (((color >> 8) & 0xFF)) * fact;
	b = ((color) & (0xFF)) * fact;
	dark = rgb_to_int(0, r, g, b);
	if (dark > color)
		dark = color;
	return (dark);
}

void	crouch(void)
{
	g_p.crouch = 10;
}

int		mini_map(void)
{
	return (MINI_MAP);
}
