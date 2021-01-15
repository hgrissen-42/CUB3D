#include "cub3d.h"


void mlx_initialisation()
{
    g_img.tile_size = 32;//(int)roundf(g_prm.w / g_prm.lnglin);
    //g_prm.w = g_img.tile_size * g_prm.lnglin;
    //g_prm.h = g_img.tile_size * g_prm.nwlcnt;
    g_mlx.mlx = mlx_init();
    g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, g_prm.w, g_prm.h, "Hello world!");
    g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.h);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel, &g_img.line_length,
                                 &g_img.endian);
}