#include <marienbad.h>

char	**my_double_malloc(char **str, int sizeb, int size)
{
  int	i;

  i = 0;
  if (sizeb == -1 || size == -1)
    return (NULL);
  if ((str = malloc(sizeb * sizeof(char *) + 9)) == NULL)
    return (NULL);
  while (i != sizeb)
    {
      if ((str[i] = malloc(size + 1)) == NULL)
	{
	  free(str);
	  return (NULL);
	}
      i = i + 1;
    }
  str[i] = NULL;
  return (str);
}

int	my_double_free(char **str)
{
  int	i;

  i = 0;
  while (str[i] != NULL)
    free(str[i++]);
  free(str);
  return (0);
}
