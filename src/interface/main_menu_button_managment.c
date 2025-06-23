/*
** EPITECH PROJECT, 2025
** boutton managment
** File description:
** boutton managment
*/

#include "../../include/rpg.h"

float scale_calculate(float a, float b, float t)
{
    return a + t * (b - a);
}

static void pressed_and_hovered_detection(button_t *btn, rpg_t *game,
    sfBool is_hovered)
{
    if (is_hovered && btn->state != PRESSED && btn->final_scale.x != 1.3f) {
        btn->current_scale = btn->current_scale;
        btn->final_scale = (sfVector2f){1.3f, 1.3f};
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

static void pressed_and_hovered_action(button_t *btn, rpg_t *game,
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
        btn->current_scale = (sfVector2f){0.9f, 0.9f};
        btn->final_scale = btn->default_scale;
        btn->duration = 0.1f;
        btn->elapsed = 0.0f;
        btn->state = RETURNING;
    }
    sfClock_restart(btn->clock);
}

void handle_button_event(button_t *btn, rpg_t *game)
{
    sfBool is_hovered;

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    btn->bounds.height *= game->new_scale.y;
    btn->bounds.left *= game->new_scale.x;
    btn->bounds.top *= game->new_scale.y;
    btn->bounds.width *= game->new_scale.x;
    is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);
    pressed_and_hovered_detection(btn, game, is_hovered);
    pressed_and_hovered_action(btn, game, is_hovered);
}

void draw_all_button(rpg_t *game)
{
    draw_button(game->btn->btn_jouer, game->window);
    draw_button(game->btn->btn_options, game->window);
    draw_button(game->btn->btn_credits, game->window);
    draw_button(game->btn->btn_quitter, game->window);
}

static void main_menu_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_options->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 1;
    if (sfFloatRect_contains(&game->btn->btn_quitter->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->is_close = 1;
    if (sfFloatRect_contains(&game->btn->btn_credits->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 2;
}

void main_menu_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
        sfmouse_get_position_resized(game);
        handle_button_event(game->btn->btn_jouer, game);
        handle_button_event(game->btn->btn_options, game);
        handle_button_event(game->btn->btn_credits, game);
        handle_button_event(game->btn->btn_quitter, game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            main_menu_button_press_event(game);
        }
    }
}

void main_menu(rpg_t *game)
{
    handle_music(game->music->music1);
    while (sfRenderWindow_isOpen(game->window)) {
        main_menu_event(game);
        update_button(game->btn->btn_jouer, game->window);
        update_button(game->btn->btn_options, game->window);
        update_button(game->btn->btn_credits, game->window);
        update_button(game->btn->btn_quitter, game->window);
        sfSprite_setScale(game->sprite1, game->new_scale);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_scren_button(game);
        menu_credit_button(game);
        menu_s(game);
        sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
        draw_all_button(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
