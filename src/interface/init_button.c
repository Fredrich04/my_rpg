/*
** EPITECH PROJECT, 2025
** button
** File description:
** button
*/

#include "../../include/rpg.h"

static void init_screen_button(rpg_t *game)
{
    game->btn->btn_back_screen = create_button(sfTexture_createFromFile(
        "assert/option/back_screen.png", NULL), (sfVector2f){140, 140},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_size1 = create_button(sfTexture_createFromFile(
        "assert/option/1.png", NULL), (sfVector2f){380, 500},
        (sfVector2f){0.8f, 0.8f});
    game->btn->btn_size2 = create_button(sfTexture_createFromFile(
        "assert/option/2.png", NULL), (sfVector2f){940, 500},
        (sfVector2f){0.8f, 0.8f});
    game->btn->btn_size3 = create_button(sfTexture_createFromFile(
        "assert/option/3.png", NULL), (sfVector2f){1520, 500},
        (sfVector2f){0.8f, 0.8f});
}

static void init_main_menu_button(rpg_t *game)
{
    game->btn->btn_jouer = create_button(sfTexture_createFromFile(
        "assert/main menu/btn_jouer.png", NULL), (sfVector2f){1300, 500},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_options = create_button(sfTexture_createFromFile(
        "assert/main menu/btn_option.png", NULL), (sfVector2f){1300, 620},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_credits = create_button(sfTexture_createFromFile(
        "assert/main menu/btn_credit.png", NULL), (sfVector2f){1300, 740},
        (sfVector2f){1.0f, 1.0f});
    game->btn->btn_quitter = create_button(sfTexture_createFromFile(
        "assert/main menu/btn_quitter.png", NULL), (sfVector2f){1300, 860},
        (sfVector2f){1.0f, 1.0f});
}

static void init_option_button(rpg_t *game)
{
    game->btn->btn_volume_up = create_button(sfTexture_createFromFile(
        "assert/option/volume_up.png", NULL), (sfVector2f){380, 250},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_volume_d = create_button(sfTexture_createFromFile(
        "assert/option/volume_down.png", NULL), (sfVector2f){1100, 250},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_commande = create_button(sfTexture_createFromFile(
        "assert/option/commande.png", NULL), (sfVector2f){380, 500},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_e_size = create_button(sfTexture_createFromFile(
        "assert/option/s_r.png", NULL), (sfVector2f){800, 730},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_muet = create_button(sfTexture_createFromFile(
        "assert/option/muet.png", NULL), (sfVector2f){1100, 500},
        (sfVector2f){0.85f, 0.85f});
    game->btn->btn_retour = create_button(sfTexture_createFromFile(
        "assert/option/retour.png", NULL), (sfVector2f){200, 920},
        (sfVector2f){0.75f, 0.75f});
    init_screen_button(game);
}

static void init_credit_button(rpg_t *game)
{
    game->btn->btn_back_credit = create_button(sfTexture_createFromFile(
        "assert/credit/back_credit.png", NULL), (sfVector2f){140, 900},
        (sfVector2f){0.85f, 0.85f});
}

void init_button(rpg_t *game)
{
    init_main_menu_button(game);
    init_option_button(game);
    init_credit_button(game);
}
