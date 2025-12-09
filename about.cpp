#include <ncurses/curses.h>
#include <cstdlib>
#include <ctime>

void about() {

    int winH = 20;
    int winW = 50;
    int startY = (LINES - winH) / 2;
    int startX = (COLS - winW) / 2;

    WINDOW* w = newwin(winH, winW, startY, startX);
    box(w, 0, 0);
    keypad(w, TRUE);

    mvwprintw(w, 2, 2, "ABOUT GAME");
    mvwprintw(w, 4, 2, "Game ini diciptakan oleh Kelompok 7 yang");
    mvwprintw(w, 5, 2, "yang beranggotakan : ");
    mvwprintw(w, 7, 2, "   1. Gusti Made Michael Mahatma");
    mvwprintw(w, 8, 2, "   2. Nadia Putri Azzahra");
    mvwprintw(w, 9, 2, "   3. Siti Zulaika");
    mvwprintw(w, 11, 2, "game ini terinspiasi dari minigame yang ada");
    mvwprintw(w, 12, 2, "di game pou yang diusulkan dari nadia");

    mvwprintw(w, 18, 2, "Press any key to go back...");
    wrefresh(w);

    wgetch(w);
    delwin(w);
}
