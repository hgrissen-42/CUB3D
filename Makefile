# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 14:31:20 by hgrissen          #+#    #+#              #
#    Updated: 2021/01/20 15:06:02 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRC = *.c

#OBJECT = *.o

#NAME = cub3d.a

#all : $(NAME)

#$(NAME) :
#	@gcc -Wall -Wextra -Werror  $(SRC)
#	@ar rc $(NAME) $(OBJECT)
#	@ranlib $(NAME)

#clean : 
#	@rm -rf *.o

#fclean : clean
#	@rm -rf $(NAME)

#re : fclean all

INC=%%%%

INCLIB=$(INC)/../lib

CC=gcc

CFLAGS= -I$(INC) -O3 -I..

NAME= cub3D
SRC = test.c
OBJ = $(SRC:.c=.o)

all     :$(NAME)

$(NAME) :$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -L.. -lmlx -L$(INCLIB)-lX -lXext 11 -lm -lbsd

clean   :
        rm -f $(NAME) $(OBJ) *~ core *.core


re      : clean all
