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
    sfVector2u mc_sprite_size;
    sfVector2u ennemy_sprite_size;
    sfVector2u decor_sprite_size;
    sfVector2f mc_position;
    sfVector2f ennemy_position;
    sfVector2f ennemy_scale;
    sfVector2f mc_scale;
    sfVector2f decor_scale;
    sfSprite *decor_sprite = sfSprite_create();
    sfSprite *mc_sprite = sfSprite_create();
    sfSprite *ennemy_sprite = sfSprite_create();
    sfTexture *decor_texture = sfTexture_createFromFile("./src/fight_env.jpeg", NULL);
    sfTexture *mc_texture = sfTexture_createFromFile("./src/mc_fight.png", NULL);
    sfTexture *ennemy_texture = sfTexture_createFromFile("./src/ennemy.png", NULL);

    mc_sprite_size = sfTexture_getSize(mc_texture);
    ennemy_sprite_size = sfTexture_getSize(ennemy_texture);
    decor_sprite_size = sfTexture_getSize(decor_texture);
    sfSprite_setTexture(decor_sprite, decor_texture, sfTrue);
    sfSprite_setTexture(mc_sprite, mc_texture, sfTrue);
    sfSprite_setTexture(ennemy_sprite, ennemy_texture, sfTrue);
    sfSprite_setTextureRect(mc_sprite, (sfIntRect) {0, 0, mc_sprite_size.x / 3, mc_sprite_size.y});
    sfSprite_setTextureRect(ennemy_sprite, (sfIntRect) {0, ennemy_sprite_size.y / 2, ennemy_sprite_size.x / 3.5, ennemy_sprite_size.y / 2});
    printf("The scale I am currently using is %.2f, %.2f\n", (double) 1920 / (mc_sprite_size.x / 3), (double) 1080 / (mc_sprite_size.y));
    mc_scale = (sfVector2f) {(double)  (mc_sprite_size.x / 3) / 200, (double) (mc_sprite_size.y) / 350};
    mc_position = (sfVector2f) {0, 900 - (double) (mc_sprite_size.y) * (mc_sprite_size.y) / 350};
    ennemy_scale = (sfVector2f) {(double)  (1), (double) 1.5};
    ennemy_position = (sfVector2f) {1800 - ennemy_sprite_size.x / 3.5, 950 - (1.5 * (ennemy_sprite_size.y / 2))};
    decor_scale = (sfVector2f) {(double) 1920 / decor_sprite_size.x, (double) 1080 / decor_sprite_size.y};
    sfSprite_setPosition(mc_sprite, mc_position);
    sfSprite_setScale(mc_sprite, mc_scale);
    sfSprite_setScale(ennemy_sprite, ennemy_scale);   
    sfSprite_setPosition(ennemy_sprite, ennemy_position);
    sfSprite_setScale(decor_sprite, decor_scale);
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
