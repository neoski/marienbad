int	check_sign(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
        j = -1 * j;
      else
        j = j * 1;
      i++;
    }
  return (j);
}

int	my_getnbr(char *str)
{
  int	res;
  int	i;
  int	ten;
  int	y;

  ten = 1;
  res = 0;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    i++;
  y = i;
  while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
    if (i++ != y)
      ten = ten * 10;
  while (y != i)
    {
      res = res + ((str[y++] - 48) * ten);
      ten = ten / 10;
    }
  if (check_sign(str) == -1)
    return (res * -1);
  return (res);
}
