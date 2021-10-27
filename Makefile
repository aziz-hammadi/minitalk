# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:48:33 by ahammad           #+#    #+#              #
#    Updated: 2021/10/27 15:43:21 by ahammad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		= server
NAME_CLIENT		= client

#NAME = fdf
SRC_SERVER		= server.c
SRC_CLIENT		= client.c

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
               #      MINLBX_DIR = ./mlx_linux/

OBJ_CLIENT		= $(SRC_CLIENT:.c=.o)
OBJ_SERVER		= $(SRC_SERVER:.c=.o)
                  #   SRC_FILES = main.c ft_parsing.c ges_screan.c ft_suppl_fct.c event.c top_bande.c ft_ternary.c ft_loop_a.c
                 #    OBJ_FILES = $(SRC_FILES:.c=.o)

                         #        SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
                   #      MINLBX	= $(addprefix $(MINLBX_DIR), libmlx.a)

                    #   LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
			         # -L./mlx_linux -lmlx -lXext -lX11 -lm

all: obj $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

obj:
	@mkdir $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(FLAGS) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
$(LIBFT):
	@make -C $(LIBFT_DIR)
                      #         $(MINLBX):
                     #             	@make -C $(MINLBX_DIR)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
	@echo "$(NAME) generated!"

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) -o $(NAME_CLIENT)
	@echo "$(NAME) generated!"

clean:
	rm -f $(OBJ_SERVER)
	rm -f $(OBJ_CLIENT)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(SRC_CLIENT)
	@rm -f $(SRC_SERVER)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
