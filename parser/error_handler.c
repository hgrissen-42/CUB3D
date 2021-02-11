/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:26:20 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 18:08:22 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ch_fil_err(void)
{
	if (ch_err())
	{
		printf("Error\n");
		print_errs();
		printf("al batal !!!\n");
		exit(0);
	}
}

void	print_errs(void)
{
	if (g_err.elm_inv)
		printf("ash zayd fl file ");
	else if (res_err() || rgb_err() || pat_err())
		printf("parameter is missing");
	else if (g_err.num_prm)
		printf("wash maghadish t9ad number dlparameters ");
	else if (g_prm.inc > 8)
		printf("forbidden double inclusion");
	else if (g_err.map_inv || g_err.inv_nwl || g_err.map_spc
	|| g_err.plr_cnt > 1 || g_err.plr_cnt < 1 || !g_err.map_bgn
	|| g_err.map_open)
		map_err();
	else
	{
		if (res_out() && !g_err.num_prm && !g_err.elm_inv)
			printf("resolution 3andk mahiyash\n");
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
	if (!g_err.map_bgn)
		printf("map is missing\n");
	else if (g_err.map_inv)
		printf("lghalat a3shiri\n");
	else if (g_err.inv_nwl)
		printf("newline in the map\n");
	else if (g_err.plr_cnt > 1)
		printf("multiple players\n");
	else if (g_err.plr_cnt < 1)
		printf("lplayer is missing\n");
	else if (g_err.map_spc)
		printf("line only a space\n");
	else if (g_err.map_open)
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
