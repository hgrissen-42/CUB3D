#include "cub3d.h"

void    player_pos();
void canvas_init()
{
    g_s_count = 0;
    g_mlx.mlx = mlx_init();
    g_mlx.mlx_win = mlx_new_window(g_mlx.mlx, g_prm.w, g_prm.h, "CUB3D");
    g_img.img = mlx_new_image(g_mlx.mlx, g_prm.w, g_prm.h);
    g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp,
    &g_img.ll, &g_img.end);
    player_init();
}

void    player_init()
{
    player_pos();
    g_p.iscrouch    = 0;
    g_p.crouch      = 0;
    g_p.turndir     = 0;
    g_p.vir_dir     = 0;
    g_p.hor_dir     = 0;
    g_p.rotang      = spawn_direction();
    g_p.movespeed   = 10;
    g_p.turnspeed   = 0.1;
    g_p.hlfpi     = 0;
}

void    player_pos()
{
    int i;
    int j;

    i = 0;
    while (i < g_prm.nwlcnt)
    {
        j = 0;
        while (j < g_prm.lnglin)
        {
            if (is_player(g_prm.map[i][j]))
            {
                g_p.x = j * TILE_SIZE + (TILE_SIZE / 2);
                g_p.y = i * TILE_SIZE + (TILE_SIZE / 2);
            }
            else if (g_prm.map[i][j] == '2')
                g_s_count++;
            j++;
        }
     i++;   
    }
}

