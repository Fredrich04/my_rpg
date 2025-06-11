/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void game_initialization(rpg_t *game)
{
    game->music = malloc(sizeof(music_t));
    game->window = create_window(false);
    game->m = 0;
    game->music->music1 = sfMusic_createFromFile("assert/music_epic.mp3");
}
/*
void game_loop(rpg_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_display(game->window);
    }
}
*/
void destroy_game(rpg_t *game)
{
    sfSprite_destroy(game->sprite1);
    sfTexture_destroy(game->texture1);
    sfRenderWindow_destroy(game->window);
    free(game->music);
    free(game);
}
