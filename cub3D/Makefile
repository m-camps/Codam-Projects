# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mcamps <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/12 02:10:28 by abobas        #+#    #+#                  #
#    Updated: 2020/10/12 20:54:34 by mcamps        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC := main.c read_data.c utils.c on_error.c fill_data.c struct_init.c fill_res.c \
		fill_path.c fill_color.c fill_map.c hook_function.c image.c dda.c fill_spawn.c \
		hook_move.c hook_rotate.c tex_init.c fill_tex.c image_calc.c flood_fill.c \
		sprite.c sprite_image.c fill_spr.c input_check.c screenshot.c struct_init_2.c \
		ft_atoi.c

SRC := $(SRC:%=srcs/%)

MLX = -lmlx -L . -framework OpenGL -framework Appkit

FLAGS = -Wall -Werror -Wextra  \
		-Ofast -march=native

MLXDIR = ./mlx/

all: $(NAME)

$(NAME):
	make -C $(MLXDIR)
	cp ./mlx/libmlx.dylib .
	make clean -C $(MLXDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME) $(MLX)

run: 
	./cub3D maps/test.cub

screenshot:
	./cub3D maps/test.cub --save

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libmlx.dylib
	rm -rf capture.bmp

re: fclean all
