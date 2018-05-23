NAME = lem-in

CC = gcc

FLAGS = 

RM = rm -f

SRC = srcs/main.c srcs/lem_in.c srcs/parsing.c srcs/manage_container.c \
	srcs/parsing_tools.c srcs/parsing2.c srcs/manage_rooms_lst.c \
	srcs/parsing_link.c srcs/manage_links_lst.c srcs/algorithm_tools.c \
	srcs/algorithm.c

LIB_DIR = libft/

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_DIR) all
	$(CC) $(FLAGS) $(OBJ) -o $@ -L./libft/ -lft 
	@echo "lem-in done."

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@make clean -C $(LIB_DIR)
	$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIB_DIR)
	$(RM) $(NAME)

re: fclean all
