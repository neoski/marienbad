#include "allum.h"

int	start_curse()
{
  if (initscr() == NULL)
    return (my_putstr("Couldn't initscr.\n", 2));
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_YELLOW, COLOR_BLUE);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  curs_set(0);
  if (noecho() == ERR)
    return (my_putstr("Couldn't noecho.\n", 2));
  if (keypad(stdscr, TRUE) == ERR)
    return (my_putstr("Couldn't keypad.\n", 2));
  return (0);
}

void	just_quit(t_struct *s)
{
  if (s != NULL)
    free(s);
  endwin();
  exit(0);
}

int		main()
{
  t_struct	*s;
  WINDOW	*frame;

  if (start_curse() == -1 || (s = malloc(sizeof(*s))) == NULL)
    just_quit(s);
  if ((frame = newwin(25, 51, 1, 3)) == NULL)
    return (my_putstr("Couldn't create frame window.\n", 2));
  if ((s->game = newwin(23, 49, 2, 4)) == NULL)
    return (my_putstr("Couldn't create game window.\n", 2));
  wbkgd(frame, COLOR_PAIR(3));
  wbkgd(s->game, COLOR_PAIR(1));
  wborder(frame, '+', '+', '+', '+', '+', '+', '+', '+');
  wrefresh(stdscr);
  wrefresh(frame);
  chose_game_mode(s, 0);
  just_quit(s);
  return (0);
}
