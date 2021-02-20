# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 14:31:20 by hgrissen          #+#    #+#              #
#    Updated: 2021/02/19 12:32:34 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./GNL/get_next_line_utils.c ./GNL/get_next_line.c ./basic/ft_atoi.c ./basic/ft_bzero.c ./basic/ft_calloc.c									\
		./basic/ft_itoa.c ./basic/ft_isalnum.c ./basic/ft_isalpha.c ./basic/ft_isascii.c ./basic/ft_isdigit.c										\
		./basic/ft_isprint.c ./basic/ft_memccpy.c  ./basic/ft_memchr.c ./basic/ft_memcmp.c ./basic/ft_memcpy.c										\
		./basic/ft_memmove.c ./basic/ft_memset.c ./basic/ft_putchar_fd.c ./basic/ft_putendl_fd.c ./basic/ft_putnbr_fd.c								\
		./basic/ft_putstr_fd.c ./basic/ft_split.c ./basic/ft_strchr.c ./basic/ft_strdup.c  ./basic/ft_strjoin.c ./basic/ft_strlcat.c				\
		./basic/ft_strlcpy.c ./basic/ft_strlen.c ./basic/ft_strmapi.c ./basic/ft_strncmp.c ./basic/ft_strnstr.c ./basic/ft_strrchr.c				\
		./basic/ft_strtrim.c  ./basic/ft_substr.c ./basic/ft_tolower.c ./basic/ft_toupper.c ./parser/debuglogs.c ./parser/error_handler.c			\
		./parser/error_util.c ./parser/file_parser.c ./parser/get_map.c ./parser/get_params.c ./parser/get_path.c ./parser/map_build.c				\
		./parser/avoid_2_assign.c ./parser/map_utility.c ./parser/structs_init.c ./parser/utility.c  color_utils.c event_handler.c mlx_init.c		\
		quit.c raycaster.c render_2d.c shot.c wall_projection.c cub3d.c math_util.c player_mouvement.c raycast_util.c render3d.c render_shapes.c	\
		sprite_projection.c shadow_bonus.c bg_music.c event_utils.c sfx.c


OBJ =	./GNL/get_next_line_utils.o ./GNL/get_next_line.o ./basic/ft_atoi.o ./basic/ft_bzero.o ./basic/ft_calloc.o									\
		./basic/ft_itoa.o ./basic/ft_isalnum.o ./basic/ft_isalpha.o ./basic/ft_isascii.o ./basic/ft_isdigit.o										\
		./basic/ft_isprint.o ./basic/ft_memccpy.o  ./basic/ft_memchr.o ./basic/ft_memcmp.o ./basic/ft_memcpy.o										\
		./basic/ft_memmove.o ./basic/ft_memset.o ./basic/ft_putchar_fd.o ./basic/ft_putendl_fd.o ./basic/ft_putnbr_fd.o								\
		./basic/ft_putstr_fd.o ./basic/ft_split.o ./basic/ft_strchr.o ./basic/ft_strdup.o  ./basic/ft_strjoin.o ./basic/ft_strlcat.o				\
		./basic/ft_strlcpy.o ./basic/ft_strlen.o ./basic/ft_strmapi.o ./basic/ft_strncmp.o ./basic/ft_strnstr.o ./basic/ft_strrchr.o				\
		./basic/ft_strtrim.o  ./basic/ft_substr.o ./basic/ft_tolower.o ./basic/ft_toupper.o ./parser/debuglogs.o ./parser/error_handler.o			\
		./parser/error_util.o ./parser/file_parser.o ./parser/get_map.o ./parser/get_params.o ./parser/get_path.o ./parser/map_build.o				\
		./parser/avoid_2_assign.o ./parser/map_utility.o ./parser/structs_init.o ./parser/utility.o  color_utils.o event_handler.o mlx_init.o		\
		quit.o raycaster.o render_2d.o shot.o wall_projection.o cub3d.o math_util.o player_mouvement.o raycast_util.o render3d.o render_shapes.o	\
		sprite_projection.o shadow_bonus.o bg_music.o event_utils.o



HEADER = ./GNL/get_next_line.h *.h ./basic/libft.h cub3d.h
	
BONUS = $(SRC) shadow_bonus.c

BHEADER = header_bonus.h

NAME = cub3D
BNAME = Cub3D

all: $(NAME)

$(NAME): $(SRC)
	gcc -Wall -Werror -Wextra -lmlx -O3 -fsanitize=address -framework OpenGL -framework Appkit $(SRC) -o cub3D	-D BON=0

bonus: $(BNAME)

$(BNAME) : $(SRC)
	gcc -Wall -Werror -Wextra -lmlx -O3 -framework OpenGL -framework Appkit $(SRC) -o cub3D -D BON=1

norm:
	norminette $(SRC) $(HEADER)

bnorm:
	norminette $(HEADER) $(BONUS) $(BHEADER)
	
clean:
	rm -f $OBJ
	
fclean: clean
	rm -f $(NAME)

	
re: fclean all

bre: bclean bonus