/**
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

void set_close(rpg_t *game)
{
    if (game->main_menu->is_close)
        game->is_close = 1;
}

void sfMouse_getPositionResized(rpg_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    game->mouse_pos.x *= game->new_scale.x;
    game->mouse_pos.y *= game->new_scale.y;
}

void close_event(rpg_t *game)
{
    set_close(game);
    if (game->event.type == sfEvtClosed
        || game->event.key.code == sfKeyEscape || game->is_close) {
        sfRenderWindow_close(game->window);
        destroy_game(game);
        exit(0);
    }
}

void main_menu_button_press_event(rpg_t *game)
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
        sfMouse_getPositionResized(game);
        handle_button_event(game->btn->btn_jouer, game);
        handle_button_event(game->btn->btn_options, game);
        handle_button_event(game->btn->btn_credits, game);
        handle_button_event(game->btn->btn_quitter, game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            main_menu_button_press_event(game);
        }
        if (game->event.type == sfEvtResized) {
            game->newWinSize = (sfVector2f){(float)game->event.size.width, (float)game->event.size.height};
            game->new_scale = (sfVector2f){game->newWinSize.x / game->defaultWinSize.x, game->newWinSize.y / game->defaultWinSize.y};
            sfView_setSize(game->winView, game->newWinSize);
            sfView_setCenter(game->winView, (sfVector2f){game->newWinSize.x / 2.f, game->newWinSize.y / 2.f});
            sfRenderWindow_setView(game->window, game->winView);
            button_resize(game, game->btn->btn_jouer);
            button_resize(game, game->btn->btn_credits);
            button_resize(game, game->btn->btn_options);
            button_resize(game, game->btn->btn_quitter);
            button_resize(game, game->btn->btn_volume_d);
            button_resize(game, game->btn->btn_volume_up);
            button_resize(game, game->btn->btn_e_size);
            button_resize(game, game->btn->btn_retour);
            button_resize(game, game->btn->btn_back_screen);
            button_resize(game, game->btn->btn_back_credit);
        }
    }
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

void game_loop(rpg_t *game)
{
    handle_music(game->music->music1);
    sfSprite_setTexture(game->sprite1, game->texture1, sfTrue);
    sfSprite_setPosition(game->sprite1, (sfVector2f){0, 0});
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
        if (game->main_menu->m == 0)
            sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
        draw_all_button(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
