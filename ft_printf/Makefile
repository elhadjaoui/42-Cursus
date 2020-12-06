# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/28 22:28:31 by mel-hadj          #+#    #+#              #
#    Updated: 2019/12/29 07:06:07 by mel-hadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all: $(NAME)
	
$(NAME):
	@gcc -Wall -Wextra -Werror -c -g ft_flags.c ft_function1.c ft_function2.c \
	ft_function3.c ft_function4.c ft_function5.c ft_function6.c ft_printf.c
	@ar -rc $(NAME) *.o
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)

re: fclean all
