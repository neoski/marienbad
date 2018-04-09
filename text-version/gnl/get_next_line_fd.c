#include <stdlib.h>
#include "get_next_line.h"

char		*check_if_new_fd(int fd, char *str, int *key)
{
  static int	new = 0;

  if (new == 0)
    new = fd;
  else if (new != fd)
    {
      new = fd;
      *key = 0;
    }
  if (*key == 2 || ((str = my_gnl_realloc(str, 0, key))) == NULL)
    return (NULL);
  if (new != fd)
    {
      new = fd;
      *key = 0;
    }
  return (str);
}
