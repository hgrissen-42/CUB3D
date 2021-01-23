#include "cub3d.h"


void canvas_init()
{
    g_img.tile_size = 32;
    g_mlx.mlx = mlx_init();
    g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, g_prm.w, g_prm.h, "sma9looo");
    g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.w);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bits_per_pixel,
    &g_img.line_length, &g_img.endian);
    player_init();
    rayclr = 0;
}

void    player_init()
{
    g_player.x           = 0;
    g_player.y           = 0;
    g_player.radius      = 5;
    g_player.turndir     = 0;
    g_player.vir_dir     = 0;
    g_player.hor_dir     = 0;
    g_player.rotang      = spawn_direction();
    g_player.movespeed   = 5;
    g_player.turnspeed   = 5;
    g_player.hlfpi        = 0;
}

