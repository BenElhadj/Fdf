# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/01 08:24:14 by bhamdi            #+#    #+#              #
#    Updated: 2018/11/15 13:47:32 by bhamdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Off=\033[0m             # Color off

BRed=\033[0;31m         # Red
BGreen=\033[1;32m       # Green
BWhite=\033[1;37m       # White

AWK = awk '{print $$1, $$2, $$3, $$4, $$5, $$6, $$7, $$8, $$9, $$10 $$11, $$12}'

NAME = fdf
FLAGS = -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit

LIB_PATH = libft/
LIB_NAME = libft.a
SRCS_PATH = srcs/

SRC_FILE = main.c init.c create_win.c read_file.c map.c draw.c event.c free.c

SRC = $(addprefix $(SRCS_PATH)/,$(SRC_FILE))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME)) 

OBJ = $(patsubst srcs/%.c,./%.o,$(SRC))
INC = -I includes/

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)

		make -C libft/ re
			gcc $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
				printf "${BGreen}[ ✔ ] libft.a \n\n" | ${AWK}
		printf "\033[7m${BWhite}[ OK ] ${Off}\n\n" | ${AWK}
		printf "\033[42m${BWhite} >-----[ fdf ]-----< ${Off}\n" | ${AWK}

./%.o: srcs/%.c
		gcc $(FLAGS) $(INC) -c $< -o $@
		printf "${BGreen}[ ✔ ] $<\n" | ${AWK}

clean:
	make clean -C libft
		rm $(OBJ)
			printf "${BRed}[ ✔ ] Clean${Off}\n" | ${AWK}
			printf "\033[42m${BWhite} <([ Clean ])> ${Off}\n" | ${AWK}

fclean:
	make fclean -C libft
		rm $(OBJ)
			printf "${BRed}[ ✔ ] Clean${Off}\n" | ${AWK}
		rm $(NAME)
			printf "${BRed}[ ✔ ] FClean${Off}\n" | ${AWK}

		printf "\033[42m${BWhite} <([ FClean ])> ${Off}\n" | ${AWK}

re: fclean all

.PHONY: all clean fclean re
