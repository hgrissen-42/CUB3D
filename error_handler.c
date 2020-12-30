/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:26:20 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/30 18:47:30 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_errs(void)
{
	Check_prm();
	if (g_err.elm_inv)
		printf("ash zayd tm akhay\n");
	else if (g_err.num_prm && !g_err.elm_inv)
		printf("wash maghadish ze3ma t9ad l3ddad dyal lparameters\n");
	if (g_prm.inc > 8)
		printf("\nkayn 3andk akhay double inclusion fl file\n");
	
}
void	Check_prm()
{
	if(g_prm.w == -1 || g_prm.h == -1 || g_prm.fr == -1
	|| g_prm.fg == -1 || g_prm.fb == -1 || g_prm.cr == -1
	|| g_prm.cg == -1 || g_prm.cb == -1 || !g_prm.no 
	|| !g_prm.so || !g_prm.ea || !g_prm.we || !g_prm.s)
		printf("shi parameter na9ss 3and akhay");
	else if ((g_prm.w <= 100 || g_prm.h <= 100)
	&& !g_err.num_prm && !g_err.elm_inv)
		printf("khay resolution 3andk mahiyash\n");
	else if(g_prm.fr < 0 || g_prm.fg < 0 || g_prm.fb < 0
	|| g_prm.cr < 0 || g_prm.cg < 0 || g_prm.cb < 0 ||
	g_prm.fr > 255 || g_prm.fg > 255 || g_prm.fb > 255
	|| g_prm.cr > 255 || g_prm.cg > 255 || g_prm.cb > 255)
		printf("shi 7aja tem 3andk out of range");
}


void print_struct_elemts()
{
	printf("\nfloor r : %d g : %d b : %d\n" ,g_prm.fr ,g_prm.fg ,g_prm.fb);
    printf("\nceiling r : %d g : %d b : %d\n" ,g_prm.cr ,g_prm.cg ,g_prm.cb);
    printf("\nWidth : %d  Height : %d\n"  ,g_prm.w  ,g_prm.h);
    printf("\nNo %s\nSo %s\nEa %s\nWe %s\nSprite %s\n",g_prm.no ,g_prm.so ,g_prm.ea ,g_prm.we, g_prm.s);
	
}
