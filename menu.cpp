#include <ncurses/curses.h>
#include <cstdlib>

int menu() {

    int winH = 25;
    int winW = 75;
    int startY = (LINES - winH) / 2;
    int startX = (COLS - winW) / 2;

    WINDOW* w = newwin(winH, winW, startY, startX);
    keypad(w, TRUE);
    curs_set(0);

    // Warna
    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_RED,    COLOR_BLACK);   // merah
        init_pair(2, COLOR_WHITE,  COLOR_BLACK);   // putih
        init_pair(3, COLOR_CYAN,   COLOR_BLACK);   // teks menu
        init_pair(4, COLOR_YELLOW, COLOR_BLACK);   // highlight
    }

    int highlight = 0;
    const char* choices[3] = {"Play", "About", "Exit"};

    // ASCII
    const char* line1 = "    __ __ ____________________  _______  __    __  ___   ________ ";
    const char* line2 = "   / //_// ____/ ____/ ____/  |/  / __ \\/ /   / / / / | / / ____/ ";
    const char* line3 = "  / ,<  / __/ / /   / __/ / /|_/ / /_/ / /   / / / /  |/ / / __    ";
    const char* line4 = " / /| |/ /___/ /___/ /___/ /  / / ____/ /___/ /_/ / /|  / /_/ /   ";
    const char* line5 = "/_/ |_/_____/\\____/_____/_/  /_/_/   /_____/\\____/_/ |_/\\____/    ";

    while (true) {
        werase(w);
        box(w, 0, 0);

        // ===============================
        // ASCII ART WARNA MERAH (baris atas)
        // ===============================
        wattron(w, COLOR_PAIR(1));
        mvwprintw(w, 1, 3, "%s", line1);
        mvwprintw(w, 2, 3, "%s", line2);
        wattroff(w, COLOR_PAIR(1));

        // Baris tengah (putih)
        wattron(w, COLOR_PAIR(1));
        mvwprintw(w, 3, 3, "%s", line3);
        wattroff(w, COLOR_PAIR(1));

        // Dua baris bawah (putih)
        wattron(w, COLOR_PAIR(2));
        mvwprintw(w, 4, 3, "%s", line4);
        mvwprintw(w, 5, 3, "%s", line5);
        wattroff(w, COLOR_PAIR(2));

        // ===============================
        // MENU
        // ===============================
        for (int i = 0; i < 3; i++) {

            wattron(w, COLOR_PAIR(3));

            if (i == highlight) {
                wattron(w, A_REVERSE);
                wattron(w, COLOR_PAIR(4));
            }

            mvwprintw(w, 10 + i, winW / 2 - 4, "%s", choices[i]);

            if (i == highlight) {
                wattroff(w, COLOR_PAIR(4));
                wattroff(w, A_REVERSE);
            }

            wattroff(w, COLOR_PAIR(3));
        }

        wrefresh(w);

        int ch = wgetch(w);

        if (ch == KEY_UP || ch == 'w' || ch == 'W') {
            highlight--;
            if (highlight < 0) highlight = 2;
        }
        else if (ch == KEY_DOWN || ch == 's' || ch == 'S') {
            highlight++;
            if (highlight > 2) highlight = 0;
        }
        else if (ch == '\n') {
            delwin(w);
            return highlight;
        }
    }
}
