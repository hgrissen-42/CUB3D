#include <mlx.h>
char map[6][6] = {
        {'1','1','1','1','1','\0'},
        {'1','0','0','0','1','\0'},
        {'1','1','1','0','1','\0'},
        {'1','0','1','0','1','\0'},
        {'1','0','N','0','1','\0'},
        {'1','1','1','1','1','\0'}
    };
void    *mlx;
void    *mlx_win;
typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;
t_data  img;

void            draw_player(int x, int y, int clr);
void            draw_map();
void            drawCircle(int xc, int yc, int x, int y, int clr);
void            circleBres(int xc, int yc, int r, int clr);
void            draw_rect(int x, int y, int clr);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);

int             main(void)
{
   

    

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    img.img = mlx_new_image(mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
    
    draw_map();
    //my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void draw_rect(int x, int y, int clr)
{
    int i;
    int j;

    i = x;
    while(i < x + 64)
    {
        j = y;
        while(j < y + 64)
        {
            my_mlx_pixel_put(&img, i, j, clr);
            j++;
        }
        i++;
    }
}
void draw_map()
{
    int i;
    int j;

    i = 0;
    while(i < 6)
    {
        j = 0;
        while(j < 5)
        {
            if(map[i][j] == '1')
            {
                draw_rect(j * 64, i * 64, 0x00DAF7A6);
            }
            else if(map[i][j] == '0')
            {
                draw_rect(j * 64, i * 64, 0x00900C3F);
            }
            else if(map[i][j] == 'N')
            {
                draw_rect(j * 64, i * 64, 0x00900C3F);
                draw_player(j * 64, i * 64, 0x00FFC300);
            }
            j++;
        }
        i++;
    }
}

void    draw_player(int x, int y, int clr)
{
    int xc = x + 32, yc = y + 32, r = 5;
    while(r >= 0)
    {
        circleBres(xc, yc, r, clr);
        r--;
    }
}

void drawCircle(int xc, int yc, int x, int y, int clr) 
{ 
    my_mlx_pixel_put(&img, xc+x, yc+y, clr); 
    my_mlx_pixel_put(&img, xc-x, yc+y, clr); 
    my_mlx_pixel_put(&img, xc+x, yc-y, clr); 
    my_mlx_pixel_put(&img, xc-x, yc-y, clr); 
    my_mlx_pixel_put(&img, xc+y, yc+x, clr); 
    my_mlx_pixel_put(&img, xc-y, yc+x, clr); 
    my_mlx_pixel_put(&img, xc+y, yc-x, clr); 
    my_mlx_pixel_put(&img, xc-y, yc-x, clr); 
}

void circleBres(int xc, int yc, int r, int clr) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, clr); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(xc, yc, x, y, clr); 
    } 
}

void draw_ray(int x, int y, int clr)
{

}