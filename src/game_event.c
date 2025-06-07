/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

void close_event(rpg_t *game)
{
    if (game->event.type == sfEvtClosed
        || game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
}

void game_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
    }
}