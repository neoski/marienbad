#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define CHAR_READ 1000

typedef struct	s_struct
{
  char		*res;
  char		*buff;
  int		rvalue;
  int		i;
}		t_struct;

char	*check_if_new_fd(int fd, char *str, int *key);
char	*get_next_line(const int fd);
int	savedchars_to_result(char *result, char *saved_chars, int *interrupter);
char	*resultchars(t_struct *pbuff, int *interrupter, int i, int j);
char	*save_chars(char *saved_chars, t_struct *pbuff, int *k, int i);
char	*my_gnl_realloc(char *old, int i, int *interrupter);

#endif /* !GET_NEXT_LINE_H_ */
