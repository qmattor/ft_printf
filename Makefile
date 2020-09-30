CC := gcc
NAME := ft_printf
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft/libft.a
SOURCE := SRC/ft_printf.c SRC/TEST_MAIN.c SRC/write_data_type.c SRC/variable_param.c SRC/write_data_types_second.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

debug:
	$(CC) $(CFLAGS) -g $(SOURCE) $(LIBFT) -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) -fsanitize=address $(SOURCE) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJECTS)

sclean:
	rm -f $(OBJECTS)

fclean: dclean
	rm -f $(NAME)
	rm -f $(LIBFT)

dclean: clean
	rm -rf $(NAME).dSYM

re: fclean all

sre: sclean all