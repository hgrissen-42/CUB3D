#include "cub3d.h"

void    player_pos();
void canvas_init()
{
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
    g_player.iscrouch    = 0;
    g_player.crouch      = 0;
    g_player.turndir     = 0;
    g_player.vir_dir     = 0;
    g_player.hor_dir     = 0;
    g_player.rotang      = spawn_direction();
    g_player.movespeed   = 10;
    g_player.turnspeed   = 5;
    g_player.hlfpi     = 0;
}

void    player_pos()
{
    int i;
    int j;
    int check;

    i = 0;
    check = 0;
    while (i < g_prm.nwlcnt)
    {
        j = 0;
        while (j < g_prm.lnglin)
        {
            if (is_player(g_prm.map[i][j]))
            {
                check = 1;
                g_player.x = j * TILE_SIZE + (TILE_SIZE / 2);
                g_player.y = i * TILE_SIZE + (TILE_SIZE / 2);
                break;
            }
            j++;
        }
        if (check)
            break;
     i++;   
    }
}

