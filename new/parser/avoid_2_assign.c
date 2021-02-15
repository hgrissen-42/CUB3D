/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avoid_2_assign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:47:26 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/14 16:45:04 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		res_invalid(int i, char *line)
{
	int num;

	if (ft_isdigit(line[i]) && ft_isspace(line[1]))
	{
		num = ft_atoi(&line[i]);
		return (num);
	}
	else if (!ft_isspace(line[i]))
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

int		skip_digit(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

int		map_is_last(void)
{
	if (g_prm.cr && g_prm.cg && g_prm.cb && g_prm.fr
	&& g_prm.fg && g_prm.fb && g_prm.w > -1 && g_prm.h > 1
	&& g_prm.no && g_prm.so && g_prm.ea && g_prm.we && g_prm.s)
		return (1);
	else
		return (0);
}
