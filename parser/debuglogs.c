/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuglogs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:11:36 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 17:53:46 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_struct_elemts(void)
{
	printf("\nfloor   rgb : %d,%d,%d\n", g_prm.fr, g_prm.fg, g_prm.fb);
	printf("\nceiling rgb : %d,%d,%d\n", g_prm.cr, g_prm.cg, g_prm.cb);
	printf("\nWid and Hei : %d %d\n", g_prm.w, g_prm.h);
	printf("\nNo %s\nSo %s\nEa %s\nWe %s\nSp %s\n", g_prm.no, g_prm.so,
	g_prm.ea, g_prm.we, g_prm.s);
	printmap();
}

void	printmap(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_prm.nwlcnt + 2)
	{
		j = 0;
		while (j < g_prm.lnglin + 2)
		{
			printf("%c", g_prm.map[i][j]);
			j++;
		}
		printf("%c", '\n');
		i++;
	}
}
