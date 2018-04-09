#ifndef ALLUM_H_
# define ALLUM_H_

int	try_again(int key);
int	my_getnbr(char *str);
int	marienbad(char *str, int *line, int *nb, int i);
int	loop(char *str, int turn, int lock);
int	show_win(int turn);
int	my_putchar(char c);
int	print_nb_min_max_line(char *str, int y);
int	print_allum(char *str, int *turn, int tmp, int space);
int	my_putstr(char *str, int output);

#endif /* !ALLUM_H_ */
