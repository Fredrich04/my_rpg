/*
** EPITECH PROJECT, 2025
** bsm
** File description:
** bsm
*/

#include "../include/rpg.h"


static void pressed_and_hovered_detection_screen(button_t *btn, rpg_t *game,
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

static void pressed_and_hovered_action_screen(button_t *btn, rpg_t *game,
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

void handle_button_event_screen(button_t *btn, rpg_t *game)
{
    sfBool is_hovered;

    btn->bounds = sfSprite_getGlobalBounds(btn->sprite);
    btn->bounds.height *= game->new_scale.y;
    btn->bounds.left *= game->new_scale.x;
    btn->bounds.top *= game->new_scale.y;
    btn->bounds.width *= game->new_scale.x;
    is_hovered = sfFloatRect_contains(&btn->bounds, game->mouse_pos.x,
        game->mouse_pos.y);
    pressed_and_hovered_detection_screen(btn, game, is_hovered);
    pressed_and_hovered_action_screen(btn, game, is_hovered);
}

void draw_button_screen(rpg_t *game)
{
    draw_button(game->btn->btn_back_screen, game->window);
}

void menu_screen_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_back_screen->bounds,
	game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 0;
}

void menu_screen_button_event(rpg_t *game)
{
    sfMouse_getPositionResized(game);
    handle_button_event_screen(game->btn->btn_back_screen, game);
     if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            menu_screen_button_press_event(game);
        }
}

void menu_screen_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
	    close_event(game);
        menu_screen_button_event(game);
    }
}

void menu_scren_button(rpg_t *game)
{
    sfSprite_setScale(game->sprite_e, game->new_scale);
    while (game->main_menu->m == 3) {
        menu_screen_event(game);
        update_button(game->btn->btn_back_screen, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite_e, NULL);
        draw_button_screen(game);
        sfRenderWindow_display(game->window);
    }
}
