# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhsu <yhsu@hive.student.fi>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 15:30:09 by yhsu              #+#    #+#              #
#    Updated: 2024/03/13 13:34:50 by yhsu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc    
GREEN = \033[0;32m

FLAGS = -Wall -Wextra -Werror -I./libft -g 
MLX_FLAGS = -lglfw -framework Cocoa -framework OpenGL -framework IOKit

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a
LIBFT_INCLUDE = -I ${LIBFT_DIR}

MLX42_DIR = ./MLX42/build
MLX42 = ./MLX42/build/libmlx42.a
LD_FLAGS = -L/Users/${USER}/.brew/opt/glfw/lib/

INCLUDES = -I/opt/X11/include -Imlx

SOURCES  = 	map_check1.c\
			map_check2.c\
           path_check.c\
           so_long.c\
		   init.c\
		   load_sprite.c\
		   move.c\
		   move_direction.c\
		   screen_string.c\
		   error_delete.c\
		   parse_map.c\
		   render_map.c\
		   mix.c\
		   
SOURCES_BONUS  = 	./bonus_source/map_check1_bonus.c\
			./bonus_source/map_check2_bonus.c\
           ./bonus_source/path_check_bonus.c\
           ./bonus_source/so_long_bonus.c\
		   ./bonus_source/init_bonus.c\
		   ./bonus_source/load_sprite_bonus.c\
		   ./bonus_source/load_enemy_bonus.c\
		   ./bonus_source/move_bonus.c\
		   ./bonus_source/move_direction_bonus.c\
		   ./bonus_source/screen_string_bonus.c\
		   ./bonus_source/enemy_bonus.c\
		   ./bonus_source/error_delete_bonus.c\
		   ./bonus_source/parse_map_bonus.c\
		   ./bonus_source/render_map_bonus.c\
		   ./bonus_source/mix_bonus.c\


OBJECTS = ${SOURCES:.c=.o}
BONUS_OBJECTS = ${SOURCES_BONUS:.c=.o}


all: makelibft ${NAME} ${NAME_BONUS}


%.o: %.c 
	${CC} ${FLAGS} ${INCLUDES} -c $< -o $@

makelibft:
	make -C ${LIBFT_DIR}

${NAME}: ${LIBFT} ${MLX42} ${OBJECTS}
	@(echo "${GREEN}Creating The Executable✅: ${NAME}" && ${CC} ${CFLAGS} ${OBJECTS} ${LIBFT_INCLUDE} $(MLX42) $(MLX_FLAGS) ${LD_FLAGS} -L${LIBFT_DIR} ${INCLUDES} -lft -o ${NAME})

${NAME_BONUS}: ${LIBFT} ${MLX42} ${BONUS_OBJECTS}
	@(echo "${GREEN}Creating The Executable✅: ${NAME_BONUS}" && ${CC} ${CFLAGS} ${BONUS_OBJECTS} ${LIBFT_INCLUDE} $(MLX42) $(MLX_FLAGS) ${LD_FLAGS} -L${LIBFT_DIR} ${INCLUDES} -lft -o ${NAME_BONUS})

${LIBFT}:
	make -C ./libft

${MLX42}:
	cd MLX42 &&    cmake -B build && cmake --build build -j4

clean:
	rm -f ${OBJECTS} ${BONUS_OBJECTS}
	@make clean -C ${LIBFT_DIR}
	rm -rf MLX42/build

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	@make clean -C ${LIBFT_DIR} 

re: fclean all

.PHONY: all clean fclean re
