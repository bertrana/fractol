# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 04:25:14 by yjohns            #+#    #+#              #
#    Updated: 2019/11/01 05:30:43 by yjohns           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB_NAME = libft.a
SRC_DIR = sources/
OBJ_DIR = obj/
INC_DIR = includes/
LIB_DIR = libft/

LFT = $(addprefix $(LIB_DIR), $(LIB_NAME))

C_FILES =	main.c\
			fractol.c

HEADERS = $(INC_DIR)fractol.h $(LIB_DIR)libft.h

SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
LIB_SRC = $(addprefix $(LIB_DIR), $(LIB_FILES))

CC = gcc -O2
CFLAGS = -Wall
INC = -I $(INC_DIR) -I $(LIB_DIR)
FRAMEWORKS = -lmlx -framework OpenGL -framework AppKit
C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

all: $(NAME)

$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
		@make -C $(LIB_DIR)
		@$(CC) $(CFLAGS) $(OBJ) $(LFT) $(FRAMEWORKS)  -o $(NAME)
		@printf "$(C_MAGENTA)FRACTOL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR):
		@mkdir obj
		@printf "$(C_MAGENTA)FRACTOL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
		@$(CC) $(CFLAGS) -c $(INC) $< -o $@
		@printf "$(C_MAGENTA)FRACTOL:$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@
clean:
		@rm -rf $(OBJ_DIR)*
		@make clean -C $(LIB_DIR)
		@printf "$(C_MAGENTA)FRACTOL:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
		@rm -rf $(NAME)
		@make fclean -C $(LIB_DIR)
		@printf "$(C_MAGENTA)FRACTOL:$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all

norm:
	@norminette $(SRC) $(HEADERS)

allnorm: norm
	@norminette $(LIB_SRC)