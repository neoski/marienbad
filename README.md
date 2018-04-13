# marienbad

You can find here a marienbad game (called also NIM) coded in C language with 3 different AI lvl (easy, medium, hard) with the ncurses library.

<img alt="Marienbad demo" src="https://thumbs.gfycat.com/ScaredSpicyBactrian-size_restricted.gif" height="330px"/>

I coded this project during my studies, basically the aim was to create a text-version marienbad with an IA. I went further and made it more user-friendly with a better graphical approach using the ncurses library and added other features including 3 IAS lvl, 3 games mode (Player vs IA, Player vs Player, IA vs IA), 2 different game structures (Rectange/Pyramid), the choice of the structure size, screenshots (for fun, with a `fork`/`execvp` on `import`), menus and game duration.

I also made in pararell the basic mandatory text-version which is accessible in the repository `text-version`.

**Requirements :**

make

gcc

**Usage :**

1. git clone https://github.com/neoski/marienbad.git

2. cd marienbad && make

3. ./marienbad

*Note : The current ncurses library path used for the compilation works for MAC OS X.
It's possible that you might need to change it depending of its location.
You can find it by typing `man curses` on your shell.
Then replace `# include <ncurses.h>` and `# include <curses.h>` by the good path in `include/allum.h`.*


**Author :** Sebastien S.

**Github repository :** https://github.com/neoski/marienbad.

Made during my studies in february 2015.
