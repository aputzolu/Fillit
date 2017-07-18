NAME = fillit

OBJ = $(SRC:%.c=%.o)

SRC = checker.c clean.c get_coord.c init.c main.c reader.c solver.c

CPP = gcc

FLAGS = -Werror -Wextra -Wall

LIBPATH = libft/

LIBNAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CPP) -o $(NAME) $(OBJ) -L. $(LIBPATH)/$(LIBNAME)

$(OBJ):
	$(CPP) $(FLAGS) -c $(SRC)

clean:
	make clean -C libft
	/bin/rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME)

re: clean fclean all
	make re -C libft
