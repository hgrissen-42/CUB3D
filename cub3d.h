/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:33 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/20 15:41:58 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "GNL/get_next_line.h"
# include "basic/libft.h"
# include <signal.h>

# define FLT_MAX 3.402823e+38

# define P_RADIUS 1
# define MINI_MAP 10
# define TILE_SIZE 64
# define FOV 1.0472
# define COL_DIS 10

# define DMG 20
# define CROUCH 200
# define LGHT 50
# define PLAYER_MOVE_SPEED 20
# define PLAYER_TURN_SPEED 0.1

# define C_EMPTY  0x001A3A41
# define C_WALL 0x00B1C288
# define C_SPRITE 0x00FBF6A5
# define C_PLAYER 0x00CC3C2C
# define C_RAY 0x00FFFFFF

# define A_KEY 0
# define D_KEY 2
# define S_KEY 1
# define W_KEY 13
# define ESC_KEY 53
# define L_ARR 123
# define R_ARR 124
# define U_ARR 126
# define D_ARR 125
# define SPACE 49
# define TAB 48

int				g_hmini;
int				g_wmini;

int				g_post;
int				g_healthmax;
int				g_dmg;
int				g_damageable;

int				g_x;

int				g_is_down;
int				g_is_up;
int				g_is_right;
int				g_is_left;

unsigned int	g_red;
unsigned int	g_green;
unsigned int	g_blue;

int				*g_spad;
float			g_sz;

int				g_h;
int				g_v;
float			g_inc;
float			g_str_ang;
int				g_xc;
int				g_yc;

int				g_i;
int				g_j;
int				g_tmp;

int				g_pid;

typedef struct	s_prms {
	int			inc;
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
	char		*str;
	char		**map;
	int			nwlcnt;
	int			lnglin;

}				t_prm;
t_prm			g_prm;

typedef struct	s_errs {
	int			num_prm;
	int			dbl_inc;
	int			elm_inv;
	int			plr_cnt;
	int			map_bgn;
	int			inv_nwl;
	int			map_inv;
	int			map_spc;
	int			map_open;
}				t_err;
t_err			g_err;

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			end;
}				t_img;
t_img			g_img;
t_img			g_so;
t_img			g_ea;
t_img			g_we;
t_img			g_no;
t_img			g_si;

typedef struct	s_mlx {
	void		*mlx;
	void		*mlx_win;
}				t_mlx;
t_mlx			g_mlx;

typedef struct	s_player {
	float		x;
	float		y;
	char		spawn_dir;
	float		hor_dir;
	float		vir_dir;
	float		turndir;
	double		rotang;
	float		movespeed;
	float		turnspeed;
	float		hlfpi;
	int			iscrouch;
	int			crouch;
	int			ismap;
}				t_player;
t_player		g_p;

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
	float		x_intercept;
	float		y_intercept;
	float		ystep;
	float		xstep;
	int			found_horzhit;
	int			found_verthit;
	float		horz_hitx;
	float		vert_hitx;
	float		vert_hity;
	float		horz_hity;
	float		nhx;
	float		nvx;
	float		nvy;
	float		nhy;
	float		xcheck;
	float		ycheck;
	float		hdist;
	float		vdist;
}				t_ray;
t_ray			g_r;

typedef struct	s_wall
{
	float		perp_dist;
	float		distproj;
	float		projwallh;
	int			strip_h;
	int			walltop;
	int			wallbot;
	int			xoff;
	int			yoff;
	int			dist;
}				t_wall;
t_wall			g_col;

typedef	struct	s_bmp_header
{
	char		type[2];
	u_int32_t	filesize;
	u_int16_t	reserved1;
	u_int16_t	reserved2;
	u_int32_t	pxdataoff;
	u_int32_t	headersize;
	int32_t		width;
	int32_t		height;
	u_int16_t	planes;
	u_int16_t	bpp;
	u_int32_t	compression;
	u_int32_t	imagesize;
	int32_t		xpermeter;
	int32_t		ypermeter;
	u_int32_t	totalcolors;
	u_int32_t	importantcolors;
}				t_bmp_file;
t_bmp_file		g_bmp;
int				g_save;

typedef struct	s_prite
{
	float		x;
	float		xof;
	float		y;
	float		yof;
	float		dist;
	float		size;
}				t_sprite;
t_sprite		*g_sp;
int				g_s_count;
int				g_save;
char			*g_file;

void			get_file(char *argv[]);

void			prm_init();
void			err_init(void);

void			treat_file(char *line);
void			get_map(char *line);
void			routing(char *line);
void			get_res(char *line);
void			get_rgb(char *line, int f);
int				prm_count(int num, int cnt, int f);
void			get_path(char *line, int c);
void			path_rout(char *s, int c);

int				is_map(int c);
int				is_player(int c);
int				is_srndbl(int c);
int				is_notspace(int c);
void			addline(char *line);
void			lng_lin();
void			nwl_cnt();
void			map_fil();
void			spc_fil();
void			build_map();
void			spc2wal();
float			spawn_direction();

void			arguments_errors(int error);
void			print_errs();
int				ch_err();
int				rgb_err();
int				res_err();
int				pat_err();
int				res_out();
int				rgb_out();
void			ch_fil_err();
void			map_err();
void			map_chk_opn();

int				white_space(char *line);

void			render_flr_cei();
void			walls3d(void);
int				render();
void			canvas_init();
void			player_init();
void			render_player();
void			draw_player(int x, int y, int clr);
void			draw_ray();
void			render_map();
void			circlebres(int xc, int yc, int r, int clr);
void			draw_rect(int x, int y, int clr);
void			draw_ver(int x, int start, int end, int clr);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);

int				shade(int i, char x);
unsigned int	shadow(unsigned int color, int col);
int				shadedcolor(int r, int g, int b, float percent);

void			texture_error(int error);
void			init_textures(void);
int				assign_textures(int i);
void			ray_norm(int i);

void			draw_sprite(int id);
void			sprites_conf(void);
void			sprite_sort(void);
void			init_sprites(void);

void			save_bmp(void);
void			screenshot();

float			clamp_clr(float clr);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);
int				rgb_to_int(int t, int r, int g, int b);

void			cast_rays(void);
int				update();
int				key_released(int keycode);
int				key_pressed(int keycode);
int				ft_quit(void);

void			move();
void			collision(float newx, float newy);
void			player_pos();

int				is_corner(int x, int y);
char			side_hit(float x, float y);
int				is_wall(float x, float y);
int				is_sprite(float x, float y);

float			clamp_percent(float percent);
float			normalize_ang(float ang);
float			d2r(float ang);
float			dis_pts(float x1, float y1, float x2, float y2);
float			deg(float x);

void			print_struct_elemts();
void			printmap();

int				res_invalid(int i, char *line);
void			set_color(char f, char rgb, int num);
int				skip_digit(char *line);
int				map_is_last();

void			bonus_events(int keycode, int pr);
void			wasd_r_events(int keycode);
void			arrow_r_events(int keycode);
void			wasd_p_events(int keycode);
void			arrow_p_events(int keycode);

void			play_m();
void			play_damage_sfx();
void			health_bg(void);
void			health_bar(void);
void			red_post();
#endif
