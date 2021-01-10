/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 10:05:00 by hgrissen          #+#    #+#             */
/*   Updated: 2021/01/04 14:41:56 by hgrissen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <fcntl.h>

# include <stdlib.h>

# include <unistd.h>

#include "../LIBFT/libft.h"

#define BUFFER_SIZE 1000

int				outtil(int fd, char **rest, char **line);
int				get_next_line(int fd, char **line);
char			*linend(char		*str);

#endif
