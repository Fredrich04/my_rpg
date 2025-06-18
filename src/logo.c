#include "../include/rpg.h"

static float frame_duration;
static int frame;

void load_frames(rpg_t *game)
{
    char filename[64];

    game->loading = malloc(sizeof(loading_t));
    game->loading->clock = sfClock_create();
    for (int i = 0; i < INTRO_FRAME; i++) {
        sprintf(filename, "assert/loading/%d.png", i + 1);
        game->loading->txt[i] = sfTexture_createFromFile(filename, NULL);
        if (!game->loading->txt[i])
            continue;
        game->loading->sprite[i] = sfSprite_create();
        if (!game->loading->sprite[i])
            continue;
        sfSprite_setTexture(game->loading->sprite[i], game->loading->txt[i],
            sfTrue);
    }
}

void loading_events(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        close_event(game);
}

void loading(rpg_t *game)
{
    int try = 2;

    frame_duration = 3.5f / 40.0f;
    frame = 0;
    sfClock_restart(game->loading->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        loading_events(game);
        game->loading->time = sfTime_asSeconds(sfClock_getElapsedTime(game->loading->clock));
        if (game->loading->time >= frame_duration) {
            frame++;
            sfClock_restart(game->loading->clock);
        }
        if (try == 0)
            break;
        if (frame >= INTRO_FRAME) {
            try--;
            frame = 0;
        }
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->loading->sprite[frame])
            sfRenderWindow_drawSprite(game->window,
                game->loading->sprite[frame], NULL);
        sfRenderWindow_display(game->window);
    }
}

void destroy_intro(rpg_t *game)
{
    for (int i = 0; i < INTRO_FRAME; i++) {
        sfTexture_destroy(game->loading->txt[i]);
        sfSprite_destroy(game->loading->sprite[i]);
    }
    game->loading->clock;
    free(game->loading);
}