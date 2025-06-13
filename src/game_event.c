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
        || game->event.key.code == sfKeyEscape) {
        sfRenderWindow_close(game->window);
        destroy_game(game);
        exit(0);
    }
}

void game_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
        handle_button_event(game->btn->btn_jouer, game);
        handle_button_event(game->btn->btn_options, game);
        handle_button_event(game->btn->btn_credits, game);
        handle_button_event(game->btn->btn_quitter, game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            if (sfFloatRect_contains(&game->btn->btn_options->bounds, game->mouse_pos.x, game->mouse_pos.y))
                game->m = 1;
        }
    }
}

void menu_s(rpg_t *game)
{
    game->sprite2 = sfSprite_create();
    game->texture2 = sfTexture_createFromFile("assert/menu_s1.png", NULL);
    sfSprite_setTexture(game->sprite2, game->texture2, sfTrue);
    sfSprite_setPosition(game->sprite2, (sfVector2f){-1, -1});
    sfSprite_setScale (game->sprite2, (sfVector2f){0.98, 0.934});
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    while (game->m == 1) {
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            close_event(game);
            handle_button_event_s(game->btn->btn_volume_up, game);
            game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
            printf("%d\n %d\n", game->mouse_pos.x, game->mouse_pos.y);
            if (game->event.type == sfEvtMouseButtonPressed) {
                if (game->mouse_pos.x >= 85 && game->mouse_pos.x <= 400 &&
                    game->mouse_pos.y >= 870 && game->mouse_pos.y <= 952) {
                    game->m = 0;
                }
            }
        }
        update_button(game->btn->btn_volume_up, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
        draw_all_button_s(game);
        sfRenderWindow_display(game->window);
    }
    sfSprite_destroy(game->sprite2);
    sfTexture_destroy(game->texture2);
}

void game_loop(rpg_t *game)
{
    handle_music(game->music->music1);
    game->sprite1 = sfSprite_create();
    game->texture1 = sfTexture_createFromFile("assert/front.png", NULL);
    sfSprite_setTexture(game->sprite1, game->texture1, sfTrue);
    sfSprite_setPosition(game->sprite1, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        update_button(game->btn->btn_jouer, game->window);
        update_button(game->btn->btn_options, game->window);
        update_button(game->btn->btn_credits, game->window);
        update_button(game->btn->btn_quitter, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_s(game);
        if (game->m == 0)
            sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
        draw_all_button(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
