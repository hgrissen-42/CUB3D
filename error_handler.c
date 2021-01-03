/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:26:20 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/01 18:07:01 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	Ch_fil_err()
{
	if (ch_err())
	{
		printf("Error\n");
		print_errs();
		printf("al batal !!!\n");
		exit (0);
	}
}

void	print_errs()
{
	if (g_err.elm_inv)
		printf("ash zayd fl file ");
	else if (res_err() || rgb_err() || pat_err())
		printf("shi parameter na9ss 3andk ");
	else if (g_err.num_prm)
		printf("wash maghadish t9ad number dlparameters ");
	else if (g_prm.inc > 8)
		printf("kayn 3andk double inclusion fl file ");
	else if (g_err.map_inv || g_err.inv_nwl || g_err.map_spc
	|| g_err.plr_cnt > 1 || g_err.plr_cnt < 1)
		map_err();
	else
	{
		if (res_out() && !g_err.num_prm && !g_err.elm_inv)
			printf("resolution 3andk mahiyash\n");
		else if (rgb_out())
			printf("shi color 3andk out of range ");
	}
}

int		ch_err()
{
	if (g_err.dbl_inc || g_err.elm_inv ||
	g_err.num_prm || g_prm.inc > 8 || res_err() || rgb_err()
	|| pat_err() || res_out() || rgb_out() || g_err.map_inv
	|| g_err.inv_nwl || g_err.plr_cnt > 1 || g_err.plr_cnt < 1
	|| g_err.map_spc)
		return (1);
	else
		return (0);
}

void	map_err()
{
	if (g_err.map_inv)
        printf("lghalat a3shiri\n");
    else if(g_err.inv_nwl)
        printf("new line a3shiri\n");
    else if(g_err.plr_cnt > 1)
        printf("3Andk shela players\n");
    else if(g_err.plr_cnt < 1)
        printf("lplayer fkaghk?! \n");
	else if (g_err.map_spc)
		printf("ster koulu ghir space,WTF?! \n");
}

