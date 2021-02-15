/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:42 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/14 16:41:37 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_file(char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		arguments_errors(4);
	while (get_next_line(fd, &line))
	{
		treat_file(line);
		free(line);
		line = NULL;
	}
	treat_file(line);
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	treat_file(char *line)
{
	char c;

	c = line[0];
	if (c == 'R' && !g_err.map_bgn)
		get_res(line);
	else if ((c == 'F' || c == 'C') && ft_isspace(line[1]) && !g_err.map_bgn)
	{
		c == 'F' ? get_rgb(line, 'F') : get_rgb(line, 'C');
		g_prm.inc++;
	}
	else if ((c == 'W' || c == 'E' || c == 'N' || c == 'S') && !g_err.map_bgn)
		routing(line);
	else if (!line[0] && g_err.map_bgn)
		g_err.inv_nwl = 1;
	else if (g_prm.inc == 8)
		get_map(line);
	else if (!line[0])
		c = line[0];
	else
	{
		ch_fil_err();
		exit(0);
	}
}
