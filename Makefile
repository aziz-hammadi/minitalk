# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahammad <ahammad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/28 13:48:33 by ahammad           #+#    #+#              #
#    Updated: 2021/10/27 18:01:31 by ahammad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		= server
NAME_CLIENT		= client

#NAME = fdf
SRC_SERVER		= server.c
SRC_CLIENT		= client.c
OBJ_CLIENT		= $(SRC_CLIENT:.c=.o)
OBJ_SERVER		= $(SRC_SERVER:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
LIBFT_DIR = ./libft/
               #      MINLBX_DIR = ./mlx_linux/

                  #   SRC_FILES = main.c ft_parsing.c ges_screan.c ft_suppl_fct.c event.c top_bande.c ft_ternary.c ft_loop_a.c
#OBJ_FILES = $(SRC_SERVER:.c=.o)
#OBJ_FILES = $(SRC_CLIENT:.c=.o)

                         #        SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_SERVER2 = $(addprefix $(OBJ_DIR), $(OBJ_SERVER))
OBJ_CLIENT2 = $(addprefix $(OBJ_DIR), $(OBJ_CLIENT))

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

$(NAME_SERVER): $(OBJ_SERVER2)
	$(CC) $(FLAGS) $(OBJ_SERVER2) -o $(NAME_SERVER) -L $(LIBFT_DIR) -lft
	@echo "$(NAME_SERVER) generated!"

$(NAME_CLIENT): $(OBJ_CLIENT2)
	$(CC) $(FLAGS) $(OBJ_CLIENT2) -o $(NAME_CLIENT) -L libft/ -lft
	@echo "$(NAME_CLIENT) generated!"

clean:
	rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME_SERVER)
	@rm -f $(NAME_CLIENT)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
