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

void game_loop(rpg_t *game)
{
    play_intro(game);
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
