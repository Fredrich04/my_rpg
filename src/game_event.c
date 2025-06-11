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
        if (game->event.type == sfEvtMouseButtonPressed) {
            if (game->pos_par.x >= 330 && game->pos_par.x <= 750 &&
                game->pos_par.y >= 880 && game->pos_par.y <= 1000) {
                game->m = 1;
            }
        }
    }
}

void menu_s(rpg_t *game)
{
    game->sprite2 = sfSprite_create();
    game->texture2 = sfTexture_createFromFile("assert/menu_s.png", NULL);
    sfSprite_setTexture(game->sprite2, game->texture2, sfTrue);
    sfSprite_setPosition(game->sprite2, (sfVector2f){-1, -1});
    sfSprite_setScale (game->sprite2, (sfVector2f){0.98, 0.974});
    game->pos_par = sfMouse_getPositionRenderWindow(game->window);
    while (game->m == 1) {
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            close_event(game);
            game->pos_par = sfMouse_getPositionRenderWindow(game->window);
            printf("%d\n" "%d\n" , game->pos_par.x, game->pos_par.y);
            if (game->event.type == sfEvtMouseButtonPressed) {
                
                if (game->pos_par.x >= 90 && game->pos_par.x <= 370 &&
                    game->pos_par.y >= 920 && game->pos_par.y <= 1000) {
                    game->m = 0;
                }
            }
        }
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
        sfRenderWindow_display(game->window);
    }
    sfSprite_destroy(game->sprite2);
    sfTexture_destroy(game->texture2);
}

void game_loop(rpg_t *game)
{
    game->m = 0;
    handle_music(game->music->music1);
    game->sprite1 = sfSprite_create();
    game->texture1 = sfTexture_createFromFile("assert/menu_p.png", NULL);
    sfSprite_setTexture(game->sprite1, game->texture1, sfTrue);
    sfSprite_setPosition(game->sprite1, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_s(game);
        if (game->m == 0)
            sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
