/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:33 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 09:29:19 by hgrissen         ###   ########.fr       */
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

#define P_RADIUS 1
#define MINI_MAP 5
#define TILE_SIZE 32
#define FOV 60 * (M_PI / 180)
//#define M_PI 3.14159265359
# define FLT_MAX 3.402823e+38
# define CROUCH 200


#define A_KEY 0
#define D_KEY 2
#define S_KEY 1
#define W_KEY 13
#define ESc_KEY 53
#define L_ARR 123
#define R_ARR 124
#define U_ARR 126
#define D_ARR 125
#define SPACE 49

int				g_is_down;
int				g_is_up;
int				g_is_right;
int				g_is_left;

unsigned int				g_red;
unsigned int				g_green;
unsigned int				g_blue;

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
    int         bpp;
    int         ll;
    int         end;
}               t_img;
t_img  g_img;
t_img  g_so;
t_img  g_ea;
t_img  g_we;
t_img  g_no;
t_img  g_sp;

typedef struct  s_mlx {
    void    *mlx;
    void    *mlx_win;
}               t_mlx;
t_mlx g_mlx;

typedef struct  s_player {
    float   x;
    float   y;
    char    spawn_dir;
    float   hor_dir;
    float   vir_dir;
    float   turndir;
    double  rotang;
    float   movespeed;
    float   turnspeed;
    float   hlfpi;
	int		iscrouch;
	int		crouch;
}               t_player;
t_player g_player;

typedef struct	s_rays {
	float		angle;
	float		hitx;
	float		hity;
	float		dist;
	int			hit_v;
	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;
}				t_rays;

t_rays			g_rays[10000];


typedef struct	s_ray
{
	float	x_intercept;
	float	y_intercept;
	float	ystep;
	float	xstep;
	int		found_horzhit;
	int		found_verthit;
	float	horz_hitx;
	float	vert_hitx;
	float	vert_hity;
	float	horz_hity;
	float	nhx;
	float	nvx;
	float	nvy;
	float	nhy;
	float	xcheck;
	float	ycheck;
	float	hdist;
	float	vdist;
}				t_ray;
t_ray			g_r;

typedef struct	s_wall
{
	float	perp_dist;
	float	distproj;
	float	projwallh;
	int		strip_h;
	int		walltop;
	int		wallbot;
	int		xoff;
	int		yoff;
	int		dist;
}				t_wall;

t_wall			g_col;


void            get_file();

void            prm_init();
void            err_init(void);

void            treat_file(char*    line);
void            get_map(char* line);
void            routing(char* line);
void            get_res(char* line);
void            get_rgb(char* line ,int f);
int             prm_count(int num, int cnt, int f);
void            get_path(char* line, int c);
void            path_rout(char* s, int c);

int             is_map(int c);
int             is_player(int c);
int             is_srndbl(int c);
int             is_notspace(int c);
void            addline(char* line);
void            lng_lin();
void            nwl_cnt();
void            map_fil();
void            spc_fil();
void            build_map();
void            spc2wal();
float           spawn_direction();

void            print_errs();
int             ch_err();
int             rgb_err();
int             res_err();
int         pat_err();
int         res_out();
int         rgb_out();
void        Ch_fil_err();
void        map_err();
void        map_chk_opn();

int         white_space(char *line);

//render
void            render_flr_cei();
void		    walls3d(void);

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

int					shade(int i, int wall, char x);
unsigned int		shadow(unsigned int color, int col);
int					shadedcolor(int r, int g, int b, float percent);

void	    		texture_error(int error);
void				init_textures(void);
int					assign_textures(int i);
void				ray_norm(int i);

//color utility
float				clamp_clr(float clr);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);
int					rgb_to_int(int r, int g, int b);

//ray casting 
//void            cast_all_rays();
void		    cast_rays(void);
int             update();
void            keys_loop();
int             key_released(int keycode);
int             key_pressed(int keycode);


void            move();
void            collision();

int             is_corner(int x, int y);
int             is_wall(int x, int y);

//math utils
float			clamp_percent(float percent);
float           normalize_ang(float ang);
float           deg2rad(float ang);
float           dis_pts(float x1, float y1, float x2, float y2);
//debugging
void            print_struct_elemts();


#endif