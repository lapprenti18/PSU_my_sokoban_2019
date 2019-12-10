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