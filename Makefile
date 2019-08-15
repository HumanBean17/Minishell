SRC = src/*.c

OBJ = ./*.o

HDR = -I includes/

CC = gcc

LIBFT = libft/

LIBFT_A = libft/libft.a

NAME = minishell

all: $(OBJ) $(SRC)

$(OBJ):
	make -C $(LIBFT)
	$(CC) -c $(HDR) $(SRC) $(LIBFT_A)

$(SRC): $(OBJ)
	$(CC) $(HDR) $(SRC) $(LIBFT_A) -o $(NAME)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all