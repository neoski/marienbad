#include "marienbad.h"

int	calc_nb_lines(t_list *tmp, t_list *list, int i)
{
  while (list->next != tmp)
    {
      if (list->y != list->next->y)
	++i;
      list = list->next;
    }
  if (list->y != list->next->y)
    ++i;
  if (i == 0)
    ++i;
  return (i);
}

int	find_biggest_al_y(t_list *tmp, t_list *list)
{
  while (list->next != tmp)
    {
      if (list->y == list->next->y)
	return (list->y);
      list = list->next;
    }
  if (list->y == list->next->y)
    return (list->y);
  return (0);
}

int	case_marienbad(t_struct *s, t_list *list)
{
  int	y;

  if (calc_nb_lines(list, list, 0) % 2 == 0)
    {
      if ((y = find_biggest_al_y(list, list)) != 0)
	return (marienbad_del(s, list, l_allum(list, y), y));
      else
	return (marienbad_del(s, list, 1, list->y));
    }
  else
    {
      if ((y = find_biggest_al_y(list, list)) != 0)
	return (marienbad_del(s, list, l_allum(list, y) - 1, y));
      else
	return (marienbad_del(s, list, 1, list->y));
    }
  return (0);
}
