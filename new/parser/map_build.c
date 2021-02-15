/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:01:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 18:42:57 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	nwl_cnt(void)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (g_prm.str[i])
	{
		if (g_prm.str[i] == '\n')
			cnt++;
		i++;
	}
	g_prm.nwlcnt = cnt;
}

void	lng_lin(void)
{
	int haha[g_prm.nwlcnt];

	g_i = 0;
	g_j = 0;
	g_tmp = 0;
	while (g_prm.str[g_i])
	{
		g_tmp++;
		if (g_prm.str[g_i] == '\n')
		{
			haha[g_j] = g_tmp - 1;
			g_tmp = 0;
			g_j++;
		}
		g_i++;
	}
	g_tmp = 0;
	g_j--;
	while (g_j >= 0)
	{
		if (g_tmp < haha[g_j])
			g_tmp = haha[g_j];
		g_j--;
	}
	g_prm.lnglin = g_tmp;
}

void	build_map(void)
{
	int i;

	i = 0;
	nwl_cnt();
	lng_lin();
	g_prm.map = malloc(sizeof(char *) * (g_prm.nwlcnt + 2 + 1));
	while (i <= g_prm.nwlcnt + 1)
	{
		g_prm.map[i] = malloc(sizeof(char) * (g_prm.lnglin + 2 + 1));
		i++;
	}
	spc_fil();
}

void	spc_fil(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= g_prm.nwlcnt + 1)
	{
		j = 0;
		while (j <= g_prm.lnglin + 1)
		{
			g_prm.map[i][j] = ' ';
			j++;
		}
		g_prm.map[i][j] = '\0';
		i++;
	}
	g_prm.map[i] = NULL;
	map_fil();
}

void	map_fil(void)
{
	int i;
	int j;
	int k;

	i = 1;
	j = 1;
	k = 0;
	while (i <= g_prm.nwlcnt)
	{
		j = 1;
		while (j <= g_prm.lnglin + 1)
		{
			if (g_prm.str[k] == '\n')
			{
				k++;
				break ;
			}
			g_prm.map[i][j++] = g_prm.str[k];
			k++;
		}
		i++;
	}
}
