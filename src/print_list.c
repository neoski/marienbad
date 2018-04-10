#include "marienbad.h"

int	change_turn(t_struct *s)
{
  if (s->turn == 1)
    {
      if (s->mode == 0)
	print_whereami(s->game, 3, 15, "Player 1");
      if (s->mode == 1)
	print_whereami(s->game, 3, 15, "Your Turn");
      if (s->mode == 2)
	print_whereami(s->game, 3, 15, "Bot1 is thinking");
      s->turn = 2;
    }
  else
    {
      if (s->mode == 0)
        print_whereami(s->game, 3, 15, "Player 2");
      if (s->mode == 1)
	print_whereami(s->game, 3, 15, "Bot is thinking");
      if (s->mode == 2)
	print_whereami(s->game, 3, 15, "Bot2 is thinking");
      s->turn= 1;
    }
  return (0);
}

int	config_print(WINDOW *w, t_list *list)
{
  if (list->pos == 2)
    list->pos = 0;
  if (list->pos == 0 && list->selec == 0)
    mvwprintw(w, list->y, list->x, "|");
  else if (list->pos == 0)
    print_videorev(w, list->y, list->x, "|");
  if (list->pos == 1)
    {
      if (list->selec == 0)
	print_whereami_notselect(w, list->y, list->x, "|");
      else
	print_whereami(w, list->y, list->x, "|");
      list->pos = 2;
    }
  return (0);
}

int		print_list(t_struct *s, t_list *list, int i)
{
  t_list	*temp;

  wclear(s->game);
  mvwprintw(s->game, 3, 3, "Marienbad :");
  if (s->mode != 2)
    {
      mvwprintw(s->game, 19, 4, "Use directional keys to move.");
      mvwprintw(s->game, 20, 4, "Press SPACE to select matches on a line.");
      mvwprintw(s->game, 21, 4, "Press ENTER to delete selected matches.");
      /*mvwprintw(s->game, 22, 4, "Press s to take a screenshot.");*/
    }
  else
    mvwprintw(s->game, 19, 4, "Bots are playing. Have fun as watching ! :D");
  temp = list;
  while (list->next != temp)
    {
      config_print(s->game, list);
      list = list->next;
    }
  config_print(s->game, list);
  if (i != 1)
    change_turn(s);
  wrefresh(s->game);
  return (0);
}
