/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:57:14 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/10 17:09:37 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	arguments_errors(int error)
{
	if (error == 1)
		printf("Error:\nwrong config file extension");
	if (error == 2)
		printf("Error:\nthe second argument must be --save");
	if (error == 3)
		printf("Error:\nwrong number of parameters");
	if (error == 4)
		printf("Error:\nwrong config file");
	exit(0);
}

void	arguments(int argc, char *argv[])
{
	int end;

	end = ft_strlen(argv[1]) - 1;
	if (argc == 3)
	{
		if (argv[1][end] == 'b' && argv[1][end - 1] == 'u' &&
			argv[1][end - 2] == 'c' && argv[1][end - 3] == '.')
			g_file = ft_strdup(argv[1]);
		else
			arguments_errors(1);
		if (!ft_strncmp(argv[2], "--save", 7))
			g_save = 1;
		else
			arguments_errors(2);
	}
	else if (argc == 2)
	{
		if (argv[1][end] == 'b' && argv[1][end - 1] == 'u' &&
			argv[1][end - 2] == 'c' && argv[1][end - 3] == '.')
			g_file = ft_strdup(argv[1]);
		else
			arguments_errors(1);
	}
	else
		arguments_errors(3);
}

void  screenshot()
{
    save_bmp();
    exit(0);
}

int main(int argc, char **argv)
{  
    prm_init();
    err_init();
	arguments(argc, argv);
    get_file();
    if (g_err.map_bgn)
    { 
        build_map();
        map_chk_opn();
    }
    //print_struct_elemts();
    Ch_fil_err();
    //render_map();
    canvas_init();
    init_sprite();
    
    mlx_loop_hook(g_mlx.mlx, update, &g_mlx);
    mlx_loop(g_mlx.mlx);

    return 0;
}







    
    
