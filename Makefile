# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/20 16:51:10 by sjang             #+#    #+#              #
#    Updated: 2020/02/17 20:18:21 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = convert_c.c convert_p.c convert_u.c ft_printf.c lib.c\
	   convert_di.c convert_s.c convert_x.c convert_percent.c\
	   convert_di2.c convert_p2.c convert_u2.c lib2.c ft_printf2.c\

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@make -C libft
		@cp libft/libft.a $(NAME)
		@ar rc $(NAME) $^
		@ranlib $(NAME)
.o: .c
		@gcc $(FLAGS) -o $@ -c $<
clean:
		@make clean -C libft
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all
