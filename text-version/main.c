#include <stdlib.h>
#include "allum.h"
#include "get_next_line.h"

int	get_line(char *str, int key, int nb)
{
  char	*res;

  while (key == 0)
    {
      print_nb_min_max_line(str, 0);
      if ((res = get_next_line(0)) == NULL)
	return (my_putstr("Quit.\n", 2));
      if ((nb = my_getnbr(res)) > 0 && nb < 5 && str[nb - 1] != 0)
	key = 1;
      else
	{
	  if (nb <= 0 || nb > 4)
	    my_putstr("Error : Incorrect line.\n", 2);
	  else
	    my_putstr("Error : Empty line.\n", 2);
	}
      free(res);
    }
  return (nb);
}

int	get_nb(char *str, int line, int key, int nb)
{
  char	*res;

  while (key == 0)
    {
      my_putstr("Chose allum nb to del (min 1, max ", 1);
      my_putchar(str[line - 1] + 48);
      my_putstr(") : ", 1);
      if ((res = get_next_line(0)) == NULL)
        return (my_putstr("Quit.\n", 2));
      if ((nb = my_getnbr(res)) > 0 && nb <= str[line - 1])
        key = 1;
      else
	my_putstr("Error : Incorrect nb.\n", 2);
      free(res);
    }
  return (nb);
}

int	del_elem(char *str, int *lock, int line, int nb)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  str[line - 1] = str[line - 1] - nb;
  while (i != 4)
    {
      if (str[i] > 0)
	++y;
      ++i;
    }
  if (y == 0)
    *lock = 1;
  return (0);
}

int	loop(char *str, int turn, int lock)
{
  int	line;
  int	nb;

  print_allum(str, &turn, 0, 0);
  while (lock != 1)
    {
      if (turn == 2)
	{
	  if ((line = get_line(str, 0, 0)) == -1)
	    return (0);
	  if ((nb = get_nb(str, line, 0, 0)) == -1)
	    return (0);
	  del_elem(str, &lock, line, nb);
	}
      else
	{
	  my_putstr("Bot is playing..\n", 1);
	  marienbad(str, &line, &nb, 0);
	  del_elem(str, &lock, line, nb);
	}
      if (lock != 1)
	print_allum(str, &turn, 0, 0);
    }
  show_win(turn);
  return (try_again(0));
}

int	main()
{
  try_again(1);
  return (-1);
}
