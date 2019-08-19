SRC = src/*.c

OBJ = ./*.o

HDR = -I includes/

CC = gcc -g

LIBFT = libft/

LIBFT_A = libft/libft.a

NAME = minishell

all: $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) -c $(HDR) $(SRC)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(HDR) $(SRC) -o $(NAME) $(LIBFT_A)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
