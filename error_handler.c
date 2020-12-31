/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:26:20 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/31 18:48:35 by hgrissen         ###   ########.fr       */
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
	else
	{
		if (res_out() && !g_err.num_prm && !g_err.elm_inv)
		{
			printf("resolution 3andk mahiyash\n");
			printf("width must be between 100 and 2560\n");
			printf("height must be between 100 and 1440\n");
		}
		else if (rgb_out())
			printf("shi color 3andk out of range ");
	}
}

int		ch_err()
{
	if (g_err.dbl_inc || g_err.elm_inv ||
	g_err.num_prm || g_prm.inc > 8 || res_err() || rgb_err()
	|| pat_err() || res_out() || rgb_out())
		return (1);
	else
		return (0);
}


