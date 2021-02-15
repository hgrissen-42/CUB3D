/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:26:20 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/14 10:05:23 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ch_fil_err(void)
{
	if (ch_err())
	{
		printf("Error\n");
		print_errs();
		exit(0);
	}
}

void	print_errs(void)
{
	if (g_err.elm_inv)
		printf("womething is wrong in the file");
	else if (res_err() || rgb_err() || pat_err())
		printf("parameter is missing or map is not the last element");
	else if (g_err.num_prm)
		printf("wrong number of params");
	else if (g_prm.inc > 8)
		printf("forbidden double inclusion");
	else if (g_err.map_inv || g_err.inv_nwl || g_err.map_spc
	|| g_err.plr_cnt > 1 || g_err.plr_cnt < 1 || !g_err.map_bgn
	|| g_err.map_open)
		map_err();
	else
	{
		if (res_out() && !g_err.num_prm && !g_err.elm_inv)
			printf("resolution is wrong\n");
		else if (rgb_out())
			printf("color out of range");
	}
}

int		ch_err(void)
{
	if (g_err.dbl_inc || g_err.elm_inv ||
	g_err.num_prm || g_prm.inc > 8 || res_err() || rgb_err()
	|| pat_err() || res_out() || rgb_out() || g_err.map_inv
	|| g_err.inv_nwl || g_err.plr_cnt > 1 || g_err.plr_cnt < 1
	|| g_err.map_spc || !g_err.map_bgn || g_err.map_open)
		return (1);
	else
		return (0);
}

void	map_err(void)
{
	if (!g_err.map_bgn && g_prm.inc == 8)
		printf("map is missing or is not the last param\n");
	else if (g_err.map_inv && g_prm.inc == 8)
		printf("invalid map\n");
	else if (g_err.inv_nwl && g_prm.inc == 8)
		printf("newline in the map\n");
	else if (g_err.plr_cnt > 1 && g_prm.inc == 8)
		printf("multiple players\n");
	else if (g_err.plr_cnt < 1 && g_prm.inc == 8)
		printf("lplayer is missing\n");
	else if (g_err.map_spc && g_prm.inc == 8)
		printf("line only a space\n");
	else if (g_err.map_open && g_prm.inc == 8)
		printf("map is open\n");
}

void	map_chk_opn(void)
{
	int i;
	int j;

	i = 1;
	while (i <= g_prm.nwlcnt)
	{
		j = 1;
		while (j <= g_prm.lnglin)
		{
			if (is_srndbl((int)g_prm.map[i][j]))
			{
				if (g_err.map_open
				|| !is_notspace((int)g_prm.map[i][j - 1])
				|| !is_notspace((int)g_prm.map[i][j + 1])
				|| !is_notspace((int)g_prm.map[i - 1][j])
				|| !is_notspace((int)g_prm.map[i + 1][j]))
				{
					g_err.map_open = 1;
					break ;
				}
			}
			j++;
		}
		i++;
	}
}
