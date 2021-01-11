/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 16:21:19 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/11 12:01:14 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int rgb_err()
{
       if(g_prm.fr == -1 || g_prm.fg == -1
       || g_prm.fb == -1 || g_prm.cr == -1
       || g_prm.cg == -1 || g_prm.cb == -1)
            return (1);
       else
            return (0);
}

int res_err()
{   
   if(g_prm.w == -1 || g_prm.h == -1)
        return (1);
    else
        return (0);
}

int pat_err()
{
    if (!g_prm.no || !g_prm.so || !g_prm.ea
    || !g_prm.we || !g_prm.s)
        return (1);
    else
        return(0);
}

int res_out()
{
    if (g_prm.w <= 100 || g_prm.h <= 100
    || g_prm.w > 2560 || g_prm.h >1440)
        return (1);
    else
        return (0);
}

int rgb_out()
{
    if (g_prm.fr < 0 || g_prm.fg < 0 || g_prm.fb < 0
	|| g_prm.cr < 0 || g_prm.cg < 0 || g_prm.cb < 0 ||
	g_prm.fr > 255 || g_prm.fg > 255 || g_prm.fb > 255
	|| g_prm.cr > 255 || g_prm.cg > 255 || g_prm.cb > 255)
        return (1);
    else
        return (0);
}