NAME = lem_in

SRC = ./src
OBJ = ./obj
LIB = ./libft

SRC_FILES = main.c\
			error_management.c\
			parser.c\
			parse_map.c\
			parse_room.c\
			breadth_first_search.c\

SRCS 		= $(addprefix $(SRC)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJ)/, $(SRC_FILES:c=o))

INC = -I ./includes
INC_LIB = -I ./libft/includes

LIB_NAME = ./libft/libftprintf.a
LIBS_LINK = -L $(LIB)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

# ***************** targets ***************** #

all: dir $(NAME)

dir:
	@mkdir -p $(OBJ)
	@make -C $(LIB)


$(NAME): $(OBJS)
	@gcc $(OBJS) -g $(LIB_NAME) $(LIBS_LINK) -o $(NAME)
	@echo good compile lem_in!

$(OBJ)/%.o:$(SRC)/%.c
	@gcc -g $(FLAGS) $(INC_LIB) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ) > /dev/null
	@make -C $(LIB) clean > /dev/null

fclean: clean
	@rm -rf $(NAME) > /dev/null
	@make -C $(LIB) fclean > /dev/null

re: fclean all