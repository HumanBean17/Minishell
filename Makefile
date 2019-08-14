SRC = src/*.c

HDR = -I includes/

CC = gcc -Wall -Wextra -Werror

LIBFT = libft/

LIBFT_A = libft/libft.a

NAME = minishell

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	$(CC) $(HDR) $(SRC) $(LIBFT_A) -o $(NAME)

clean:
	make -C $(LIBFT) clean

fclean:
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all