# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgrissen <hgrissen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 14:31:20 by hgrissen          #+#    #+#              #
#    Updated: 2020/12/29 14:33:40 by hgrissen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

OBJECT = *.o

NAME = cub3d.a

all : $(NAME)

$(NAME) :
	@gcc -Wall -Wextra -Werror  $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean : 
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all