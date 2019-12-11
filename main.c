/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_bootstrap_2019
** File description:
** boostrap.c
*/

#include "sokoban.h"

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

int    error2(int ac, char **av, char *map)
{
    int p = 0;
    int x;
    int o;

    for (int a = 0; map[a]; a += 1)
        if (map[a] != '#' && map[a] != 'P' && map[a] != 'X' && map[a] != 'O' \
        && map[a] != ' ' && map[a] != '\n')
            return (84);
    for (int a = 0; map[a]; a += 1)
        if (map[a] == 'P')
            p += 1;
    for (int a = 0; map[a]; a += 1){
        if (map[a] == 'X')
            x += 1;
        if (map[a] == 'O')
            o += 1;
    }
    if (p != 1 || o == 0 || x == 0 || o > x)
        return (84);
    return (0);
}

int    error(int ac, char **av, char *map)
{
    int fd = open(av[1], O_RDONLY);
    struct stat size_buff;
    char *buffer[32000];
    int c;
    int temp;

    stat(av[1], &size_buff);
    if (fd == -1 || size_buff.st_size == 0 || ac != 2)
        return 84;
    c = read(fd, buffer, size_buff.st_size);
    if (c == -1)
        return (84);
    return (0);
}

void    man(void)
{
    char *text = "USAGE\n\
\t./my_sokoban map\n\
DESCRIPTION\n\
\tmap  file representing the warehouse map, containing ‘#’ for walls,\n\
\t\t‘P’ for the player, ‘X’ for boxes and ‘O’ for storage locations.\n";

    write(1, text, 188);
}

int    main (int ac, char **av)
{
    char *map;
    char **tab;
    int err = error(ac, av, map);

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        man();
        return (0);
    }
    if (err == 84)
        return (84);
    map = fill(av);
    err = error2(ac, av, map);
    if (err == 84)
        return (84);
    if (win(tab, map, av) == 1)
        return (1);
    return (0);
}