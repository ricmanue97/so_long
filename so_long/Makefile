# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue <ricmanue@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:59:18 by ricmanue          #+#    #+#              #
#    Updated: 2025/02/04 15:44:44 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIBFT	=	./libft/libft.a
MLX		=	.././mlx_linux/libmlx.a

CC	=	@cc
CFLAGS	=	-Wall -Werror -Wextra
MLXFLAGS	=	-Iminilibx-linux -lXext -lX11 -lm -lz
RM	=	@rm -f

SRCS	=	error_management.c game_setup.c map_opening.c \
			map_check.c map_drawing.c playing.c so_long.c \
			valid_map_checker.c

OBJS	=	error_management.o game_setup.o map_opening.o\
			map_check.o map_drawing.o playing.o so_long.o \
			valid_map_checker.o
all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
		@echo "Make .o and so_long."
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
		@make -s -C ./libft

$(MLX):
		@make -s -C .././mlx_linux


%.o:	$(SRCS)%.c
		@$(CC) $(CFLAGS) -c $< -o $@


clean:
		$(RM) -r $(OBJS)
		@make -s clean -C ./libft
		@make -s clean -C .././mlx_linux
		@echo "Clean .o files."

fclean:		clean
		$(RM) $(NAME)
		@make -s fclean -C ./libft
		@echo "Clean exacuteble/s."

re:		fclean all

.PHONY:		all clean fclean re


