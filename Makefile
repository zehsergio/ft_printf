# =======================
#   ft_printf - Makefile
# =======================

NAME	= libftprintf.a
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror -g
SRC		= ft_printf.c ft_printf_tools.c
OBJ		= $(SRC:.c=.o)

# Rules
all: $(NAME)

 $(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

tests: $(NAME)
	$(CC) $(CFLAGS) tests.c $(NAME) -o tests.o
	@echo "Run: ./tests.o"

clean:
	rm -f $(OBJ)
	@echo "Object files removed"

fclean: clean
	rm -f $(NAME) tests
	@echo "Library and test binary removed"

re: fclean all

.PHONY: all clean fclean re tests