NAME = fractol

SRC = \
		main.c \
		atof.c \
		utils.c \
		colors.c \
		display.c \
		fractales.c \
		image.c \
		math.c	\
		palette.c

CC = cc
OBJ = $(SRC:.c=.o)

CFLAGS = -O3 -Wall -Wextra -Werror
CFLAGS += -I./minilibx-linux/

LDFLAGS = -L./minilibx-linux/
LDFLAGS += -lmlx_Linux
LDFLAGS += -lX11 -lXext


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re