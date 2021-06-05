CHECKER =			checker
PUSH_SWAP = 		push_swap
NAME = push_swap

CC =			gcc 

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

SANITIZE = -fsanitize=address

DIR_HEADERS =	./headers/

DIR_SRCS =		./srcs/
	
SRC =			 operations_1.c  utils.c utils_2.c utils_1.c  utils_3.c  utils_4.c  utils_5.c handle_errors.c  get_next_line.c
			
SRCS =			$(addprefix $(DIR_SRCS), $(SRC)) 



all:			$(NAME)

$(NAME) :
				 @make -C ./libft
				 @make bonus -C ./libft
				 @cp ./libft/libft.a libft.a
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(SRCS) ./srcs/push_swap.c  libft.a -o $(PUSH_SWAP)

norme:
				norminette $(SRCS) 
				norminette $(DIR_HEADERS)
				norminette ./libft/
bonus:
				@$(CC) $(FLAGS) -I $(DIR_HEADERS) $(SRCS) ./srcs/checker.c  libft.a -o $(CHECKER)

clean:
				@make clean -C ./libft

fclean:			clean
				@make fclean -C ./libft
				@$(RM) libft.a
				@$(RM) $(NAME) $(PUSH_SWAP) $(CHECKER)
				

re:				fclean all

.PHONY:			all, clean, fclean, re