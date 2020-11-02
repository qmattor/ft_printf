CC := gcc
NAME := ft_printf.a
CFLAGS := -Wall -Wextra -Werror
LIBFT := libft/libft.a
SOURCE :=	SRC/ft_printf.c SRC/write_data_type.c SRC/write_data_types_second.c SRC/struct_stuff.c SRC/errors.c\
			SRC/parsing.c SRC/debugging.c SRC/switches.c SRC/misc.c SRC/width.c

OBJECTS := $(patsubst %.c,%.o,$(SOURCE))

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	make -C libft
	make -C libft OBJS = $(OBJECTS)
	ar rc $@ $^ OBJS
	ranlib $(NAME)
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