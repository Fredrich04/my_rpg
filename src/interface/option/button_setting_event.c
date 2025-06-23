/*
** EPITECH PROJECT, 2025
** b_s_m
** File description:
** b_s_m
*/

#include "../../../include/rpg.h"

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
    sfBool is_hovered;

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    btn->bounds.height *= game->new_scale.y;
    btn->bounds.left *= game->new_scale.x;
    btn->bounds.top *= game->new_scale.y;
    btn->bounds.width *= game->new_scale.x;
    is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);
    pressed_and_hovered_detection_s(btn, game, is_hovered);
    pressed_and_hovered_action_s(btn, game, is_hovered);
}

void menu_s_button_event(rpg_t *game)
{
    sfmouse_get_position_resized(game);
    handle_button_event_s(game->btn->btn_retour, game);
    handle_button_event_s(game->btn->btn_muet, game);
    handle_button_event_s(game->btn->btn_e_size, game);
    handle_button_event_s(game->btn->btn_commande, game);
    handle_button_event_s(game->btn->btn_volume_d, game);
    handle_button_event_s(game->btn->btn_volume_up, game);
}

static void regulate_vol_up(rpg_t *game)
{
    game->music->volume = sfMusic_getVolume(game->music->music1);
    if (game->music->volume + 5 > 200)
        game->music->volume = 200;
    else
        game->music->volume += 5;
    sfMusic_setVolume(game->music->music1, game->music->volume - 5);
}

static void regulate_vol_down(rpg_t *game)
{
    game->music->volume = sfMusic_getVolume(game->music->music1);
    if (game->music->volume - 5 < 0)
        game->music->volume = 0;
    else
        game->music->volume -= 5;
    sfMusic_setVolume(game->music->music1, game->music->volume - 5);
}

void main_menu_sound_managment(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_volume_up->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        regulate_vol_up(game);
    if (sfFloatRect_contains(&game->btn->btn_volume_d->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        regulate_vol_down(game);
    if (sfFloatRect_contains(&game->btn->btn_muet->bounds,
        game->mouse_pos.x, game->mouse_pos.y) && game->music->m_bool == 0) {
        sfMusic_pause(game->music->music1);
        game->music->m_bool = 1;
    } else if (sfFloatRect_contains(&game->btn->btn_muet->bounds,
        game->mouse_pos.x, game->mouse_pos.y) && game->music->m_bool == 1) {
        sfMusic_play(game->music->music1);
        game->music->m_bool = 0;
    }
}
