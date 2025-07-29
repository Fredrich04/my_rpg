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
    game->powers = NULL;
}

void game_loop(rpg_t *game)
{
    sfVector2f mc_position;
    sfVector2f ennemy_position;
    sfVector2f ennemy_scale;
    sfVector2f mc_scale;
    sfSprite *decor_sprite = sfSprite_create();
    sfSprite *mc_sprite = sfSprite_create();
    sfSprite *ennemy_sprite = sfSprite_create();
    sfTexture *decor_texture = sfTexture_createFromFile("", NULL);
    sfTexture *mc_texture = sfTexture_createFromFile("", NULL);
    sfTexture *ennemy_texture = sfTexture_createFromFile("", NULL);

    sfSprite_setTexture(decor_sprite, decor_texture, sfTrue);
    sfSprite_setTexture(mc_sprite, mc_texture, sfTrue);
    sfSprite_setTexture(ennemy_sprite, ennemy_texture, sfTrue);
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, decor_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, mc_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, ennemy_sprite, NULL);
        sfRenderWindow_display(game->window);
    }
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
