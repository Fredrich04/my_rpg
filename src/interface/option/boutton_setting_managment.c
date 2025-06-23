/*
** EPITECH PROJECT, 2025
** b_s_m
** File description:
** b_s_m
*/

#include "../../../include/rpg.h"

void draw_all_button_s(rpg_t *game)
{
    draw_button(game->btn->btn_volume_up, game->window);
    draw_button(game->btn->btn_volume_d, game->window);
    draw_button(game->btn->btn_commande, game->window);
    draw_button(game->btn->btn_e_size, game->window);
    draw_button(game->btn->btn_muet, game->window);
    draw_button(game->btn->btn_retour, game->window);
}

void menu_s_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_retour->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 0;
    main_menu_sound_managment(game);
    if (sfFloatRect_contains(&game->btn->btn_e_size->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 3;
}

void menu_s_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
        menu_s_button_event(game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            menu_s_button_press_event(game);
        }
    }
}

void update_menu_s_button(rpg_t *game)
{
    update_button(game->btn->btn_retour, game->window);
    update_button(game->btn->btn_muet, game->window);
    update_button(game->btn->btn_e_size, game->window);
    update_button(game->btn->btn_commande, game->window);
    update_button(game->btn->btn_volume_d, game->window);
    update_button(game->btn->btn_volume_up, game->window);
}

void menu_s(rpg_t *game)
{
    sfSprite_setScale(game->sprite2, game->new_scale);
    while (game->main_menu->m == 1) {
        menu_s_event(game);
        update_menu_s_button(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
        draw_all_button_s(game);
        sfRenderWindow_display(game->window);
    }
}
