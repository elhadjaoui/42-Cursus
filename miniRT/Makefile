NAME =			miniRT

CC =			gcc 

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./Headers/

DIR_SRCS =		./Src/



LIBMLX =		-lmlx -framework OpenGL -framework AppKit libmlx.dylib

			

SRC =			Intersection/cylinder_intersection.c\
				Intersection/plane_intersection.c\
				Intersection/spher_intersection.c\
				Intersection/square_intersection.c\
				Intersection/triangle_intersection.c\
				\
				Math/math.c\
				Math/math1.c\
				Math/math2.c\
				\
				Parsing/parsing_obj.c\
				Parsing/parsing_scene_config.c\
				Parsing/read_file.c\
				\
				Utils/draw.c\
				Utils/ft_atoi.c\
				Utils/ft_bzero.c\
				Utils/ft_calloc.c\
				Utils/ft_lstadd_back_bonus.c\
				Utils/ft_lstnew_bonus.c\
				Utils/ft_putstr_fd.c\
				Utils/ft_split.c\
				Utils/ft_strdup.c\
				Utils/get_next_line.c\
				Utils/get_next_line_utils.c\
				Utils/handle_errors.c\
				Utils/handle_errors2.c\
				Utils/handle_errors3.c\
				Utils/utils.c\
				Utils/utils1.c\
				\
				bitmap.c
			
SRCS =			$(addprefix $(DIR_SRCS), $(SRC)) minirt.c

OBJS =			*.o


all:			$(NAME)

$(NAME) :		$(OBJS)
				 @make -C ./minilibx_mms
				 @cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				$(CC) $(FLAGS) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)
$(OBJS) :  $(SRCS)
			@$(CC) -c $(FLAGS) $(SRCS)

norme:
				norminette $(DIR_SRCS) minirt.c
				norminette $(DIR_HEADERS)
run:			
				@./miniRT Scene/new_scene.rt

clean:
				$(RM) $(OBJS)

fclean:			clean
				@make clean -C ./minilibx_mms
				$(RM) libmlx.dylib
				$(RM) $(NAME)
				$(RM) $(OBJS)
				

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
