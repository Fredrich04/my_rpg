/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"
float manage_time(sfClock *clock)
{
    float secs = 0.0;
    sfTime time = {0};

    time = sfClock_getElapsedTime(clock);
    secs = sfTime_asSeconds(time);
    return secs;
}

void game_initialization(rpg_t *game)
{
    game->window = create_window(false);
    game->powers = NULL;
}

void game_loop(rpg_t *game)
{
    sfSprite *test = sfSprite_create();
    sfTexture *test1 = sfTexture_createFromFile("./Powers/global_images/fight_decor.jpeg", NULL);
    ennemies_t *ennemies = create_ennemie_ui();
    character_t *character = create_main_character_ui(game->powers);

    sfSprite_setTexture(test, test1, sfTrue);
    game->powers->texture_size = sfTexture_getSize(test1);
    game->powers->scale = (sfVector2f){(double)1920 / game->powers->texture_size.x, (double)1080 / game->powers->texture_size.y};
    sfSprite_setScale(test, game->powers->scale);
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, test, NULL);
        draw_ui(game, character, ennemies);
        sfRenderWindow_display(game->window);
    }
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
