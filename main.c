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

int    error2(int ac, char **av, char *map)
{
    int p = 0;
    int x;
    int o;

    for (int a = 0; map[a]; a += 1)
        if (map[a] != '#' && map[a] != 'P' && map[a] != 'X' && map[a] != 'O' && map[a] != ' ' && map[a] != '\n')
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
    return(0);
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

int main (int ac, char **av)
{
    char *map;
    char **tab;
    int **o_pos;
    int win;
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
    tab = my_str_to_word_array(map);
    o_pos = tab_o(tab);
    win = loop(tab, o_pos, av);
    if (win == 2)
        return (1);
    return (0);
}