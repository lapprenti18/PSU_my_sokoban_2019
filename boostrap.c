/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <curses.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>

int    my_strlen(char const *str);

int main (int ac, char **av)
{
    char *msg = av[1];
    int b = 0;
    int height = 0;
    int widht = 0;

    initscr();
    while (1) {
        clear();
        mvprintw((LINES/2 + height), (COLS/2 + widht) - (my_strlen(msg)/2), msg);
        refresh();
        b = getch();
        if (b == 32) {
            endwin();
            return (0);
        }
        if (b == 'z' || b == 'q' || b == 's' || b == 'd') {
            if (b == 'z') {
                height -= 1;
            }
            if (b == 'q') {
                widht -= 1;
            }
            if (b == 's') {
                height += 1;
            }
            if (b == 'd') {
                widht += 1;
            }
        }
    }
endwin();
}