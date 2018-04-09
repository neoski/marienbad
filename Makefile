SRC =	build_list.c \
	case_marienbad.c \
	chose_alum_nb.c \
	chose_game_mode.c \
	chose_lvl.c \
	game_mode.c \
	key_left_right.c \
	key_up_down.c \
	list_configs.c \
	loop.c \
	lvl_check.c \
	main.c \
	marienbad.c \
	my.c \
	print_list.c \
	print_mode.c \
	print_opti.c \
	chose_game_structure.c \
	chose_alum_per_line.c \
	lets_take_a_screenshot.c \
	my_double_malloc.c \
	show_win.c

CFLAGS += -I./include

LDFLAGS = -W -lncurses

NAME =	marienbad_ncurse

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
