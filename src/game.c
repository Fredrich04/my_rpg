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
    load_intro_frames(game);
}

void destroy_game(rpg_t *game)
{
    destroy_intro(game);
    sfRenderWindow_destroy(game->window);
    free(game);
}
