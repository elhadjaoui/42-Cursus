# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hadj <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 18:19:35 by mel-hadj          #+#    #+#              #
#    Updated: 2019/11/14 17:05:16 by mel-hadj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BN = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c   ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
	

all: $(NAME)
	
$(NAME):
	@gcc -Wall -Wextra -Werror -c ft_atoi.c \
		ft_itoa.c ft_strdup.c ft_strjoin.c ft_strchr.c\
		ft_strlen.c \

	@ar -rc $(NAME) *.o 
clean:
	@rm -f *.o
fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:
	@gcc -Wall -Wextra -Werror -c $(BN)
	@ar -rc $(NAME) *.o
