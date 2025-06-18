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
    sfClock *clock = sfClock_create();
    int x = 0;
    int times = 0;
    game->powers->tab = malloc(sizeof(sfSprite *) * 3);
    (game->powers->tab)[0] = (sfSprite *) sfSprite_create();
    game->powers->charging_texture = sfTexture_createFromFile("./Powers/global_images/load_judgements.png", NULL);
    sfSprite_setTexture(game->powers->tab[0], game->powers->charging_texture, sfTrue);
    game->powers->texture_size = sfTexture_getSize(game->powers->charging_texture);
    game->powers->scale = (sfVector2f){(double)1920 / game->powers->texture_size.x, (double)1080 / game->powers->texture_size.y};
    sfSprite_setScale(game->powers->tab[0], game->powers->scale);
     (game->powers->tab)[1] = sfSprite_create();
    sfSprite_setTexture(game->powers->tab[1], game->powers->middle_texture, sfTrue);
    game->powers->texture_size = sfTexture_getSize(game->powers->middle_texture);
    game->powers->scale = (sfVector2f){(double)1920 / game->powers->texture_size.x, (double)1080 / game->powers->texture_size.y};
    sfSprite_setScale(game->powers->middle_sprite, game->powers->scale);
    (game->powers->tab)[2] = sfSprite_create();
     sfSprite_setTexture(game->powers->tab[2], game->powers->final_texture, sfTrue);
      game->powers->texture_size = sfTexture_getSize(game->powers->final_texture);
    game->powers->scale = (sfVector2f){(double)1920 / game->powers->texture_size.x, (double)1080 / game->powers->texture_size.y};
    sfSprite_setScale(game->powers->final_sprite, game->powers->scale);
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
      //  sfRenderWindow_clear(game->window, sfBlack);
//        sfRenderWindow_drawSprite(game-);
         if (manage_time(clock) >= 1 && times >= 1) {
             x++;
             sfClock_destroy(clock);
             clock = sfClock_create();
             if (x == 3)
                 x = 0;
         }
        // printf("I'm currently trying to access %d\n", x);
        times++;
       sfRenderWindow_drawSprite(game->window, (game->powers->tab)[x], NULL);
        sfRenderWindow_display(game->window);
    }
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
