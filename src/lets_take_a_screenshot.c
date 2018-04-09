#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "allum.h"

static int	show_top(t_struct *s)
{
  mvwprintw(s->game, 7, 4, "Enter file name and extension (ex : name.jpg)");
  mvwprintw(s->game, 8, 4, "File name (max 17 carac) : ");
  mvwprintw(s->game, 10, 4, "letters, numbers, ._- supported");
  mvwprintw(s->game, 12, 4, "Use Backspace to del a character.");
  mvwprintw(s->game, 13, 4, "PRESS ENTER TO CONFIRM.");
  mvwprintw(s->game, 14, 4, "Then use the mouse to screenshot.");
  wrefresh(s->game);
  return (0);
}

int	get_file_name(t_struct *s, char *str, int key, int i)
{
  str[0] = 0;
  show_top(s);
  while ((key = getch()) != ENTER || i == 0)
    {
      if (key == KEY_BACKSPACE && i > 0)
	str[--i] = '\0';
      if (i < 17 && ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')
		     || (key >= '0' && key <= '9') || key == '.' || key == '-'
		     || key == '_'))
	{
	  str[i++] = key;
	  str[i] = 0;
	}
      if (i < 18 && ((key >= 'A' &&  key <= 'Z') ||
		     (key >= 'a' && key <= 'z') ||
		     (key >= '0' && key <= '9') ||
		     key == '.' || key == '-' || key == '_' ||
		     key == KEY_BACKSPACE))
	{
	  wclear(s->game);
	  print_screenshot(s->game, str);
	  show_top(s);
	}
    }
  return (0);
}

int	my_strcpy(char *scr, char *wanted, int i)
{
  int	y;

  y = 0;
  while (wanted[y++])
    scr[i++] = wanted[y - 1];
  scr[i] = '\0';
  return (0);
}

int	do_screenshot(char **str, int i)
{
  pid_t	pid;

  return (0); /* make sure you have the built-in import if you want to use this functionality */
  if ((pid = fork()) == -1)
    return (0);
  if (pid == 0 && execvp(str[0], str) == -1)
    return (0);
  if (waitpid(pid, &i, 0) == -1)
    return (0);
  return (0);
}

int	lets_take_a_screenshot(t_struct *s, t_list *list)
{
  int	i;
  char	**str;

  if ((str = my_double_malloc(NULL, 2, 20)) == NULL)
    return (my_putstr("Couldn't alloc memory.", 2));
  my_strcpy(str[0], "import", 0);
  str[2] = NULL;
  i = 0;
  wclear(s->game);
  get_file_name(s, str[1], 0, 0);
  while (list->pos != 2)
    list = list->next;
  list->pos = 1;
  print_list(s, list, 1);
  do_screenshot(str, 0);
  print_whereami(s->game, 7, 10, "Screenshot saved. Back to game.");
  wrefresh(s->game);
  sleep(2);
  while (list->pos != 2)
    list = list->next;
  list->pos = 1;
  print_list(s, list, 1);
  my_double_free(str);
  return (0);
}
