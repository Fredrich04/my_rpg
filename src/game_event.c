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
}

void game_event(rpg_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        close_event(game);
        handle_button_event(game->btn->btn_jouer, game);
        handle_button_event(game->btn->btn_options, game);
        handle_button_event(game->btn->btn_credits, game);
        handle_button_event(game->btn->btn_quitter, game);
        if (game->event.type == sfEvtMouseButtonPressed) {
            sfSound_play(game->music->sound_btn);
            main_menu_button_press_event(game);
        }
        // if (game->event.type == sfEvtResized)
        //  button_resize(game, game->btn->btn_jouer);
    }
}

void menu_s_button_event(rpg_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    handle_button_event_s(game->btn->btn_retour, game);
    handle_button_event_s(game->btn->btn_muet, game);
    handle_button_event_s(game->btn->btn_e_size, game);
    handle_button_event_s(game->btn->btn_commande, game);
    handle_button_event_s(game->btn->btn_volume_d, game);
    handle_button_event_s(game->btn->btn_volume_up, game);
    printf("%d\n %d\n", game->mouse_pos.x, game->mouse_pos.y);
}

void menu_s_button_press_event(rpg_t *game)
{
    if (sfFloatRect_contains(&game->btn->btn_retour->bounds,
        game->mouse_pos.x, game->mouse_pos.y))
        game->main_menu->m = 0;
     if (sfFloatRect_contains(&game->btn->btn_volume_up->bounds,
         game->mouse_pos.x, game->mouse_pos.y)) {
         game->music->volume = sfMusic_getVolume(game->music->music1);
         if (game->music->volume + 5 > 100)
             game->music->volume = 100;
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
        // if (game->event.type == sfEvtResized)
            //  button_resize(game, btn);
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
    game->sprite2 = sfSprite_create();
    game->texture2 = sfTexture_createFromFile("assert/menu_s1.png", NULL);
    sfSprite_setTexture(game->sprite2, game->texture2, sfTrue);
    sfSprite_setPosition(game->sprite2, (sfVector2f){-1, -1});
    sfSprite_setScale(game->sprite2, (sfVector2f){0.98, 0.934});
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    while (game->main_menu->m == 1) {
        menu_s_event(game);
        update_menu_s_button(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->sprite2, NULL);
        draw_all_button_s(game);
        sfRenderWindow_display(game->window);
    }
    sfSprite_destroy(game->sprite2);
    sfTexture_destroy(game->texture2);
}

void game_loop(rpg_t *game)
{
    handle_music(game->music->music1);
    game->sprite1 = sfSprite_create();
    game->texture1 = sfTexture_createFromFile("assert/front.png", NULL);
    sfSprite_setTexture(game->sprite1, game->texture1, sfTrue);
    sfSprite_setPosition(game->sprite1, (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        update_button(game->btn->btn_jouer, game->window);
        update_button(game->btn->btn_options, game->window);
        update_button(game->btn->btn_credits, game->window);
        update_button(game->btn->btn_quitter, game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        menu_s(game);
        if (game->main_menu->m == 0)
            sfRenderWindow_drawSprite(game->window, game->sprite1, NULL);
        draw_all_button(game);
        sfRenderWindow_display(game->window);
    }
    sfMusic_stop(game->music->music1);
}
