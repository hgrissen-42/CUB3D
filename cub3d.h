/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:33 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/15 18:39:51 by hgrissen         ###   ########.fr       */
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

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    int         tile_size;
}               t_data;
t_data  g_img;


typedef struct  s_mlx {
    void    *mlx;
    void    *mlx_win;
}               t_mlx;
t_mlx g_mlx;
typedef struct  s_player {
    float x;
    float y;
    float radius;
    float turndir;
    float walkdir;
    float rotang;
    float movespeed;
    float turnspeed;
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
void            mlx_initialisation();
void            render_player();
void            draw_player(int x, int y, int clr);
void            render_map();
void            drawCircle(int xc, int yc, int x, int y, int clr);
void            circleBres(int xc, int yc, int r, int clr);
void            draw_rect(int x, int y, int clr);
void            my_mlx_pixel_put(t_data *data, int x, int y, int color);

//debugging
void print_struct_elemts();


#endif