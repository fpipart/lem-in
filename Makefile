# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpipart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 10:59:14 by fpipart           #+#    #+#              #
#    Updated: 2017/01/31 18:17:46 by fpipart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = lemin.c utilities.c utilities_tube.c ft_atoi_checker.c	\
		del_lst.c algo.c algo_shortest_paths.c manage_path.c	\
		nbr_path.c reshape_map.c display.c

SRC_PATH = ./srcs/
CFILES = $(FILES:%=./srcs/%)

OBJ_PATH = ./obj/
OBJ_FILE = $(FILES:%.c=%.o)
OBJ = $(OBJ_FILE:%=$(OBJ_PATH)%)

NAME = lem-in

LIB_PATH = ./libft/
LIB = libft.a

INC_PATH = ./includes/
INC = lem_in.h

FLAGS = -Wextra -Werror -Wall

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_PATH)$(INC)
	@mkdir -p $(OBJ_PATH)
	gcc $(FLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(LIB_PATH)$(LIB) $(OBJ)
	gcc -L ./libft/ -lft -o $(NAME) $(OBJ)

$(LIB_PATH)$(LIB):
	make -C $(LIB_PATH)

clean:
	/bin/rm -rf $(OBJ_PATH)
	make -C ./libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
