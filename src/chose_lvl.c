#include "marienbad.h"

static int	move_game_lvl(t_struct *s, char **str, int key)
{
  int		i;

  i = 0;
  if (key == KEY_UP)
    {
      if (s->lvl == 0)
        s->lvl = 2;
      else
        --s->lvl;
    }
  else if (key != 0)
    {
      if (s->lvl == 2)
	s->lvl = 0;
      else
	++s->lvl;
    }
  while (++i != 4)
    {
      if (i - 1 == s->lvl)
        print_whereami(s->game, i + 6, 6, str[i - 1]);
      else
        mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
  return (0);
}

static int	print_chose_lvl(t_struct *s)
{
  mvwprintw(s->game, 4, 6, "Chose game difficulty :");
  mvwprintw(s->game, 14, 6, "Use directional keys to move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to chose.");
  mvwprintw(s->game, 16, 6, "Press b to go back.");
  return (0);
}

int	chose_lvl(t_struct *s, int key)
{
  char	*str[3];

  wclear(s->game);
  s->lvl = 0;
  str[0] = "Easy";
  str[1] = "Medium";
  str[2] = "Hard";
  print_chose_lvl(s);
  move_game_lvl(s, str, 0);
  wrefresh(s->game);
  while (s->mode != 0 && (key = getch()) != ENTER)
    if (key == KEY_UP || key == KEY_DOWN || key == 'b')
      {
	if (key == 'b')
	  {
	    wclear(s->game);
	    return (chose_game_mode(s, 0));
	  }
	move_game_lvl(s, str, key);
	wrefresh(s->game);
      }
  chose_game_structure(s, 0, 1);
  return (0);
}
