/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

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
    int test = 0;

    player.nb_o = nb_of_o(tab);
    before_loop();
    while (1) {
        start_loop(tab);
        test = win_or_loose(tab, o_pos, test, &player);
        check_o(tab, o_pos, &player);
        if (test == 1 || test == 2)
            break;
        b = getch();
        if (b == 32)
            tab = reset_map(av);
        player_pos(&player, tab);
        move_p(player, tab, b);
        check_o(tab, o_pos, &player);
    }
    endwin();
    return (test);
}