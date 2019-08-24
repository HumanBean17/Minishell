SRC = src/builtin.c \
	src/change_dir.c \
	src/envp.c \
	src/error.c \
	src/free.c \
	src/get_next_line.c \
	src/homeresonance.c \
	src/main.c \
	src/percent.c \
	src/search.c \
	src/signals.c \
	src/split.c \
	src/split_whitespaces.c

OBJ = builtin.o \
		change_dir.o \
		envp.o \
		error.o \
		free.o \
		get_next_line.o \
		homeresonance.o \
		main.o \
		percent.o \
		search.o \
		signals.o \
		split.o \
		split_whitespaces.o

HDR = -I includes/

CC = gcc  -Wall -Wextra -Werror

LIBFT = libft/

LIBFT_A = libft/libft.a

NAME = minishell

all: LIB $(OBJ) $(NAME)

LIB:
	make -C $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(HDR) $(OBJ) -o $(NAME) $(LIBFT_A)

$(OBJ): $(SRC)
	$(CC) -c $(HDR) $(SRC)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all
