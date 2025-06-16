/*
** EPITECH PROJECT, 2025
** boutton managment
** File description:
** boutton managment
*/

#include "../include/rpg.h"

static float scale_calculate(float a, float b, float t)
{
    return a + t * (b - a);
}

button_t *create_button(sfTexture *texture, sfVector2f pos, sfVector2f scale)
{
    sfVector2u size;
    button_t *btn = malloc(sizeof(button_t));

    btn->sprite = sfSprite_create();
    sfSprite_setTexture(btn->sprite, texture, sfTrue);
    size = sfTexture_getSize(texture);
    sfSprite_setOrigin(btn->sprite, (sfVector2f){size.x / 2.0f,
        size.y / 2.0f});
    sfSprite_setPosition(btn->sprite, pos);
    sfSprite_setScale(btn->sprite, scale);
    btn->default_scale = scale;
    btn->final_scale = scale;
    btn->current_scale = scale;
    btn->original_pos = pos;
    btn->clock = sfClock_create();
    btn->duration = 0.0f;
    btn->elapsed = 0.0f;
    btn->state = NORMAL;
    btn->bounds = (sfFloatRect){0};
    return btn;
}

void update_button(button_t *btn, sfRenderWindow *window)
{
    float delta = sfTime_asSeconds(sfClock_restart(btn->clock));
    sfVector2f new_scale;

    btn->elapsed += delta;
    if (btn->elapsed < btn->duration) {
        new_scale = (sfVector2f){
            scale_calculate(btn->current_scale.x, btn->final_scale.x,
                (float)(btn->elapsed / btn->duration)),
            scale_calculate(btn->current_scale.y, btn->final_scale.y,
                (float)(btn->elapsed / btn->duration))
        };
        sfSprite_setScale(btn->sprite, new_scale);
    } else {
        sfSprite_setScale(btn->sprite, btn->final_scale);
        btn->current_scale = btn->final_scale;
    }
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
    sfBool is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    pressed_and_hovered_detection(btn, game, is_hovered);
    pressed_and_hovered_action(btn, game, is_hovered);
}

void draw_button(button_t *btn, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, btn->sprite, NULL);
}

void destroy_button(button_t *btn)
{
    sfSprite_destroy(btn->sprite);
    sfClock_destroy(btn->clock);
    free(btn);
}

void draw_all_button(rpg_t *game)
{
    draw_button(game->btn->btn_jouer, game->window);
    draw_button(game->btn->btn_options, game->window);
    draw_button(game->btn->btn_credits, game->window);
    draw_button(game->btn->btn_quitter, game->window);
}
