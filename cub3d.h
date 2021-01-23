/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:33 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/23 18:22:02 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "GNL/get_next_line.h"
#include "LIBFT/libft.h"


static int     rayclr;
float   g_rays_dis[10000];

#define PI 3.14159265359
#define A_KEY 0
#define D_KEY 2
#define S_KEY 1
#define W_KEY 13
#define ESc_KEY 53
#define L_ARR 123
#define R_ARR 124


typedef struct	s_prms {
    int         inc;
	int			w;
	int			h;
	int			fr;
	int			fg;
	int			fb;
    int			cr;
	int			cg;
	int			cb;
    char		*no;
    char		*so;
    char		*we;
    char		*ea;
    char		*s;
    char        *str;
    char        **map;
    int         nwlcnt;
    int         lnglin;

}				t_prm;
t_prm g_prm;

typedef struct	s_errs {
    int         num_prm;
    int         dbl_inc;
    int         elm_inv;
    int         plr_cnt;
    int         map_bgn;
    int         inv_nwl;
    int         map_inv;
    int         map_spc;
    int         map_open;
}				t_err;
t_err g_err;

typedef struct  s_img {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         tile_size;
}               t_img;
t_img  g_img;


typedef struct  s_mlx {
    void    *mlx;
    void    *mlx_win;
}               t_mlx;
t_mlx g_mlx;
typedef struct  s_player {
    float   x;
    float   y;
    char    spawn_dir;
    float   radius;
    float   hor_dir;
    float   vir_dir;
    float   turndir;
    double  rotang;
    float   movespeed;
    float   turnspeed;
    float   hlfpi;
}               t_player;
t_player g_player;




void        get_file();

void        prm_init();
void        err_init(void);

void        treat_file(char*    line);
void        get_map(char* line);
void        routing(char* line);
void        get_res(char* line);
void        get_rgb(char* line ,int f);
int         prm_count(int num, int cnt, int f);
void        get_path(char* line, int c);
void        path_rout(char* s, int c);

int         is_map(int c);
int         is_player(int c);
int         is_srndbl(int c);
int         is_notspace(int c);
void        addline(char* line);
void        lng_lin();
void        nwl_cnt();
void        map_fil();
void        spc_fil();
void        build_map();
void        spc2wal();
float       spawn_direction();

void        print_errs();
int         ch_err();
int         rgb_err();
int         res_err();
int         pat_err();
int         res_out();
int         rgb_out();
void        Ch_fil_err();
void        map_err();
void        map_chk_opn();

int         white_space(char *line);

//render
int             render();
void            canvas_init();
void            player_init();
void            render_player();
void            draw_player(int x, int y, int clr);
void            draw_ray();
void            render_map();
void            drawCircle(int xc, int yc, int x, int y, int clr);
void            circleBres(int xc, int yc, int r, int clr);
void            draw_rect(int x, int y, int clr);
void            draw_ver(int x, int start, int end, int clr);
void            my_mlx_pixel_put(t_img *data, int x, int y, int color);

int             update();
void            keys_loop();
int             key_released(int keycode);
int             key_pressed(int keycode);


void            move();
void            collision();

int     is_corner(int x, int y);


float   deg2rad(float ang);
//debugging
void print_struct_elemts();


#endif