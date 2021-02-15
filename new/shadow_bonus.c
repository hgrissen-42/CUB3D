/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:58:44 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/15 18:12:24 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	red_post()
{
	int i;
	int j;

	if (g_post)
	{
		i = 0;
		while (i < g_prm.h)
		{
			j = 0;
			while (j < g_prm.w)
			{
				my_mlx_pixel_put(&g_img, j, i, 0xA0FF0000);
				j++;
			}
			i++;
		}
	}
	g_post = 0;
}

void	health_bar(void)
{
	int i;
	int j;

	i = g_prm.h - (g_prm.h / 20) + 2;
	while (i < g_prm.h - (g_prm.h / 20) + (g_prm.h / 30) - 2)
	{
		j = (g_prm.w / 4) + 2;
		while (j < (g_prm.w / 4) + 2 + (g_healthmax - g_dmg))
		{
			my_mlx_pixel_put(&g_img, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	health_bg(void)
{
	int i;
	int j;

	i = g_prm.h - (g_prm.h / 20);
	while (i < (g_prm.h - (g_prm.h / 20)) + (g_prm.h / 30))
	{
		j = (g_prm.w / 4);
		while (j < g_prm.w - (g_prm.w / 4))
		{
			my_mlx_pixel_put(&g_img, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
