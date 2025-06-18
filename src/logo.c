#include "../include/rpg.h"

static float frame_duration;
static int frame;

void load_intro_frames(rpg_t *game)
{
    char filename[64];

    game->intro = malloc(sizeof(intro_t));
    game->intro->clock = sfClock_create();
    for (int i = 0; i < INTRO_FRAME; i++) {
        sprintf(filename, "intro_frames1/%d.png", i + 1);
        game->intro->txt[i] = sfTexture_createFromFile(filename, NULL);
        if (!game->intro->txt[i])
            continue;
        game->intro->sprite[i] = sfSprite_create();
        if (!game->intro->sprite[i])
            continue;
        sfSprite_setTexture(game->intro->sprite[i], game->intro->txt[i],
            sfTrue);
    }
}

void intro_events(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        close_event(game);
}

void play_intro_part2(rpg_t *game)
{
    
}

void play_intro(rpg_t *game)
{
    int try = 0;

    frame_duration = 5.0f / 40.0f;
    frame = 0;
    sfClock_restart(game->intro->clock);
    while (sfRenderWindow_isOpen(game->window)) {
        intro_events(game);
        game->intro->time = sfTime_asSeconds(sfClock_getElapsedTime(game->intro->clock));
        if (game->intro->time >= frame_duration) {
            frame++;
            sfClock_restart(game->intro->clock);
        }
        if (frame >= INTRO_FRAME - 1) {
            break;
        }
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->intro->sprite[frame])
            sfRenderWindow_drawSprite(game->window,
                game->intro->sprite[frame], NULL);
        sfRenderWindow_display(game->window);
    }
}

void destroy_intro(rpg_t *game)
{
    for (int i = 0; i < INTRO_FRAME; i++) {
        sfTexture_destroy(game->intro->txt[i]);
        sfSprite_destroy(game->intro->sprite[i]);
    }
    game->intro->clock;
    free(game->intro);
}