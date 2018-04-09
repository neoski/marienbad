#include "allum.h"

int	key_right(t_list *list)
{
  if (list->next->y == list->y)
    list->next->pos = 1;
  else
    {
      while (list->y == list->prev->y)
	list = list->prev;
      list->pos = 1;
    }
  return (0);
}

int	key_left(t_list *list)
{
  if (list->prev->y == list->y)
    list->prev->pos = 1;
  else
    {
      while (list->y == list->next->y)
	list = list->next;
      list->pos = 1;
    }
  return (0);
}

int	move_left_right(t_struct *s, t_list *list, int key)
{
  while (list->pos != 2)
    list = list->next;
  if (key == KEY_RIGHT)
    key_right(list);
  else
    key_left(list);
  return (print_opti(s, list));
}
