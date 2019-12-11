/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

char    **my_str_to_word_array(char *str);
char    *fill(char **av);

void    display_map(char **tab)
{
    for (int i = 0; tab[i] != NULL; i += 1) {
        mvprintw(i, 0, tab[i]);
    }
}

void    player_pos(player_s *player, char **tab)
{
    int a = 0;

    for (int i = 0; tab[i]; i += 1) {
        for (a = 0; tab[i][a] != 'P' && tab[i][a] != '\0'; a += 1);
        if (tab[i][a] == 'P') {
            player->x = a;
            player->y = i;
        }
    }
}
void move_p(player_s player, char **tab, int b)
{
    if (b == KEY_UP) {
        if (tab[player.y - 1][player.x] != '#' && tab[player.y - 1][player.x] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y - 1][player.x] = 'P';
        }
        if (player.y != 1 && tab[player.y - 2][player.x] != '#' && tab[player.y - 1][player.x] == 'X' && tab[player.y - 2][player.x] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y - 1][player.x] = 'P';
            tab[player.y - 2][player.x] = 'X';
        }
    }
    if (b == KEY_DOWN) {
        if (tab[player.y + 1][player.x] != '#' && tab[player.y + 1][player.x] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y + 1][player.x] = 'P';
        }
        if (tab[player.y + 2] && tab[player.y + 2][player.x] != '#' && tab[player.y + 1][player.x] == 'X' && tab[player.y + 2][player.x] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y + 1][player.x] = 'P';
            tab[player.y + 2][player.x] = 'X';
        }
    }
    if (b == KEY_LEFT) {
        if (tab[player.y][player.x - 1] != '#' && tab[player.y][player.x - 1] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y][player.x - 1] = 'P';
        }
        if (tab[player.y][player.x - 2] != '#' && tab[player.y][player.x - 1] == 'X' && tab[player.y][player.x - 2] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y][player.x - 1] = 'P';
            tab[player.y][player.x - 2] = 'X';
        }
    }
    if (b == KEY_RIGHT) {
        if (tab[player.y][player.x + 1] != '#' && tab[player.y][player.x + 1] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y][player.x + 1] = 'P';
        }
        if (tab[player.y][player.x + 2] != '#' && tab[player.y][player.x + 1] == 'X' && tab[player.y][player.x + 2] != 'X') {
            tab[player.y][player.x] = ' ';
            tab[player.y][player.x + 1] = 'P';
            tab[player.y][player.x + 2] = 'X';
        }
    }
    if (b == 32) {
        endwin();
        return;
    }
}

int    nb_of_o(char **tab)
{
    int a = 0;
    int o = 0;

    for (int i = 0; tab[i]; i += 1) {
        for (a = 0;tab[i][a] != '\0'; a += 1) {
            if (tab[i][a] == 'O')
                o += 1;
        }
    }
    return (o);
}

void    check_o(char **tab, int **tab_o, player_s *player)
{
    for (int i = 0; i < player->nb_o; i += 1) {
        if (tab[tab_o[i][0]][tab_o[i][1]] == ' ')
            tab[tab_o[i][0]][tab_o[i][1]] = 'O';
    }
}

int    check_win(char **tab, int **tab_o, player_s *player, int test)
{
    int a = 0;

    for (int i = 0; i < player->nb_o; i += 1) {
        if (tab[tab_o[i][0]][tab_o[i][1]] == 'X')
            a += 1;
    }
    if (a == player->nb_o)
        return (1);
    return (test);
}

int    check_x_blocked(char **tab, int i, int a)
{
    if (tab[i][a + 1] == '#' && tab[i + 1][a] == '#')
        return (1);
    if (tab[i][a + 1] == '#' && tab[i - 1][a] == '#')
        return (1);
    if (tab[i][a - 1] == '#' && tab[i + 1][a] == '#')
        return (1);
    if (tab[i][a - 1] == '#' && tab[i - 1][a] == '#')
        return (1);
    return (0);
}

int    check_loose(char **tab, int **tab_o, player_s *player, int test)
{
    int a = 0;
    int h = 0;
    int temp = 0;

    for (int i = 0; tab[i]; i += 1) {
        for (a = 0;tab[i][a] != '\0'; a += 1) {
            if (tab[i][a] == 'X')
                h += check_x_blocked(tab, i, a);
        }
    }
    if (h == player->nb_o)
        return (2);
    return (test);
}

char    **reset_map(char **av)
{
    char *map = fill(av);
    char **tab = my_str_to_word_array(map);

    return (tab);
}

int    loop(char **tab, int **o_pos, char **av)
{
    int b = 0;
    player_s player;
    int test;

    player.nb_o = nb_of_o(tab);
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        display_map(tab);
        refresh();
        b = getch();
        if (b == 32)
            tab = reset_map(av);
        player_pos(&player, tab);
        move_p(player, tab, b);
        test = check_loose(tab, o_pos, &player, test);
        test = check_win(tab, o_pos, &player, test);
        check_o(tab, o_pos, &player);
        if (test == 1 || test == 2)
            break;
    }
    endwin();
    return (test);
}

int **tab_o(char **tab)
{

    int o = nb_of_o(tab);
    int a = 0;
    int **tab_o;
    int repere = 0;

    tab_o = malloc(sizeof(int *) * o);
    for (int i = 0; i < o; i += 1)
        tab_o[i] = malloc(sizeof(int) * 2);
    for (int i = 0; tab[i]; i += 1) {
        for (a = 0; tab[i][a]; a += 1) {
            if (tab[i][a] == 'O') {
                tab_o[repere][0] = i;
                tab_o[repere][1] = a;
                repere += 1;
            }
        }
    }
    return (tab_o);
}

int main (int ac, char **av)
{
    char *map = fill(av);
    char **tab = my_str_to_word_array(map);
    int **o_pos = tab_o(tab);
    int win;

    win = loop(tab, o_pos, av);
    if (win == 2)
        return (1);
    return (0);
}