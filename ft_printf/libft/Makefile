# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mcamps <mcamps@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/02 15:10:48 by mcamps         #+#    #+#                 #
#    Updated: 2020/01/07 14:02:11 by mcamps        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strchr.c \
	ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
	ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_itoa_base.c

FLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	gcc $(FLAGS) -c $(SRCS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
