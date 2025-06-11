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
    game->btn = malloc(sizeof(button_center_t));
    game->window = create_window(false);
    game->m = 0;
    game->music->music1 = sfMusic_createFromFile("assert/music_epic.mp3");
    game->btn->btn_jouer = create_button(sfTexture_createFromFile(
        "assert/btn_jouer.png", NULL), (sfVector2f){1300, 500},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_options = create_button(sfTexture_createFromFile(
        "assert/btn_option.png", NULL), (sfVector2f){1300, 620},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_credits = create_button(sfTexture_createFromFile(
        "assert/btn_credit.png", NULL), (sfVector2f){1300, 740},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_quitter = create_button(sfTexture_createFromFile(
        "assert/btn_quitter.png", NULL), (sfVector2f){1300, 860},
        (sfVector2f){1.0f, 1.0f});
}

void destroy_game(rpg_t *game)
{
    sfSprite_destroy(game->sprite1);
    sfTexture_destroy(game->texture1);
    destroy_all_button(game);
    sfRenderWindow_destroy(game->window);
    sfMusic_destroy(game->music->music1);
    free(game->music);
    free(game);
}
