/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:23:15 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 09:14:13 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float   deg2rad(float ang)
{
    return ang * (M_PI / 180);
}

float   normalize_ang(float ang)
{
    ang = fmod(ang, (2 * M_PI));
    if (ang < 0)
        ang += (2 * M_PI);
    return ang;
}

float   dis_pts(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

float	clamp_percent(float percent)
{
	percent = (percent < 0) ? 0 : percent;
	percent = (percent > 1) ? 1 : percent;
	return percent;
}
