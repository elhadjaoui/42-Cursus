NAME = libasm.a
SRC = ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s
NASM = nasm -f macho64

all : $(NAME)

$(NAME) : 
		@$(NASM) ft_read.s
		@$(NASM) ft_strcmp.s
		@$(NASM) ft_strcpy.s
		@$(NASM) ft_strdup.s
		@$(NASM) ft_strlen.s
		@$(NASM) ft_write.s
		@ar -rc $(NAME) *.o
		@echo "\033[1;32mlibasm.a created succesfuly\033[m"
clean :
		@rm -f *.o
		@echo "\033[1;32mAll object files deleted succesfuly\033[m"
fclean : clean
		@rm -f $(NAME)
		@echo "\033[1;32mlibasm.a deleted succesfuly\033[m"
re : fclean all

