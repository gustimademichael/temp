#include <ncurses/curses.h>
#include <cstdlib>
#include <ctime>

void about() {

    int winH = 15;
    int winW = 50;
    int startY = (LINES - winH) / 2;
    int startX = (COLS - winW) / 2;

    WINDOW* w = newwin(winH, winW, startY, startX);
    box(w, 0, 0);
    keypad(w, TRUE);

    mvwprintw(w, 2, 2, "ABOUT GAME");
    mvwprintw(w, 4, 2, "Lorem ipsum dolor sit amet, consectetur");
    mvwprintw(w, 5, 2, "adipiscing elit. Sed do eiusmod tempor.");
    mvwprintw(w, 6, 2, "Incididunt ut labore et dolore magna aliqua.");

    mvwprintw(w, 10, 2, "Press any key to go back...");
    wrefresh(w);

    wgetch(w);
    delwin(w);
}
