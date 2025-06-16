/*
** EPITECH PROJECT, 2025
** b_s_m
** File description:
** b_s_m
*/

#include "../include/rpg.h"

static void pressed_and_hovered_detection_s(button_t *btn, rpg_t *game,
    sfBool is_hovered)
{
    if (is_hovered && btn->state != PRESSED && btn->final_scale.x != 0.88f) {
        btn->current_scale = btn->current_scale;
        btn->final_scale = (sfVector2f){0.88f, 0.88f};
        btn->duration = 0.2f;
        btn->elapsed = 0.0f;
        btn->state = HOVERED;
        sfClock_restart(btn->clock);
    } else if (!is_hovered && btn->state == HOVERED) {
        btn->current_scale = btn->current_scale;
        btn->final_scale = btn->default_scale;
        btn->duration = 0.2f;
        btn->elapsed = 0.0f;
        btn->state = NORMAL;
        sfClock_restart(btn->clock);
    }
}

static void pressed_and_hovered_action_s(button_t *btn, rpg_t *game,
    sfBool is_hovered)
{
    if (is_hovered && game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft) {
        btn->current_scale = btn->current_scale;
        btn->final_scale = (sfVector2f){0.9f, 0.9f};
        btn->duration = 0.1f;
        btn->elapsed = 0.0f;
        btn->state = PRESSED;
    }
    if (btn->state == PRESSED && game->event.type == sfEvtMouseButtonReleased
        && game->event.mouseButton.button == sfMouseLeft) {
        btn->current_scale = (sfVector2f){0.75f, 0.75f};
        btn->final_scale = btn->default_scale;
        btn->duration = 0.1f;
        btn->elapsed = 0.0f;
        btn->state = RETURNING;
    }
    sfClock_restart(btn->clock);
}

void handle_button_event_s(button_t *btn, rpg_t *game)
{
    sfBool is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    pressed_and_hovered_detection_s(btn, game, is_hovered);
    pressed_and_hovered_action_s(btn, game, is_hovered);
}

void draw_all_button_s(rpg_t *game)
{
    draw_button(game->btn->btn_volume_up, game->window);
    draw_button(game->btn->btn_volume_d, game->window);
    draw_button(game->btn->btn_commande, game->window);
    draw_button(game->btn->btn_e_size, game->window);
    draw_button(game->btn->btn_muet, game->window);
    draw_button(game->btn->btn_retour, game->window);
}
