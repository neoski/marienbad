#include <stdlib.h>
#include "allum.h"
#include "get_next_line.h"

int	show_try_again(char *str, char *res, int i)
{
  while (i == 0)
    {
      my_putstr("Try again ? (y or n) : ", 1);
      if ((res = get_next_line(0)) == NULL)
	return (my_putstr("Quit.\n", 2));
      if (res[0] == 'y' && res[1] == '\0')
	{
	  free(res);
	  return (loop(str, 1, 0));
	}
      if (res[0] == 'n' && res[1] == '\0')
	i = 1;
      else
	my_putstr("Enter y or n.\n", 1);
      free(res);
    }
  return (0);
}

int	try_again(int key)
{
  char	str[5];

  str[0] = 1;
  str[1] = 3;
  str[2] = 5;
  str[3] = 7;
  str[4] = '\0';
  if (key == 0)
    show_try_again(str, NULL, 0);
  else
    loop(str, 1, 0);
  return (0);
}
