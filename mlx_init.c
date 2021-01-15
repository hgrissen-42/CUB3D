#include "cub3d.h"


void mlx_initialisation()
{

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, g_prm.w, g_prm.h, "Hello world!");
    img.img = mlx_new_image(mlx, g_prm.w, g_prm.h);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    
}