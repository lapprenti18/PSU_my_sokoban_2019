/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

void    start_loop(char **tab)
{
    clear();
    display_map(tab);
    refresh();
}

void    before_loop(void)
{
    initscr();
    keypad(stdscr, TRUE);
}