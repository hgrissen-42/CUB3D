/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:06:50 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 16:44:40 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_wall(float x, float y)
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

int		is_sprite(float x, float y)
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

char	side_hit(float x, float y)
{
	if ((int)(x) % (TILE_SIZE) == 0 && is_wall(x, y))
		return ('W');
	else if ((int)(x + 1) % (TILE_SIZE) == 0 && is_wall(x, y))
		return ('E');
	else if ((int)(y) % (TILE_SIZE) == 0 && is_wall(x, y))
		return ('N');
	else if ((int)(y + 1) % (TILE_SIZE) == 0 && is_wall(x, y))
		return ('S');
	else
		return (0);
}

int		is_corner(int x, int y)
{
	if (!((x + 1) % TILE_SIZE) && !((y + 1) % TILE_SIZE)
	&& (g_prm.map[(y - 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'
	&& g_prm.map[(y + 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'))
		return (1);
	if (!((x) % TILE_SIZE) && !((y + 1) % TILE_SIZE)
	&& (g_prm.map[(y - 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'
	&& g_prm.map[(y + 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'))
		return (1);
	if (!((x) % TILE_SIZE) && !((y) % TILE_SIZE)
	&& (g_prm.map[(y - 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'
	&& g_prm.map[(y + 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'))
		return (1);
	if (!((x + 1) % TILE_SIZE) && !((y) % TILE_SIZE)
	&& (g_prm.map[(y - 2) / TILE_SIZE][(x - 2) / TILE_SIZE] == '1'
	&& g_prm.map[(y + 2) / TILE_SIZE][(x + 2) / TILE_SIZE] == '1'))
		return (1);
	return (0);
}
