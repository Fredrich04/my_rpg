/*
** EPITECH PROJECT, 2025
** start.h
** File description:
** start.h
*/

#ifndef START_H
  #define START_H

    #include <string.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdint.h>
    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <math.h>
    #include <time.h>

    #define GAME_NAME "Cursed Legacy"
    #define SCREEN_WIDTH 1920
    #define SCREEN_HEIGHT 1080

typedef enum {
    NORMAL,
    HOVERED,
    PRESSED,
    RETURNING
} button_state_t;

typedef struct {
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f default_scale;
    sfVector2f final_scale;
    sfVector2f current_scale;
    sfVector2f original_pos;
    float duration;
    float elapsed;
    sfFloatRect bounds;
    button_state_t state;
    sfVector2f echelle;
} button_t;

typedef struct music {
    sfMusic *music1;
    float volume;
    int m_bool;
    sfSound *sound_btn;
    sfSoundBuffer *sound_btn_buf;
} music_t;

typedef struct button_center {
    button_t *btn_jouer;
    button_t *btn_options;
    button_t *btn_credits;
    button_t *btn_quitter;
    button_t *btn_volume_up;
    button_t *btn_volume_d;
    button_t *btn_commande;
    button_t *btn_retour;
    button_t *btn_e_size;
    button_t *btn_muet;
    button_t *btn_back_screen;
    button_t *btn_back_credit;
} button_center_t;

typedef struct main_menu {
    int is_close;
    int m;
} main_menu_t;

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture1;
    sfSprite *sprite1;
    sfVector2i mouse_pos;
    sfTexture *texture2;
    sfSprite *sprite2;
    main_menu_t *main_menu;
    int is_close;
    button_center_t *btn;
    music_t *music;
    sfSprite *sprite_c;
    sfTexture *texture_c;
    sfSprite *sprite_e;
    sfTexture *texture_e;

} rpg_t;

void handle_button_event_credit(button_t *btn, rpg_t *game);
void draw_button_credit(rpg_t *game);
void menu_credit_button_press_event(rpg_t *game);
void menu_credit_button_event(rpg_t *game);
void menu_credit_event(rpg_t *game);
void menu_credit_button(rpg_t *game);
void close_event(rpg_t *game);
void menu_screen_button_press_event(rpg_t *game);
void menu_screen_event(rpg_t *game);
void menu_screen_button_event(rpg_t *game);
void draw_button_screen(rpg_t *game);
void draw_button_screen(rpg_t *game);
void handle_button_event_screen(button_t *btn, rpg_t *game);
void menu_scren_button(rpg_t *game);
void menu_c_event(rpg_t *game);
void credits(rpg_t *game);
void button_resize(rpg_t *game, button_t *btn);
void destroy_button(button_t *btn);
void draw_button(button_t *btn, sfRenderWindow *window);
void handle_button_event_s(button_t *btn, rpg_t *game);
void draw_all_button_s(rpg_t *game);
button_t *create_button(sfTexture *texture, sfVector2f pos, sfVector2f scale);
void update_button(button_t *btn, sfRenderWindow *window);
void draw_all_button(rpg_t *game);
void handle_button_event(button_t *btn, rpg_t *game);
void destroy_all_button(rpg_t *game);

void game_event(rpg_t *game);
void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

void handle_music(sfMusic *music);
sfRenderWindow *create_window(bool fullscreen);

#endif
