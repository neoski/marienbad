#include <unistd.h>
#include "allum.h"

int		l_allum(t_list *list, int y)
{
  t_list	*tmp;
  int		i;

  i = 0;
  if (list == list->next && list->y != y)
    return (0);
  else if (list == list->next)
    return (1);
  tmp = list;
  while (list->y == list->prev->y && list->next != tmp)
    list = list->next;
  tmp = list;
  while (list->y != y && list->next != tmp)
    list = list->next;
  tmp = list;
  while (list->y == y && list->next != tmp)
    {
      ++i;
      list = list->next;
    }
  if (list->next == tmp && list->y == y)
    ++i;
  return (i);
}

int	marienbad_del(t_struct *s, t_list *list, int i, int y)
{
  usleep(500000);
  while (i > 0)
    {
      if (list->y == y)
	{
	  list->selec = 1;
	  --i;
	}
      list = list->next;
    }
  print_opti(s, list);
  usleep(250000);
  return (0);
}

int	check_if_one_per_line(t_list *list, t_list *tmp, int i)
{
  int	j;

  j = 0;
  while (list->next != tmp)
    {
      if (list->y == list->prev->y)
	{
	  if (list->y != j)
	    ++i;
	  j = list->y;
	}
      list = list->next;
    }
  if (list->y == list->prev->y && list->y != j)
    ++i;
  return (i);
}

int	marienbad(t_struct *s, t_list *list, int i, int y)
{
  while (y < YMAX)
    i ^= l_allum(list, y++);
  y = YMIN;
  if (list == list->next)
    return (marienbad_del(s, list, 1, list->y));
  if (check_if_one_per_line(list, list, 0) <= 1)
    return (case_marienbad(s, list));
  if (i > 0)
    while (y < YMAX)
      {
	if (l_allum(list, y) > 0 && (l_allum(list, y) ^ i) < l_allum(list, y))
	  return (marienbad_del(s, list, l_allum(list, y) -
				(i ^ l_allum(list, y)), y));
	++y;
      }
  y = YMIN;
  return (marienbad_del(s, list, 1, list->y));
}
