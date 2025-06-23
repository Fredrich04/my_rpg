/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void init_sounds(rpg_t *game)
{
    game->music->music1 = sfMusic_createFromFile(
        "assert/music/music_epic.mp3");
    game->music->m_bool = 0;
    game->music->sound_btn = sfSound_create();
    game->music->sound_btn_buf = sfSoundBuffer_createFromFile(
        "assert/music/menu_sounds.wav");
    sfSound_setBuffer(game->music->sound_btn, game->music->sound_btn_buf);
}

void init_main_menu_bachground(rpg_t *game)
{
    game->sprite1 = sfSprite_create();
    game->texture1 = sfTexture_createFromFile("assert/main menu/front.png",
        NULL);
    sfSprite_setTexture(game->sprite1, game->texture1, sfTrue);
    game->sprite2 = sfSprite_create();
    game->texture2 = sfTexture_createFromFile("assert/option/menu_s1.png",
        NULL);
    sfSprite_setTexture(game->sprite2, game->texture2, sfTrue);
    sfSprite_setPosition(game->sprite2, (sfVector2f){-1, -1});
    sfSprite_setScale(game->sprite2, (sfVector2f){0.98, 0.934});
    game->sprite_c = sfSprite_create();
    game->texture_c = sfTexture_createFromFile("assert/credit/credits.jpg",
        NULL);
    sfSprite_setTexture(game->sprite_c, game->texture_c, sfTrue);
    game->sprite_e = sfSprite_create();
    game->texture_e = sfTexture_createFromFile("assert/option/screen.png",
        NULL);
    sfSprite_setTexture(game->sprite_e, game->texture_e, sfTrue);
}

void game_initialization(rpg_t *game)
{
    game->music = malloc(sizeof(music_t));
    game->btn = malloc(sizeof(button_center_t));
    game->main_menu = malloc(sizeof(main_menu_t));
    game->window = create_window(false, (sfVector2u){0, 0});
    game->winView = (sfView *)sfRenderWindow_getView(game->window);
    game->defaultWinSize = (sfVector2f){1920.0f, 1080.0f};
    game->new_scale = (sfVector2f){1, 1};
    game->main_menu->m = 0;
    game->is_resize = false;
    game->main_menu->is_close = 0;
    game->is_close = 0;
    load_frames(game);
    init_button(game);
    game->mouse_pos = (sfVector2i){0, 0};
    init_main_menu_bachground(game);
    init_sounds(game);
}

void destroy_all_button(rpg_t *game)
{
    destroy_button(game->btn->btn_jouer);
    destroy_button(game->btn->btn_options);
    destroy_button(game->btn->btn_credits);
    destroy_button(game->btn->btn_quitter);
    destroy_button(game->btn->btn_commande);
    destroy_button(game->btn->btn_e_size);
    destroy_button(game->btn->btn_retour);
    destroy_button(game->btn->btn_volume_d);
    destroy_button(game->btn->btn_volume_up);
    destroy_button(game->btn->btn_back_screen);
    destroy_button(game->btn->btn_back_credit);
    destroy_button(game->btn->btn_size1);
    destroy_button(game->btn->btn_size2);
    destroy_button(game->btn->btn_size3);
    free(game->btn);
}

void destroy_game(rpg_t *game)
{
    sfSprite_destroy(game->sprite1);
    sfTexture_destroy(game->texture1);
    sfSprite_destroy(game->sprite_c);
    sfTexture_destroy(game->texture_c);
    sfSprite_destroy(game->sprite_e);
    sfTexture_destroy(game->texture_e);
    sfSprite_destroy(game->sprite2);
    sfTexture_destroy(game->texture2);
    destroy_all_button(game);
    destroy_loading(game);
    sfRenderWindow_destroy(game->window);
    sfMusic_destroy(game->music->music1);
    sfSound_destroy(game->music->sound_btn);
    sfSoundBuffer_destroy(game->music->sound_btn_buf);
    destroy_loading(game);
    free(game->music);
    free(game);
}
