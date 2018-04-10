#include "marienbad.h"

int		build_list_rectangle(t_struct *s, int x, int y, int max)
{
  t_list	*list;
  int		tmp;

  tmp = x + 1;
  ini_list(&list, tmp - s->al_per_line, y);
  while (max++ < s->line)
    {
      x = tmp - s->al_per_line;
      if (y == YMIN)
	x += 2;
      while (x < tmp)
	{
	  add_elem_next(&list, x, y);
	  list = list->next;
	  x += 2;
	}
	while (x < tmp + s->al_per_line)
	  {
	    add_elem_next(&list, x, y);
	    list = list->next;
	    x += 2;
	  }
	++y;
    }
  return (game_prep(s, list->next));
}

int		build_list(t_struct *s, int x, int y, int max)
{
  t_list	*list;
  int		tmp;
  int		i;

  ini_list(&list, x, y++);
  i = x;
  tmp = x;
  while (max != s->line)
    {
      x = tmp - 2;
      while (x <= i + 2)
	{
	  add_elem_next(&list, x, y);
	  list = list->next;
	  x += 2;
	}
      i += 2;
      tmp -= 2;
      ++y;
      ++max;
    }
  list = list->next;
  return (game_prep(s, list));
}
