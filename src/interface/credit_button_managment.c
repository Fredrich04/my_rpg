/*
** EPITECH PROJECT, 2025
** cbm
** File description:
** cbm
*/

#include "../../include/rpg.h"

static void pressed_and_hovered_detection_credit(button_t *btn, rpg_t *game,
    sfBool is_hovered)
{
    if (is_hovered && btn->state != PRESSED && btn->final_scale.x != 0.96f) {
        btn->current_scale = btn->current_scale;
        btn->final_scale = (sfVector2f){0.96f, 0.96f};
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

static void pressed_and_hovered_action_credit(button_t *btn, rpg_t *game,
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

void handle_button_event_credit(button_t *btn, rpg_t *game)
{
    sfBool is_hovered;

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    btn->bounds.height *= game->new_scale.y;
    btn->bounds.left *= game->new_scale.x;
    btn->bounds.top *= game->new_scale.y;
    btn->bounds.width *= game->new_scale.x;
    is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);
    pressed_and_hovered_detection_credit(btn, game, is_hovered);
    pressed_and_hovered_action_credit(btn, game, is_hovered);
}

void draw_button_credit(rpg_t *game)
{
    draw_button(game->btn->btn_back_credit, game->window);
}

void menu_credit_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_back_credit->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 0;
}

void menu_credit_button_event(rpg_t *game)
{
    sfMouse_getPositionResized(game);
    handle_button_event_credit(game->btn->btn_back_credit, game);
     if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            menu_credit_button_press_event(game);
        }
      if (game->event.type == sfEvtMouseButtonReleased) {
          if (game->hovered = 0)
          if (game->mouse_pos.x >= 76 && game->mouse_pos.x <= 410 && game->mouse_pos.y >= 116 && game->mouse_pos.y <= 452) {
              game->hovered = 1;
              printf("entered\n");
              //sfRenderWindow_drawSprite(game->window, game->sprite_amy, NULL);
          } else
              game->hovered = 0;
      }
      printf("x= %d\n y= %d\n", game->mouse_pos.x, game->mouse_pos.y);
}

void menu_credit_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
        menu_credit_button_event(game);
    }
}

void menu_credit_button(rpg_t *game)
{
    sfSprite_setScale(game->sprite_c, game->new_scale);
    while (game->main_menu->m == 2) {
        menu_credit_event(game);
        update_button(game->btn->btn_back_credit, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite_c, NULL);
        if (game->hovered == 1)
            sfRenderWindow_drawSprite(game->window, game->sprite_amy, NULL);
        draw_button_credit(game);
        sfRenderWindow_display(game->window);
    }
}
