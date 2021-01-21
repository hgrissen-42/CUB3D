/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:01:55 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 17:35:56 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void nwl_cnt()
{
    int i   = 0;
    int cnt = 0;
    while(g_prm.str[i])
    {
        if(g_prm.str[i] == '\n')
            cnt++;
        i++;
    }
    g_prm.nwlcnt = cnt;
}

void lng_lin()
{
    int i   = 0;
    int j = 0;
    int tmp = 0;
    int haha[g_prm.nwlcnt];

    while(g_prm.str[i])
    {
        tmp++;
        if(g_prm.str[i] == '\n')
        {
            haha[j] = tmp -1;
            tmp = 0;
            j++;
        }   
        i++;
    }
    tmp = 0;
    j--;
    while(j >= 0)
    {
        if (tmp < haha[j])
            tmp = haha[j];
        j--;
    }
    g_prm.lnglin = tmp;
}

void build_map()
{
    nwl_cnt();
    lng_lin();
    int  i = 0;
    g_prm.map = malloc(sizeof(char *) * (g_prm.nwlcnt + 2));
    while(i <= g_prm.nwlcnt + 1)
    {
        g_prm.map[i] = malloc(sizeof(char) * (g_prm.lnglin + 2));
        i++;
    }
    spc_fil();
}

void spc_fil()
{
    int i = 0;
    int j = 0;
    while(i <= g_prm.nwlcnt + 1)
    {
        j = 0;
        while(j <= g_prm.lnglin + 1)
        {
            g_prm.map[i][j] = ' ';
            j++;
        }
        g_prm.map[i][j] = '\0';
        i++;
    }
    map_fil();
}

void map_fil()
{
    int i = 1;
    int j = 1;
    int k = 0;
    while(i <= g_prm.nwlcnt)
    {
        j = 1;
        while(j <= g_prm.lnglin + 1)
        {
            if (g_prm.str[k] == '\n')
            { 
                k++;
                break;
            }
            g_prm.map[i][j++] = g_prm.str[k];
            k++;
        }
        i++;
    }
    spc2wal();
}