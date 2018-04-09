SRC =	./gnl/get_next_line.c \
	./gnl/get_next_line_fd.c \
	./marienbad.c \
	./my_getnbr.c \
	./try_again.c \
	./my.c \
	./main.c

CFLAGS += -Wextra -Wall
CFLAGS += -pedantic
CFLAGS += -I./include

NAME =	marienbad_text

RM =	rm -f

CC = gcc

OBJS=	$(SRC:.c=.o)

all: $(NAME)

ncurses-version: 
	make -C ncurses-version

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
