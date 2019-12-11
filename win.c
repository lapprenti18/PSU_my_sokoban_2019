/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

int    win(char **tab, char *map, char **av)
{
    int **o_pos;
    int win;

    tab = my_str_to_word_array(map);
    o_pos = tab_o(tab);
    win = loop(tab, o_pos, av);
    if (win == 2)
        return (1);
    return (0);
}