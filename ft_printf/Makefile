# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mcamps <mcamps@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/07 13:31:39 by mcamps         #+#    #+#                 #
#    Updated: 2020/02/05 15:36:51 by mcamps        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = conv_c.c conv_d.c conv_p.c conv_s.c conv_u.c conv_x.c \
		ft_data_p.c ft_data_w.c ft_data.c  ft_itoa_u.c\
		ft_printf.c ft_struct.c ft_utils.c

FLAGS =  -Wall -Werror -Wextra

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	gcc $(FLAGS) -I libft/libft.h -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
