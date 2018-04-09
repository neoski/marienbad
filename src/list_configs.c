#include <stdlib.h>
#include "allum.h"

int		list_size(t_list *list)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = list;
  while (list->next != tmp)
    {
      list = list->next;
      i++;
    }
  return (i);
}

int		delete_list(t_list **list)
{
  t_list	*temp;

  temp = (*list)->next;
  if ((*list) == (*list)->next)
    {
      free(*list);
      *list = NULL;
    }
  else
    {
      (*list)->next->prev = (*list)->prev;
      (*list)->prev->next = (*list)->next;
      free(*list);
      *list = temp;
    }
  return (0);
}

int		add_elem_next(t_list **list, int x, int y)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    my_putstr("Cannt alloc list", 2);
  elem->x = x;
  elem->y = y;
  elem->selec = 0;
  elem->pos = 0;
  elem->prev = (*list);
  (*list)->next->prev = elem;
  elem->next = (*list)->next;
  (*list)->next = elem;
  return (0);
}

int	ini_list(t_list **list, int x, int y)
{
  if ((*list = malloc(sizeof(**list))) == NULL)
    my_putstr("Cannot alloc list.\n", 2);
  (*list)->x = x;
  (*list)->y = y;
  (*list)->selec = 0;
  (*list)->pos = 1;
  (*list)->prev = *list;
  (*list)->next = *list;
  return (0);
}
