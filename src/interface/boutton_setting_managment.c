/*
** EPITECH PROJECT, 2025
** b_s_m
** File description:
** b_s_m
*/

#include "../../include/rpg.h"

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

void draw_all_button_s(rpg_t *game)
{
    draw_button(game->btn->btn_volume_up, game->window);
    draw_button(game->btn->btn_volume_d, game->window);
    draw_button(game->btn->btn_commande, game->window);
    draw_button(game->btn->btn_e_size, game->window);
    draw_button(game->btn->btn_muet, game->window);
    draw_button(game->btn->btn_retour, game->window);
}


void menu_s_button_event(rpg_t *game)
{
    sfMouse_getPositionResized(game);
    handle_button_event_s(game->btn->btn_retour, game);
    handle_button_event_s(game->btn->btn_muet, game);
    handle_button_event_s(game->btn->btn_e_size, game);
    handle_button_event_s(game->btn->btn_commande, game);
    handle_button_event_s(game->btn->btn_volume_d, game);
    handle_button_event_s(game->btn->btn_volume_up, game);
}

void menu_s_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_retour->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 0;
        if (sfFloatRect_contains(&game->btn->btn_volume_up->bounds,
         game->mouse_pos.x, game->mouse_pos.y)) {
         game->music->volume = sfMusic_getVolume(game->music->music1);
         if (game->music->volume + 5 > 200)
             game->music->volume = 200;
         else
             game->music->volume += 5;
     sfMusic_setVolume(game->music->music1, game->music->volume);
        }
      if (sfFloatRect_contains(&game->btn->btn_volume_d->bounds,
	 game->mouse_pos.x, game->mouse_pos.y)) {
         game->music->volume = sfMusic_getVolume(game->music->music1);
         if (game->music->volume - 5 < 0)
             game->music->volume = 0;
         else
             game->music->volume -= 5;
     sfMusic_setVolume(game->music->music1, game->music->volume - 5);
     }
      if (sfFloatRect_contains(&game->btn->btn_muet->bounds,
         game->mouse_pos.x, game->mouse_pos.y) && game->music->m_bool == 0) {
          sfMusic_pause (game->music->music1);
          game->music->m_bool = 1;
      } else if (sfFloatRect_contains(&game->btn->btn_muet->bounds,
         game->mouse_pos.x, game->mouse_pos.y) && game->music->m_bool == 1) {
          sfMusic_play(game->music->music1);
          game->music->m_bool = 0;
      }
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
