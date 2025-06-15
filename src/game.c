/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void init_button_part2(rpg_t *game)
{
    game->btn->btn_volume_d = create_button(sfTexture_createFromFile(
        "assert/volume_down.png", NULL), (sfVector2f){1100, 250},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_commande = create_button(sfTexture_createFromFile(
        "assert/commande.png", NULL), (sfVector2f){380, 500},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_e_size = create_button(sfTexture_createFromFile(
        "assert/s_r.png", NULL), (sfVector2f){800, 730},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_muet = create_button(sfTexture_createFromFile(
        "assert/muet.png", NULL), (sfVector2f){1100, 500},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_retour = create_button(sfTexture_createFromFile(
        "assert/retour.png", NULL), (sfVector2f){200, 920},
        (sfVector2f){0.75f, 0.75f});
}

void init_button(rpg_t *game)
{
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
    game->btn->btn_volume_up = create_button(sfTexture_createFromFile(
        "assert/volume_up.png", NULL), (sfVector2f){380, 250},
        (sfVector2f){0.85f, 0.85f});
    init_button_part2(game);
}

void game_initialization(rpg_t *game)
{
    game->music = malloc(sizeof(music_t));
    game->btn = malloc(sizeof(button_center_t));
    game->main_menu = malloc(sizeof(main_menu_t));
    game->window = create_window(false);
    game->main_menu->m = 0;
    game->main_menu->is_close = 0;
    game->is_close = 0;
    game->music->music1 = sfMusic_createFromFile("assert/music_epic.mp3");
    init_button(game);
}

void destroy_all_button(rpg_t *game)
{
    destroy_button(game->btn->btn_jouer);
    destroy_button(game->btn->btn_options);
    destroy_button(game->btn->btn_credits);
    destroy_button(game->btn->btn_quitter);
    destroy_button(game->btn->btn_commande);
    destroy_button(game->btn->btn_e_size);
    destroy_button(game->btn->btn_retour);
    destroy_button(game->btn->btn_volume_d);
    destroy_button(game->btn->btn_volume_up);
    free(game->btn);
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
