/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** my_str_to_word_array.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ncurses.h>
#include <curses.h>
#include <fcntl.h>

typedef struct player_t
{
    int x;
    int y;
    int nb_o;
}player_s;

char    **my_str_to_word_array(char *str);
char    *fill(char **av);
void    key_up(player_s *player, char **tab, int b);
void    key_down(player_s *player, char **tab, int b);
void    key_left(player_s *player, char **tab, int b);
void    key_right(player_s *player, char **tab, int b);
void    display_map(char **tab);
void    player_pos(player_s *player, char **tab);
void    move_p(player_s player, char **tab, int b);
int    nb_of_o(char **tab);
void    check_o(char **tab, int **tab_o, player_s *player);
int    check_win(char **tab, int **tab_o, player_s *player, int test);
int    check_x_blocked(char **tab, int i, int a);
int    check_loose(char **tab, int **tab_o, player_s *player, int test);
char    **reset_map(char **av);
int    loop(char **tab, int **o_pos, char **av);
int **tab_o(char **tab);
int    error2(int ac, char **av, char *map);
int    error(int ac, char **av, char *map);
void    man(void);
void    start_loop(char **tab);
void    before_loop(void);
int    win(char **tab, char *map, char **av);