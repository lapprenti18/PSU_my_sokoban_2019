/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

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

void    move_p(player_s player, char **tab, int b)
{
    if (b == KEY_UP)
        key_up(&player, tab, b);
    if (b == KEY_DOWN)
        key_down(&player, tab, b);
    if (b == KEY_LEFT)
        key_left(&player, tab, b);
    if (b == KEY_RIGHT)
        key_right(&player, tab, b);
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