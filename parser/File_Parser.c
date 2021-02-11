/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File_Parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:19:42 by hgrissen          #+#    #+#             */
/*   Updated: 2021/02/11 18:21:51 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_file(void)
{
	int		fd;
	char	*line;

	fd = open("map.cub", O_RDONLY);
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
	if (c == 'R')
		get_res(line);
	else if (c == 'F' || c == 'C')
	{
		c == 'F' ? get_rgb(line, 'F') : get_rgb(line, 'C');
		g_prm.inc++;
	}
	else if (c == 'W' || c == 'E' || c == 'N' || c == 'S')
		routing(line);
	else if (!line[0] && g_err.map_bgn)
		g_err.inv_nwl = 1;
	else
		get_map(line);
}
