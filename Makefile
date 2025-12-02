# =======================
#   ft_printf - Makefile
# =======================

NAME	= ft_printf.a
CC		= cc
CFLAGS 	= -Wall Wextra Werror -g
OBJ	= $(SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

tests: $(NAME) tests.c
	$(CC) $(CFLAGS) tests.c $(NAME) -o tests
	@echo "Run: ./tests"

clean:
	rm -rf $(OBJ)
	@echo "Object files removed"

fclean: clean
	rm -rf $(NAME) tests
	@echo "Library and test binary removed"

re: fclean all

.PHONY: all clean fclean re tests