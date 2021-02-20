/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:31:30 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/16 14:52:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_res(char *line)
{
	int i;
	int num;

	i = 1;
	while (line[i])
	{
		i += white_space(&line[i]);
		if (!line[i])
			break ;
		num = res_invalid(i, line);
		if (num != 0)
			i += skip_digit(&line[i]) - 1;
		if (g_prm.w == -2)
			g_prm.w = num;
		else if (g_prm.h == -2)
			g_prm.h = num;
		else if (g_prm.w && g_prm.h)
			g_err.num_prm = 1;
		num = 0;
		i++;
	}
	g_prm.inc++;
}

void	get_rgb(char *line, int f)
{
	int num;
	int cnt;

	cnt = 0;
	g_i = 1;
	g_i += white_space(&line[g_i]);
	while (line[g_i])
	{
		if (ft_isdigit(line[g_i]) || (line[g_i] == ',' &&
		ft_isdigit(line[++g_i]) && cnt > 0))
		{
			line[g_i] == ',' ? g_i++ : 0;
			num = ft_atoi(&line[g_i]);
			g_i += skip_digit(&line[g_i]);
			cnt = prm_count(num, cnt, f);
		}
		else if (cnt == 3 && line[g_i] == ' ')
			g_i += white_space(&line[g_i]);
		else
		{
			g_err.elm_inv = 1;
			break ;
		}
	}
	cnt != 3 ? g_err.num_prm = 1 : 0;
}

int		prm_count(int num, int cnt, int f)
{
	if ((g_prm.fr == -1 || g_prm.cr == -1) && cnt == 0)
	{
		set_color(f, 'r', num);
		cnt++;
	}
	else if ((g_prm.fg == -1 || g_prm.cg == -1) && cnt == 1)
	{
		set_color(f, 'g', num);
		cnt++;
	}
	else if ((g_prm.fb == -1 || g_prm.cb == -1) && cnt == 2)
	{
		set_color(f, 'b', num);
		cnt++;
	}
	else
	{
		cnt++;
	}
	return (cnt);
}
