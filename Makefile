SRC =	src/build_list.c \
	src/case_marienbad.c \
	src/chose_alum_nb.c \
	src/chose_game_mode.c \
	src/chose_lvl.c \
	src/game_mode.c \
	src/key_left_right.c \
	src/key_up_down.c \
	src/list_configs.c \
	src/loop.c \
	src/lvl_check.c \
	src/main.c \
	src/marienbad.c \
	src/my.c \
	src/print_list.c \
	src/print_mode.c \
	src/print_opti.c \
	src/chose_game_structure.c \
	src/chose_alum_per_line.c \
	src/lets_take_a_screenshot.c \
	src/my_double_malloc.c \
	src/show_win.c

CFLAGS += -I./include

LDFLAGS = -W -lncurses

NAME =	marienbad

RM =	rm -f

CC = gcc

OBJS=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
