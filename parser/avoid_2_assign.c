/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avoid_2_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:47:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/12 12:19:21 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		res_invalid(int i, char *line)
{
	int num;

	if (ft_isdigit(line[i]))
	{
		num = ft_atoi(&line[i]);
		return (num);
	}
	g_err.elm_inv = 1;
	return (0);
}

void	set_color(char f, char rgb, int num)
{
	if (f == 'F')
	{
		if (rgb == 'r')
			g_prm.fr = num;
		else if (rgb == 'g')
			g_prm.fg = num;
		else if (rgb == 'b')
			g_prm.fb = num;
	}
	else
	{
		if (rgb == 'r')
			g_prm.cr = num;
		else if (rgb == 'g')
			g_prm.cg = num;
		else if (rgb == 'b')
			g_prm.cb = num;
	}
}
