/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

void set_close(rpg_t *game)
{
    if (game->main_menu->is_close)
        game->is_close = 1;
}

void close_event(rpg_t *game)
{
    set_close(game);
    if (game->event.type == sfEvtClosed
        || game->event.key.code == sfKeyEscape || game->is_close) {
        sfRenderWindow_close(game->window);
        destroy_game(game);
        exit(0);
    }
}
