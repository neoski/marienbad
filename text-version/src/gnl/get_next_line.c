#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*my_gnl_realloc(char *old, int i, int *interrupter)
{
  int	y;
  char	*new;

  y = 0;
  if (*interrupter != 2)
    if ((new = malloc(CHAR_READ + i + 1)) == NULL)
      return (NULL);
  if (i != 0)
    {
      while (old[y++])
	new[y - 1] = old[y - 1];
      new[y - 1] = '\0';
      free(old);
    }
  return (new);
}

char	*resultchars(t_struct *p, int *interrupter, int j, int y)
{
  if ((p->rvalue == -1) || (p->rvalue == 0 && p->res[0] == '\0')
      || (p->buff && p->buff[0] == '\0'))
    {
      free(p->buff);
      free(p->res);
      return (NULL);
    }
  if (p->i != 0 && p->rvalue != 0)
    if ((p->res = my_gnl_realloc(p->res, p->i, interrupter)) == NULL)
      {
	free(p->buff);
	return (NULL);
      }
  while (p->i != y + p->rvalue && p->buff[j] != '\n')
    p->res[p->i++] = p->buff[j++];
  p->res[p->i] = '\0';
  if (p->rvalue != CHAR_READ)
    *interrupter = 2;
  if (p->i != y + p->rvalue)
    *interrupter = 3;
  else
    free(p->buff);
  return (p->res);
}

int		savedchars_to_result(char *result, char *saved_chars, int *key)
{
  static int	y;
  int		i;

  i = 0;
  if (*key != 4)
    y = 0;
  while (saved_chars[y] != '\0' && saved_chars[y] != '\n')
    result[i++] = saved_chars[y++];
  result[i] = '\0';
  if (saved_chars[y] == '\n')
    {
      *key = 4;
      y++;
    }
  else
    {
      free(saved_chars);
      *key = 0;
    }
  return (i);
}

char	*save_chars(char *saved_chars, t_struct *pget, int *interrupter, int i)
{
  int	j;

  j = 0;
  if ((saved_chars = malloc(CHAR_READ + 1)) == NULL)
    return (NULL);
  while (pget->buff[j] != '\n')
    j++;
  j++;
  while (j != pget->rvalue)
    saved_chars[i++] = pget->buff[j++];
  saved_chars[i] = '\0';
  *interrupter = 1;
  free(pget->buff);
  return (saved_chars);
}

char		*get_next_line(const int fd)
{
  static char	*saved_chars;
  static int	key;
  t_struct	get;
  t_struct	*pget;

  get.i = 0;
  pget = &get;
  get.rvalue = CHAR_READ;
  if ((pget->res = check_if_new_fd(fd, pget->res, &key)) == NULL)
    return (NULL);
  if (key == 1 || key == 4)
    get.i = savedchars_to_result(pget->res, saved_chars, &key);
  while (key == 0 && get.rvalue == CHAR_READ)
    {
      if ((pget->buff = my_gnl_realloc(pget->buff, 0, &key)) == NULL)
	return (NULL);
      pget->rvalue = read(fd, pget->buff, CHAR_READ);
      if ((pget->res = resultchars(pget, &key, 0, pget->i)) == NULL)
	return (NULL);
      get.i = get.i + CHAR_READ;
    }
  if (key == 3)
    if ((saved_chars = save_chars(saved_chars, pget, &key, 0)) == NULL)
      return (NULL);
  return (pget->res);
}
