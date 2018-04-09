int	calc_nb_lines(char *str, int i, int y)
{
  while (y != 4)
    {
      if (str[y] > 0)
	++i;
      ++y;
    }
  return (i);
}

int	marien_del(char *str, int *line, int *nb, int key)
{
  int	y;

  y = 0;
  if (key == 0)
    {
      while (y < 4)
	if (str[y++] > 1)
	  {
	    *line = y;
	    *nb = str[y - 1];
	    return (1);
	  }
    }
  else
    while (y < 4)
      if (str[y++] > 1)
	{
	  *line = y;
	  *nb = str[y - 1] - 1;
	  return (1);
	}
  return (0);
}

int	case_marienbad(char *str, int *line, int *nb, int key)
{
  int	y;
  int	linenb;

  y = 0;
  if (key == 0)
    {
      linenb = calc_nb_lines(str, 0, 0) % 2;
      if (linenb == 0 && marien_del(str, line, nb, 0) == 1)
	return (0);
      if (linenb != 0 && marien_del(str, line, nb, 1) == 1)
	return (0);
    }
  while (y != 4)
    if (str[y++] > 0)
      {
	*line = y;
	*nb = 1;
      }
  return (0);
}

int	check_if_one_per_line(char *str, int i, int y)
{
  while (y != 4)
    {
      if (str[y] > 1)
	++i;
      ++y;
    }
  return (i);
}

int	marienbad(char *str, int *line, int *nb, int i)
{
  int	y;

  y = 0;
  i = str[0] ^ str[1] ^ str[2] ^ str[3];
  if (check_if_one_per_line(str, 0, 0) <= 1)
    return (case_marienbad(str, line, nb, 0));
  if (i == 0)
    return (case_marienbad(str, line, nb, 1));
  while (y < 4)
    {
      if (str[y] > 0 && (str[y] ^ i) < str[y])
	{
	  *line = y + 1;
	  *nb = str[y] - (str[y] ^ i);
	  return (0);
	}
      ++y;
    }
  return (0);
}
