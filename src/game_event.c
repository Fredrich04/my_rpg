/**
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

void game_loop(rpg_t *game)
{
    handle_music(game->music->music1);
    while (sfRenderWindow_isOpen(game->window)) {
        main_menu_event(game);
        update_button(game->btn->btn_jouer, game->window);
        update_button(game->btn->btn_options, game->window);
        update_button(game->btn->btn_credits, game->window);
        update_button(game->btn->btn_quitter, game->window);
        sfSprite_setScale(game->sprite1, game->new_scale);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_scren_button(game);
        menu_credit_button(game);
        menu_s(game);
        if (game->main_menu->m == 0) {
            sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
            draw_all_button(game);
        }
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
