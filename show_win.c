#include <time.h>
#include "allum.h"

static int	show_winner(t_struct *s)
{
  if (s->turn == 1)
    {
      if (s->mode == 0)
        print_whereami(s->game, 4, 6, "Allum1 : Player 1 WINS !");
      if (s->mode == 1)
        print_whereami(s->game, 4, 6, "Allum1 : You WIN !");
      if (s->mode == 2)
        print_whereami(s->game, 4, 6, "Allum1 : Bot1 WINS !");
    }
  else
    {
      if (s->mode == 0)
        print_whereami(s->game, 4, 6, "Allum1 : Player 2 WINS !");
      if (s->mode == 1)
        print_whereami(s->game, 4, 6, "Allum1 : Bot WINS !");
      if (s->mode == 2)
        print_whereami(s->game, 4, 6, "Allum1 : Bot2 WINS !");
    }
  return (0);
}

int		show_win(t_struct *s, int tm)
{
  time_t	t;

  t = time(NULL);
  wclear(s->game);
  show_winner(s);
  if (t != -1 && tm != -1)
    mvwprintw(s->game, 7, 6, "Game duration : %d seconds !", t - tm);
  mvwprintw(s->game, 10, 6, "PRESS ENTER TO CONTINUE");
  wrefresh(s->game);
  while (getch() != ENTER)
    ;
  wclear(s->game);
  return (chose_game_mode(s, 0));
}
