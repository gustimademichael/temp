#include <ncurses/curses.h>
#include <cstdlib>
//#include <ctime>

void play() {

    int winH = 25;
    int winW = 40;

    int startY = (LINES - winH) / 2;
    int startX = (COLS  - winW) / 2;

    WINDOW* win = newwin(winH, winW, startY, startX);
    keypad(win, TRUE);
    nodelay(win, TRUE);

    // aktifkan warna jika tersedia
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);  // bintang
        init_pair(2, COLOR_GREEN,  COLOR_BLACK);  // player
        init_pair(3, COLOR_CYAN,   COLOR_BLACK);  // score
        init_pair(4, COLOR_RED,    COLOR_BLACK);  // life
        init_pair(5, COLOR_MAGENTA, COLOR_BLACK); // game over
    }

    int playerX = winW / 2 - 3;
    int playerY = winH - 2;

    int starX = rand() % (winW - 2) + 1;
    int starY = 1;

    int score = 0;
    int life = 3;

    while (true) {
        werase(win);
        box(win, 0, 0);

        // Score warna cyan
        wattron(win, COLOR_PAIR(3));
        mvwprintw(win, 0, 2, "Score: %d", score);
        wattroff(win, COLOR_PAIR(3));

        // Life warna merah
        wattron(win, COLOR_PAIR(4));
        mvwprintw(win, 0, winW - 12, "Life: %d", life);
        wattroff(win, COLOR_PAIR(4));

        // Player warna hijau
        wattron(win, COLOR_PAIR(2));
        mvwprintw(win, playerY, playerX, "[=====]");
        wattroff(win, COLOR_PAIR(2));

        // Bintang warna kuning
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, starY, starX, "O");
        wattroff(win, COLOR_PAIR(1));

        wrefresh(win);

        starY++;
        if (starY >= playerY) {
            if (starX >= playerX && starX <= playerX + 6)
                score++;
            else {
                life--;
                if (life <= 0) break;
            }

            starX = rand() % (winW - 2) + 1;
            starY = 1;
        }

        int ch = wgetch(win);
        if (ch == 'q') break;

        if ((ch == KEY_LEFT || ch == 'a') && playerX > 1)
            playerX--;
        if ((ch == KEY_RIGHT || ch == 'd') && playerX + 6 < winW - 1)
            playerX++;

        napms(120);
    }

    werase(win);
    box(win, 0, 0);

    // Teks GAME OVER warna magenta
    wattron(win, COLOR_PAIR(5));
    mvwprintw(win, winH/2, winW/2 - 5, "GAME OVER");
    wattroff(win, COLOR_PAIR(5));

    // Final score warna cyan
    wattron(win, COLOR_PAIR(3));
    mvwprintw(win, winH/2 + 1, winW/2 - 7, "Final Score: %d", score);
    wattroff(win, COLOR_PAIR(3));

    wrefresh(win);
    napms(2000);

    delwin(win);
}
