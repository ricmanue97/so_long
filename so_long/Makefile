# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ricmanue < ricmanue@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 13:59:18 by ricmanue          #+#    #+#              #
#    Updated: 2025/01/15 11:11:39 by ricmanue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and CFLAGS
CC                      = @cc
CFLAGS                  = -Wall -Wextra -Werror -I/opt/X11/include -I./minilibx-linux
LDFLAGS                 = -L/opt/X11/lib -lX11 -L./minilibx-linux -lmlx -lXext -lX11
RM                      = @rm -f

# Source Files
SO_LONG_SRC             = error_management.c game_init.c map_check.c \
						map_drawing.c map_init.c so_long.c \
						valid_map_checker.c

# Object Files
SO_LONG_OBJECTS         = error_management.o game_init.o map_check.o \
						map_drawing.o map_init.o so_long.o \
						valid_map_checker.o

# Executable
SO_LONG                 = so_long

# Rules
all:                    $(SO_LONG)

$(SO_LONG):             $(SO_LONG_OBJECTS) $(LIBFT)
						@echo "Building $(SO_LONG)..."
						$(CC) $(CFLAGS) $(SO_LONG_OBJECTS) $(LIBFT) $(LDFLAGS) -o $(SO_LONG)
						@echo "$(SO_LONG) has been successfully built"

%.o: %.c
						@echo "Compiling $<..."
						$(CC) $(CFLAGS) -c $< -o $@

clean:
						$(RM) $(SO_LONG_OBJECTS)
						@make -s clean -C ./libft
						@echo "Cleaned up .o files."

fclean:                 clean
						@$(RM) $(SO_LONG)
						@make -s fclean -C ./libft
						@echo "Removed executables."

re:                     fclean all
						@echo "Fully rebuilt"

.PHONY: all clean fclean re