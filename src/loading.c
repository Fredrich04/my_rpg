/*
** EPITECH PROJECT, 2025
** loading
** File description:
** loading
*/

#include "../include/rpg.h"

static float frame_duration;
static int frame;
static int try;

void load_frames(rpg_t *game)
{
    char filename[64];

    game->loading = malloc(sizeof(loading_t));
    game->loading->clock = sfClock_create();
    for (int i = 0; i < LOADING_FRAME; i++) {
        game->loading->txt[i] = NULL;
        game->loading->sprite[i] = NULL;
    }
    for (int i = 0; i < LOADING_FRAME; i++) {
        sprintf(filename, "assert/loading/%d.png", i + 1);
        game->loading->txt[i] = sfTexture_createFromFile(filename, NULL);
        game->loading->sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->loading->sprite[i], game->loading->txt[i],
            sfTrue);
    }
}

void loading_events(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        close_event(game);
}

void display_loading(rpg_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
        if (game->loading->sprite[frame])
            sfRenderWindow_drawSprite(game->window,
                game->loading->sprite[frame], NULL);
        sfRenderWindow_display(game->window);
}

void loading(rpg_t *game)
{
    try = 2;
    frame_duration = 3.5f / 40.0f;
    frame = 0;
    sfClock_restart(game->loading->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        loading_events(game);
        game->loading->time = sfTime_asSeconds(
            sfClock_getElapsedTime(game->loading->clock));
        if (game->loading->time >= frame_duration) {
            frame++;
            sfClock_restart(game->loading->clock);
        }
        if (try == 0)
            break;
        if (frame >= LOADING_FRAME) {
            try--;
            frame = 0;
        }
        display_loading(game);
    }
}

void destroy_loading(rpg_t *game)
{
    if (!game || !game->loading)
        return;
    for (int i = 0; i < LOADING_FRAME; i++) {
        if (game->loading->sprite[i]) {
            sfSprite_destroy(game->loading->sprite[i]);
            game->loading->sprite[i] = NULL;
        }
        if (game->loading->txt[i]) {
            sfTexture_destroy(game->loading->txt[i]);
            game->loading->txt[i] = NULL;
        }
    }
    if (game->loading->clock) {
        sfClock_destroy(game->loading->clock);
        game->loading->clock = NULL;
    }
    free(game->loading);
    game->loading = NULL;
}
