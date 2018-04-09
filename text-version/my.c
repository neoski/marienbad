#include <stdlib.h>
#include <unistd.h>
#include "allum.h"

int	show_win(int turn)
{
  if (turn == 1)
    my_putstr("You win.\n", 1);
  else
    my_putstr("Bot wins.\n", 1);
  return (0);
}

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	print_nb_min_max_line(char *str, int y)
{
  while (str[y] == 0)
    ++y;
  my_putstr("Chose line (min ", 1);
  my_putchar(y + 49);
  my_putstr(", max ", 1);
  y = 3;
  while (str[y] == 0)
    --y;
  my_putchar(y + 49);
  my_putstr(") : ", 1);
  return (0);
}

int	print_allum(char *str, int *turn, int tmp, int space)
{
  int	i;

  if (*turn == 1)
    *turn = 2;
  else
    *turn = 1;
  i = 0;
  while (i != 4)
    {
      tmp = str[i];
      space = 7 - tmp;
      while (space-- > 0)
	my_putchar(' ');
      while (tmp-- > 0)
	my_putstr("| ", 1);
      my_putchar('\n');
      ++i;
    }
  return (0);
}

int	my_putstr(char *str, int output)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    ++i;
  write(output, str, i);
  if (output == 2)
    return (-1);
  return (0);
}
