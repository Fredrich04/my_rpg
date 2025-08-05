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
    #include "../Powers/weapons.h"
    #include "../Fight_decor/decor.h"

    #define GAME_NAME "Cursed Legacy"

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
    powers_t *powers;
    character_t *character;
    ennemies_t *ennemies;
} rpg_t;

void spawn_mc_for_fighting(sfTexture *mc_texture, sfSprite *mc_sprite);
void spawn_ennemy_for_fight(sfTexture *ennemy_texture, sfSprite *ennemy_sprite);
void spawn_decor(sfSprite *decor_sprite, sfTexture *decor_texture);
void destroy_ennemy_and_mc(sfTexture *mc_t, sfTexture *emy_t, sfSprite *mc_s, sfSprite *emy_s);
void destroy_decor(sfTexture *decor_texture, sfSprite *decor_sprite);
void create_related_to_mc_texts(rpg_t *game);
void updated_filling_mc_texts(rpg_t *game);

void draw_mc_ui_infos(rpg_t *game);
void draw_ennemy_ui_infos(rpg_t *game);
character_t *create_main_character_ui(powers_t *powers);
ennemies_t *create_ennemie_ui(void);
powers_t *load_weapons_in_list(powers_t *weapons);

void game_event(rpg_t *game);
float manage_time(sfClock *clock);
void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

sfRenderWindow *create_window(bool fullscreen);

#endif
