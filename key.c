/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

void    key_up(player_s *player, char **tab, int b)
{
    if (tab[player->y - 1][player->x] != '#' && tab[player->y - 1]\
    [player->x] != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y - 1][player->x] = 'P';
    }
    if (player->y != 1 && tab[player->y - 2][player->x] != '#' && tab[player\
    ->y - 1][player->x] == 'X' && tab[player->y - 2][player->x] != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y - 1][player->x] = 'P';
        tab[player->y - 2][player->x] = 'X';
    }
}

void    key_down(player_s *player, char **tab, int b)
{
    if (tab[player->y + 1][player->x] != '#' && tab[player->y + 1][player->x] \
    != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y + 1][player->x] = 'P';
    }
    if (tab[player->y + 2] && tab[player->y + 2][player->x] != '#' && tab[\
    player->y + 1][player->x] == 'X' && tab[player->y + 2][player->x] != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y + 1][player->x] = 'P';
        tab[player->y + 2][player->x] = 'X';
    }
}

void    key_left(player_s *player, char **tab, int b)
{
    if (tab[player->y][player->x - 1] != '#' && tab[player->y][player->x - 1] \
    != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y][player->x - 1] = 'P';
    }
    if (tab[player->y][player->x - 2] != '#' && tab[player->y][player->x - 1] \
    == 'X' && tab[player->y][player->x - 2] != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y][player->x - 1] = 'P';
        tab[player->y][player->x - 2] = 'X';
    }
}

void    key_right(player_s *player, char **tab, int b)
{
    if (tab[player->y][player->x + 1] != '#' && tab[player->y][player->x + 1] \
    != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y][player->x + 1] = 'P';
    }
    if (tab[player->y][player->x + 2] != '#' && tab[player->y][player->x + 1] \
    == 'X' && tab[player->y][player->x + 2] != 'X') {
        tab[player->y][player->x] = ' ';
        tab[player->y][player->x + 1] = 'P';
        tab[player->y][player->x + 2] = 'X';
    }
}