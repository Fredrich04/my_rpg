/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

int main(void)
{
    rpg_t *game = malloc(sizeof(rpg_t));

    game_initialization(game);
    main_menu(game);
    return 0;
}
