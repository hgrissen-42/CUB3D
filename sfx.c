/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:15:10 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/19 14:33:19 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int     g_dmg_sfx_pid;

void    stop_damage_sfx()
{
   //kill(g_dmg_sfx_pid);
}

void    play_damage_sfx()
{
    char	*afplay[3];
	int		pid;

	afplay[0] = "/usr/bin/afplay";
	afplay[1] = "./Sound_Effects/damage_sfx.mp3";
	afplay[2] = 0;

    //stop_damage_sfx();
	int random = rand() % 2;
	if (random < 1)
		afplay[1] = "./Sound_Effects/minecraft_damage_sfx.mp3";
	else
		afplay[1] = "./Sound_Effects/roblox_damage_sfx.mp3";
	
	if (BON)
	{
		if ((pid = fork()) == 0)
		{
			execve(afplay[0], afplay, NULL);
		}
		else
			g_dmg_sfx_pid = pid;
	}
}