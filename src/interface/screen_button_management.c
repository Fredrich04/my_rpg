/*
** EPITECH PROJECT, 2025
** bsm
** File description:
** bsm
*/

#include "../../include/rpg.h"

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
    draw_button(game->btn->btn_size1, game->window);
    draw_button(game->btn->btn_size2, game->window);
    draw_button(game->btn->btn_size3, game->window);
}

void menu_screen_button_press_event_part1(rpg_t *game)
{
    game->is_fullscreen = false;
    game->resize_window = false;
    if (sfFloatRect_contains(&game->btn->btn_back_screen->bounds,
        game->mouse_pos.x, game->mouse_pos.y)) {
        game->main_menu->m = 0;
        game->is_resize = false;
        return;
    }
    if (sfFloatRect_contains(&game->btn->btn_size1->bounds,
        game->mouse_pos.x, game->mouse_pos.y)) {
        game->is_fullscreen = true;
        game->resize_window = true;
    }
    if (sfFloatRect_contains(&game->btn->btn_size2->bounds,
        game->mouse_pos.x, game->mouse_pos.y)) {
        game->is_fullscreen = false;
        game->resize_window = true;
    }
}

void menu_screen_button_press_event(rpg_t *game)
{
    sfVector2u new_size = (sfVector2u){0, 0};

    menu_screen_button_press_event_part1(game);
    if (sfFloatRect_contains(&game->btn->btn_size3->bounds,
        game->mouse_pos.x, game->mouse_pos.y)) {
        game->is_fullscreen = false;
        new_size = (sfVector2u){1780, 920};
        game->resize_window = true;
        sfView_destroy(game->winView);
    }
    if (game->resize_window) {
        sfRenderWindow_destroy(game->window);
        game->window = create_window(game->is_fullscreen, new_size);
        game->is_resize = true;
    }
}

void resize_button(rpg_t *game)
{
    button_resize(game, game->btn->btn_jouer);
    button_resize(game, game->btn->btn_credits);
    button_resize(game, game->btn->btn_options);
    button_resize(game, game->btn->btn_quitter);
    button_resize(game, game->btn->btn_volume_d);
    button_resize(game, game->btn->btn_volume_up);
    button_resize(game, game->btn->btn_commande);
    button_resize(game, game->btn->btn_muet);
    button_resize(game, game->btn->btn_e_size);
    button_resize(game, game->btn->btn_retour);
    button_resize(game, game->btn->btn_back_screen);
    button_resize(game, game->btn->btn_back_credit);
    button_resize(game, game->btn->btn_size1);
    button_resize(game, game->btn->btn_size2);
    button_resize(game, game->btn->btn_size3);
}

void menu_screen_button_event(rpg_t *game)
{
    sfMouse_getPositionResized(game);
    handle_button_event_screen(game->btn->btn_back_screen, game);
    handle_button_event_screen(game->btn->btn_size1, game);
    handle_button_event_screen(game->btn->btn_size2, game);
    handle_button_event_screen(game->btn->btn_size3, game);
    if (game->event.type == sfEvtMouseButtonPressed) {
        sfSound_play(game->music->sound_btn);
        menu_screen_button_press_event(game);
    }
    if (game->is_resize) {
        game->winSize = sfRenderWindow_getSize(game->window);
        game->newWinSize = (sfVector2f){(float)game->winSize.x,
            (float)game->winSize.y};
        game->new_scale = (sfVector2f){game->newWinSize.x /
            game->defaultWinSize.x, game->newWinSize.y /
            game->defaultWinSize.y};
        game->view_rect = (sfFloatRect){0, 0, game->newWinSize.x,
            game->newWinSize.y};
        game->winView = sfView_createFromRect(game->view_rect);
        sfView_setCenter(game->winView, (sfVector2f){game->newWinSize.x / 2.f,
            game->newWinSize.y / 2.f});
        sfRenderWindow_setView(game->window, game->winView);
        resize_button(game);
    }
    game->is_resize = false;
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
    while (game->main_menu->m == 3) {
        sfSprite_setScale(game->sprite_e, game->new_scale);
        menu_screen_event(game);
        update_button(game->btn->btn_back_screen, game->window);
        update_button(game->btn->btn_size1, game->window);
        update_button(game->btn->btn_size2, game->window);
        update_button(game->btn->btn_size3, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite_e, NULL);
        draw_button_screen(game);
        sfRenderWindow_display(game->window);
    }
}
