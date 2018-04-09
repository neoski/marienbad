/*
** case_marienbad.c for case_marienbad in /home/stoilo_s/CPE_2014_allum1
** 
** Made by sebastien stoilov
** Login   <stoilo_s@epitech.net>
** 
** Started on  Tue Feb 17 20:41:32 2015 sebastien stoilov
** Last update Wed Feb 18 05:28:29 2015 sebastien stoilov
*/

#include "allum.h"

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
