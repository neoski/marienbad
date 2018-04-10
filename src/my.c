#include <unistd.h>
#include "marienbad.h"

int	my_putstr(char *str, int output)
{
  int	i;

  i = 0;
  while (str[i])
    ++i;
  if (output == 2)
    endwin();
  write(output, str, i);
  if (output == 2)
    exit(0);
  return (0);
}
