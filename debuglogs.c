/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuglogs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:11:36 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/31 17:11:50 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_struct_elemts()
{
	printf("\nfloor r : %d g : %d b : %d\n" ,g_prm.fr ,g_prm.fg ,g_prm.fb);
    printf("\nceiling r : %d g : %d b : %d\n" ,g_prm.cr ,g_prm.cg ,g_prm.cb);
    printf("\nWidth : %d  Height : %d\n"  ,g_prm.w  ,g_prm.h);
    printf("\nNo %s\nSo %s\nEa %s\nWe %s\nSprite %s\n",g_prm.no ,g_prm.so ,g_prm.ea ,g_prm.we, g_prm.s);
	
}