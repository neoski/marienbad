#include "allum.h"

static int	move_chose_form(t_struct *s, char **str, int *c)
{
  int		i;

  i = 0;
  if (*c == 0)
    *c = 1;
  else
    *c = 0;
  while (++i != 3)
    {
      if (i - 1 == *c)
        print_whereami(s->game, i + 6, 6, str[i - 1]);
      else
        mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
  return (0);
}

static int	print_chose_form(t_struct *s)
{
  mvwprintw(s->game, 4, 6, "Allum1 : Chose game structure :");
  mvwprintw(s->game, 14, 6, "Use directional keys to move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to chose.");
  mvwprintw(s->game, 16, 6, "Press b to go back.");
  return (0);
}

int	chose_game_structure(t_struct *s, int key, int choice)
{
  char  *str[2];

  wclear(s->game);
  str[0] = "Pyramid";
  str[1] = "Rectangle";
  print_chose_form(s);
  move_chose_form(s, str, &choice);
  wrefresh(s->game);
  while ((key = getch()) != ENTER)
    if (key == KEY_UP || key == KEY_DOWN || key == 'b')
      {
        if (key == 'b' && s->mode != 0)
	  return (chose_lvl(s, 0));
	else if (key == 'b')
	  {
	    wclear(s->game);
	    return (chose_game_mode(s, 0));
	  }
        move_chose_form(s, str, &choice);
        wrefresh(s->game);
      }
  return (chose_alum_nb(s, 0, 0, choice));
}
