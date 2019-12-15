/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

char    *fill(char **av)
{
    struct stat size_buff;
    int reslt = stat(av[1], &size_buff);
    char *buffer = malloc(sizeof(char) * size_buff.st_size + 1);
    int fd = open(av[1], O_RDONLY);
    int a = 0;

    for (int i = 0; i < size_buff.st_size + 1; i += 1) {
        buffer[i] = '\0';
    }
    read(fd, buffer, size_buff.st_size + 1);
    if (fd == -1)
        return "84";
    close(fd);
    return (buffer);
}

int    win_or_loose(char **tab, int **o_pos, int test, player_s *player)
{
    test = check_loose(tab, o_pos, player, test);
    test = check_win(tab, o_pos, player, test);
    return (test);
}

int    blocked(char **tab, int i, int a)
{
    if (tab[i][a] == 'X')
        return (check_x_blocked(tab, i, a));
    return (0);
}