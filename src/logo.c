#include "../include/rpg.h"

static float frame_duration;
static int frame;

void load_intro_frames(rpg_t *game)
{
    char filename[PATH_MAX];

    game->intro = malloc(sizeof(intro_t));
    game->intro->sprite = malloc(sizeof(sfSprite *) * INTRO_FRAME);
    game->intro->txt = malloc(sizeof(sfTexture *) * INTRO_FRAME);
    if (!game->intro->sprite || !game->intro->txt) {
        free(game->intro);
        return;
    }
    game->intro->clock = sfClock_create();
    for (int i = 0; i < INTRO_FRAME; i++) {
        game->intro->txt[i] = NULL;
        game->intro->sprite[i] = NULL;
        snprintf(filename, sizeof(filename), "assert/intro/%d.png", i + 1);
        game->intro->txt[i] = sfTexture_createFromFile(filename, NULL);
        game->intro->sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->intro->sprite[i], game->intro->txt[i], sfTrue);
    }
}

void intro_events(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        close_event(game);
}

void play_intro(rpg_t *game)
{
    frame_duration = 9.0f / (float)INTRO_FRAME;
    frame = 0;
    sfClock_restart(game->intro->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        intro_events(game);
        game->intro->time = sfTime_asSeconds(sfClock_getElapsedTime(game->intro->clock));
        if (game->intro->time >= frame_duration) {
            frame++;
            sfClock_restart(game->intro->clock);
        }
        if (frame >= INTRO_FRAME)
            break;
        sfRenderWindow_clear(game->window, sfBlack);
        if (frame < INTRO_FRAME && game->intro->sprite[frame]) {
            sfRenderWindow_drawSprite(game->window,
                game->intro->sprite[frame], NULL);
        }
        sfRenderWindow_display(game->window);
    }
}

void destroy_intro(rpg_t *game)
{
    if (!game->intro)
        return;
    for (int i = 0; i < INTRO_FRAME; i++) {
        if (game->intro->txt[i])
            sfTexture_destroy(game->intro->txt[i]);
        if (game->intro->sprite[i])
            sfSprite_destroy(game->intro->sprite[i]);
    }
    sfClock_destroy(game->intro->clock);
    free(game->intro->txt);
    free(game->intro->sprite);
    free(game->intro);
}
