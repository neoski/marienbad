# marienbad

You can find here a marienbad game (called also NIM) encoded in C language with 3 bots lvl (easy, medium, hard).

There is a text version in the repository `text-version`.

**Requirements :**

gcc

**Usage :**

1. git clone https://github.com/neoski/marienbad.git

2. cd marienbad && make

3. ./marienbad

Note : The current ncurses library path used for the compilation works for MAC OS X.
It's possible that you might need to change it depending of its location.
You can find it by typing `man curses` on your shell.
Then replace `# include <ncurses.h>` and `# include <curses.h>` by the good path in `include/allum.h`.


Author : Sebastien S.

Github repository : https://github.com/neoski/marienbad.

Made in february 2015.
