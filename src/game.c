/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void game_initialization(rpg_t *game)
{
    game->window = create_window(false);
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
