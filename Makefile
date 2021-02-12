# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 14:31:20 by hgrissen          #+#    #+#              #
#    Updated: 2021/02/12 12:18:05 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./GNL/get_next_line_utils.c ./GNL/get_next_line.c ./LIBFT/ft_atoi.c ./LIBFT/ft_bzero.c ./LIBFT/ft_calloc.c ./LIBFT/ft_itoa.c ./LIBFT/ft_isalnum.c ./LIBFT/ft_isalpha.c ./LIBFT/ft_isascii.c ./LIBFT/ft_isdigit.c ./LIBFT/ft_isprint.c ./LIBFT/ft_memccpy.c  ./LIBFT/ft_memchr.c ./LIBFT/ft_memcmp.c ./LIBFT/ft_memcpy.c  ./LIBFT/ft_memmove.c ./LIBFT/ft_memset.c ./LIBFT/ft_putchar_fd.c ./LIBFT/ft_putendl_fd.c ./LIBFT/ft_putnbr_fd.c ./LIBFT/ft_putstr_fd.c ./LIBFT/ft_split.c ./LIBFT/ft_strchr.c ./LIBFT/ft_strdup.c  ./LIBFT/ft_strjoin.c ./LIBFT/ft_strlcat.c ./LIBFT/ft_strlcpy.c ./LIBFT/ft_strlen.c ./LIBFT/ft_strmapi.c ./LIBFT/ft_strncmp.c ./LIBFT/ft_strnstr.c ./LIBFT/ft_strrchr.c ./LIBFT/ft_strtrim.c  ./LIBFT/ft_substr.c ./LIBFT/ft_tolower.c ./LIBFT/ft_toupper.c ./parser/debuglogs.c ./parser/error_handler.c ./parser/error_util.c ./parser/file_parser.c ./parser/get_map.c ./parser/get_params.c ./parser/get_path.c ./parser/map_build.c ./parser/avoid_2_assign.c ./parser/map_utility.c ./parser/structs_init.c ./parser/utility.c  color_utils.c event_handler.c mlx_init.c quit.c raycaster.c render_2d.c shot.c wall_projection.c cub3d.c math_util.c player_mouvement.c raycast_util.c render3d.c render_shapes.c sprite_projection.c

HEADER = ./GNL/get_next_line.h *.h ./LIBFT/libft.h cub3d.h
	
BONUS = $(SRC) shadow_bonus.c

BHEADER = header_bonus.h

NAME = cub3D

BNAME = bonus_cub3D

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -o $(NAME) -D BON=0 $(SRC)

bonus: $(BNAME)

$(BNAME): $(BONUS)
	gcc -Wall -Werror -Wextra -lmlx -O3 -framework OpenGL -framework Appkit $(BONUS) -o $(BNAME) -D BON=1 

norm:
	norminette $(SRC) $(HEADER)

bnorm:
	norminette $(HEADER) $(BONUS) $(BHEADER)
	
clean:
	rm -f *.o */*.o
	
fclean: clean
	rm -f $(NAME)

bclean: clean
	rm -f $(BNAME)
	
re: fclean all

bre: bclean bonus