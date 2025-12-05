#include <ncurses/curses.h>
#include <cstdlib>
#include "menu.cpp"
#include "about.cpp"
#include "play.cpp"

int main() {
    initscr();
    noecho();
    cbreak();
    curs_set(0);
    srand(time(nullptr));

    while (true) {
        int pilih = menu();   // 0=Play, 1=About, 2=Exit

        if (pilih == 0) {
            play();
        } 
        else if (pilih == 1) {
            about();
        } 
        else if (pilih == 2) {
            break;
        }
    }

    endwin();
    return 0;
}
