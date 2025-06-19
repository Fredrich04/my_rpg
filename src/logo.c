#include "../include/rpg.h"
//21
static float frame_duration;
static int frame;
static int move;

void load_intro_frames(rpg_t *game)
{
    char filename[64];

    game->intro = malloc(sizeof(intro_t));
    game->intro->clock = sfClock_create();
    for (int i = 0; i < INTRO_FRAME; i++) {
        sprintf(filename, "assert/intro/intro_frames1/%d.png", i + 1);
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
    int c = 51;

    move = 39;
    sfClock_restart(game->intro->clock);
    game->intro->man_clock = sfClock_create();
    game->intro->man = sfSprite_create();
    game->intro->man_txt = sfTexture_createFromFile("assert/intro/walk.png", NULL);
    game->intro->walk = (sfIntRect) {0, 0, 250, 512};
    game->intro->tambour = sfSprite_create();
    game->intro->tambour_txt = sfTexture_createFromFile("assert/intro/tambour.jpeg", NULL);
    game->intro->play_clock = sfClock_create();
    game->intro->playing = sfSprite_create();
    game->intro->playing_txt = sfTexture_createFromFile("assert/intro/play drump.png", NULL);
    game->intro->play = (sfIntRect) {0, 0, 250, 512};
    sfSprite_setTexture(game->intro->tambour, game->intro->tambour_txt, sfTrue);
    sfSprite_setTexture(game->intro->man, game->intro->man_txt, sfTrue);
    sfSprite_setTextureRect(game->intro->man, game->intro->walk);
    sfSprite_setTexture(game->intro->playing, game->intro->playing_txt, sfTrue);
    sfSprite_setTextureRect(game->intro->playing, game->intro->play);
    sfSprite_setScale(game->intro->man, (sfVector2f){0.3f, 0.3f});
    sfSprite_setPosition(game->intro->playing, (sfVector2f){500, 880});
    sfSprite_setPosition(game->intro->sprite[51], (sfVector2f){675, 200});
    sfSprite_setPosition(game->intro->sprite[50], (sfVector2f){675, 200});
    sfSprite_setScale(game->intro->tambour, (sfVector2f){0.3f, 0.3f});
    sfSprite_setScale(game->intro->playing, (sfVector2f){0.3f, 0.3f});
    sfSprite_setPosition(game->intro->man, (sfVector2f){-350, 800});
    sfSprite_setPosition(game->intro->tambour, (sfVector2f){500, 880});
    while (sfRenderWindow_isOpen(game->window)) {
        intro_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        game->intro->time = sfTime_asSeconds(sfClock_getElapsedTime(game->intro->clock));
        game->intro->man_time = sfTime_asSeconds(sfClock_getElapsedTime(game->intro->man_clock));
        if (game->intro->man_time > 0.2 && move >= 1) {
            game->intro->walk.left += game->intro->walk.width;
            if (game->intro->walk.left >= 1000)
                game->intro->walk.left = 0;
            if (move - 5 == 1) {
                game->intro->walk.top += game->intro->walk.height;
                game->intro->walk.left = 0;
                move = 4;
            }
            sfSprite_setTextureRect(game->intro->man, game->intro->walk);
            sfSprite_move(game->intro->man, (sfVector2f){20, 0});
            move--;
            sfClock_restart(game->intro->man_clock);
        }
        sfRenderWindow_drawSprite(game->window, game->intro->sprite[c], NULL);
        //if ()
        sfRenderWindow_drawSprite(game->window, game->intro->tambour, NULL);
        sfRenderWindow_drawSprite(game->window, game->intro->man, NULL);
        //if (c == 51)
        //    c = 50;
        //else
        //    c = 51;
        sfRenderWindow_display(game->window);
    }
}

void play_intro(rpg_t *game)
{
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
        if (frame >= INTRO_FRAME - 2)
            break;
        sfRenderWindow_clear(game->window, sfBlack);
        if (game->intro->sprite[frame])
            sfRenderWindow_drawSprite(game->window,
                game->intro->sprite[frame], NULL);
        sfRenderWindow_display(game->window);
    }
    play_intro_part2(game);
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