/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:57:14 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/21 18:32:52 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{  
    prm_init();
    err_init();
    get_file();
    if (g_err.map_bgn)
    { 
        build_map();
        map_chk_opn();
    }
    //print_struct_elemts();
    Ch_fil_err();


    canvas_init();
    
    mlx_loop_hook(g_mlx.mlx, update, &g_mlx);
    mlx_loop(g_mlx.mlx);

    return 0;
}




int     render()
{
    int playerclr   = 0x0068ee13;
    //draw_ver(100, 0, g_prm.h, playerclr);
    
    render_map();
    draw_player(g_player.x, g_player.y, playerclr);
    mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_img.img, 0, 0);
    return 0;
}


    
    
