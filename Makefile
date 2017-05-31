LEM-IN = lem-in

GCC_FLAGS = gcc -Wall -Werror -Wextra

SRC = 	./src/test.c

LIBFT = -L libft/ -lft

HEADERS = -I ./includes -I ./libft

O_FILES = $(SRC:.c=.o)

all: $(LEM-IN)

$(LEM-IN):
	cd libft && make all
	$(GCC_FLAGS) $(SRC) $(HEADERS) $(LIBFT) -o $(LEM-IN)
	cd libft && make fclean

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(LEM-IN)

re: fclean all

.PHONY: all clean fclean re
