/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:31:30 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/30 15:28:32 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_res(char* line)
{
	int i;
	int num;

	i = 1;
	while (line[i])
	{
		i += white_space(&line[i]);
		ft_isdigit(line[i]) ? (num = ft_atoi(&line[i])) : (g_err.elm_inv = 1);
		if (num != 0)
			i += ft_numlen(num, 0) - 1;
		if (g_prm.w == -1)
			g_prm.w = num;
		else if (g_prm.h == -1)
			g_prm.h = num;
		else if (g_prm.w && g_prm.h)
			g_err.num_prm = 1;
		num = 0;
		i++;
	}
	g_prm.inc++;
}

void	get_rgb(char* line, int f)
{
	int i;
	int num;
	int cnt;

	cnt = 0;
	i = 1;
	i += white_space(&line[i]);
	while(line[i])
	{
		if(ft_isdigit(line[i]) || (line[i] == ',' && ft_isdigit(line[++i]) && cnt > 0))
		{
			line[i] == ',' ? i++ : 0;
			num = ft_atoi(&line[i]);
			i += ft_numlen(num, 0);
			cnt = prm_count(num, cnt, f);
		}
		else
		{
			g_err.elm_inv = 1;
			break;
		}
	}
	cnt != 3 ? g_err.num_prm = 1 : 0;
}

int		prm_count(int num, int cnt, int f)
{
	if ((g_prm.fr == -1 || g_prm.cr == -1) && cnt == 0)
	{
		f == 'F' ? (g_prm.fr = num) : (g_prm.cr = num);
		cnt++;
	}
	else if ((g_prm.fg == -1 || g_prm.cg == -1) && cnt == 1)
	{
		f == 'F' ? (g_prm.fg = num) : (g_prm.cg = num);
		cnt++;
	}
	else if ((g_prm.fb == -1 || g_prm.cb == -1) && cnt == 2)
	{
		f == 'F' ? (g_prm.fb = num) : (g_prm.cb = num);
		cnt++;
	}
	else
	{
		cnt++;
	}
	return (cnt);
}
