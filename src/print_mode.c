#include "marienbad.h"

int	print_screenshot(WINDOW *w, char *str)
{
  wattron(w, COLOR_PAIR(2));
  mvwprintw(w, 8, 31, "%s", str);
  wattroff(w, COLOR_PAIR(2));
  return (0);
}

int	print_whereami_notselect(WINDOW *w, int y, int x, char *str)
{
  wattron(w, A_UNDERLINE);
  wattron(w, COLOR_PAIR(2));
  mvwprintw(w, y, x, str);
  wattroff(w, A_UNDERLINE);
  wattroff(w, COLOR_PAIR(2));
  return (0);
}

int	print_whereami(WINDOW *w, int y, int x, char *str)
{
  wattron(w, COLOR_PAIR(2));
  wattron(w, A_REVERSE);
  mvwprintw(w, y, x, str);
  wattroff(w, COLOR_PAIR(2));
  wattroff(w, A_REVERSE);
  return (0);
}

int	print_videorev(WINDOW *w, int y, int x, char *str)
{
  wattron(w, A_REVERSE);
  mvwprintw(w, y, x, str);
  wattroff(w, A_REVERSE);
  return (0);
}
