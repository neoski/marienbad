#include "marienbad.h"

int		print_opti(t_struct *s, t_list *list)
{
  t_list	*temp;

  temp = list;
  while (list->next != temp)
    {
      if (list->pos == 1 || list->pos == 2 || list->selec == 1)
	config_print(s->game, list);
      list = list->next;
    }
  if (list->pos == 1 || list->pos == 2 || list->selec == 1)
    config_print(s->game, list);
  wrefresh(s->game);
  return (0);
}
