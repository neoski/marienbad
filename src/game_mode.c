#include "allum.h"

int	player_vs_player(t_struct *s, t_list *list, int key, int lock)
{
  while (lock != 3 && (key = getch()))
    if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
	key == KEY_RIGHT || key == SPACE || key == ENTER || key == 's')
      {
	if ((key == KEY_UP || key == KEY_DOWN) && lock != 2)
	  move_up_down(s, list, key);
	      if (key == KEY_LEFT || key == KEY_RIGHT)
		move_left_right(s, list, key);
	      if (key == SPACE)
		select_pos(s, list, &lock);
	      if (key == ENTER)
		delete_selected(s, &list, &lock);
	      if (key == 's')
		lets_take_a_screenshot(s, list);
      }
  return (0);
}

void	player_vs_bot(t_struct *s, t_list *list, int key, int lock)
{
  while (lock != 3)
    if (s->turn == 2)
      {
	while (lock != 3 && s->turn == 2 && (key = getch()))
	  if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT ||
	      key == KEY_RIGHT || key == SPACE || key == ENTER || key == 's')
	    {
	      if ((key == KEY_UP || key == KEY_DOWN) && lock != 2)
		move_up_down(s, list, key);
	      if (key == KEY_LEFT || key == KEY_RIGHT)
		move_left_right(s, list, key);
	      if (key == SPACE)
		select_pos(s, list, &lock);
	      if (key == ENTER)
		delete_selected(s, &list, &lock);
	      if (key == 's')
                lets_take_a_screenshot(s, list);
	    }
      }
    else
      {
	lock = 1;
	lvl_check(s, list);
	delete_selected(s, &list, &lock);
      }
}

int	bot_vs_bot(t_struct *s, t_list *list, int lock)
{
  while (lock != 3)
    {
      if (s->turn == 2)
	{
	  lock = 1;
	  lvl_check(s, list);
	  delete_selected(s, &list, &lock);
	}
      else
	{
	  lock = 1;
          lvl_check(s, list);
          delete_selected(s, &list, &lock);
	}
    }
  return (0);
}
