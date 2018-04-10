#include "marienbad.h"

static int	move_game_mode(t_struct *s, char **str, int key)
{
  int		i;

  i = 0;
  if (key == KEY_UP)
    {
      if (s->mode == 0)
	s->mode = 3;
      else
	--s->mode;
    }
  else if (key != 0)
    {
      if (s->mode == 3)
	s->mode = 0;
      else
	++s->mode;
    }
  while (++i != 5)
    {
      if (i - 1 == s->mode)
	print_whereami(s->game, i + 6, 6, str[i - 1]);
      else
	mvwprintw(s->game, i + 6, 6, str[i - 1]);
    }
    return (0);
}

int	chose_game_mode(t_struct *s, int key)
{
  char	*str[4];

  s->mode = 0;
  str[0] = "Player vs Player";
  str[1] = "Player vs Bot";
  str[2] = "Bot1 vs Bot2";
  str[3] = "Quit";
  mvwprintw(s->game, 4, 6, "Chose game mode :");
  mvwprintw(s->game, 14, 6, "Use directional keys to move.");
  mvwprintw(s->game, 15, 6, "Press ENTER to chose.");
  move_game_mode(s, str, 0);
  wrefresh(s->game);
  while ((key = getch()) != ENTER)
    {
      if (key == KEY_UP || key == KEY_DOWN)
	{
	  move_game_mode(s, str, key);
	  wrefresh(s->game);
	}
    }
  if (s->mode == 3)
    just_quit(s);
  chose_lvl(s, 0);
  return (0);
}
