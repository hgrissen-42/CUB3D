/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:33 by hgrissen          #+#    #+#             */
/*   Updated: 2020/12/31 17:21:36 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

#define CUB3D_H

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "GNL/get_next_line.h"
#include "LIBFT/libft.h"

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

void        print_errs();
int         ch_err();
int         rgb_err();
int         res_err();
int         pat_err();
int         res_out();
int         rgb_out();
void        Ch_fil_err();

int         white_space(char *line);



//debugging
void print_struct_elemts();

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

}				t_prm;
t_prm g_prm;

typedef struct	s_errs {
    int         num_prm;
    int         dbl_inc;
    int         elm_inv;
}				t_err;
t_err g_err;

#endif