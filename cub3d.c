/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:57:14 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/15 18:22:25 by hgrissen         ###   ########.fr       */
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


    mlx_initialisation();
    render_map();
    render_player();
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(g_mlx.mlx, g_mlx.mlx_win, g_img.img, 0, 0);
    mlx_loop(g_mlx.mlx);

    return 0;
}