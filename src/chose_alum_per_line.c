#include "allum.h"

static int	save_nb(t_struct *s, int key, int *i)
{
  if (*i == 0)
    {
      color_print_nb(s->game, 7, 20, key);
      s->al_per_line = key - 48;
    }
  else if (*i == 1)
    {
      color_print_nb(s->game, 7, 21, key);
      s->al_per_line = s->al_per_line * 10 + key - 48;
    }
  *i = *i + 1;
  return (0);
}

static int	pack_nb(t_struct *s, int key, int *i)
{
  if (key == KEY_BACKSPACE)
    {
      if (*i == 2)
        {
          *i = *i - 1;
          mvwprintw(s->game, 7, 21, " ");
          s->al_per_line = s->line / 10;
        }
      else if (*i == 1)
        {
          *i = *i - 1;
          mvwprintw(s->game, 7, 20, " ");
          s->al_per_line = 0;
        }
      return (0);
    }
  if (*i == 0 || *i == 1)
    save_nb(s, key, i);
  return (0);
}

int	chose_alum_per_line(t_struct *s, int key, int i)
{
  s->al_per_line = 0;
  wclear(s->game);
  mvwprintw(s->game, 4, 6, "Allum1 :");
  mvwprintw(s->game, 6, 6, "Nb matches per line you wanna play with :");
  mvwprintw(s->game, 7, 6, "Nb (MAX 23) :");
  mvwprintw(s->game, 9, 6, "/* Type a nb between 2 and 23 */");
  mvwprintw(s->game, 15, 6, "Press ENTER to confirm.");
  mvwprintw(s->game, 16, 6, "Press b to go back");
  wrefresh(s->game);
  while ((key = getch()) != ENTER ||  i == 0
	 || s->al_per_line < 2 || s->al_per_line > 23)
    {
      if ((key >= '0' && key <= '9') || key == KEY_BACKSPACE)
        {
          pack_nb(s, key, &i);
          wrefresh(s->game);
        }
      if (key == 'b')
        return (chose_alum_nb(s, 0, 0, 1));
    }
  return (build_list_rectangle(s, XMIN, YMIN, 0));
}
