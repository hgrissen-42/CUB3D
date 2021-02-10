/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:06:50 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 18:58:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     is_wall(float x, float y)
{
	int x1;
	int y1;

	if (x < 0 || x > (g_prm.lnglin * TILE_SIZE) ||
		y < 0 || y > (g_prm.nwlcnt * TILE_SIZE))
		return (1);
	x1 = floor(x / TILE_SIZE);
	y1 = floor(y / TILE_SIZE);
	if (g_prm.map[y1][x1] == '1')
		return (1);
	else
		return (0);
}

int     is_sprite(float x, float y)
{
	int x1;
	int y1;

	if (x < 0 || x > (g_prm.lnglin * TILE_SIZE) ||
		y < 0 || y > (g_prm.nwlcnt * TILE_SIZE))
		return (1);
	x1 = floor(x / TILE_SIZE);
	y1 = floor(y / TILE_SIZE);
	if (g_prm.map[y1][x1] == '2')
		return (1);
	else
		return (0);
}