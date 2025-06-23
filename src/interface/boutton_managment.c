/*
** EPITECH PROJECT, 2025
** boutton managment
** File description:
** boutton managment
*/

#include "../../include/rpg.h"

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

void button_resize(rpg_t *game, button_t *btn)
{
    sfVector2f new_position = {btn->original_pos.x * game->new_scale.x,
        btn->original_pos.y * game->new_scale.y};
    sfVector2f scale = {btn->default_scale.x * game->new_scale.x,
        btn->default_scale.y * game->new_scale.y};

    sfSprite_setPosition(btn->sprite, new_position);
    sfSprite_setScale(btn->sprite, game->new_scale);
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
