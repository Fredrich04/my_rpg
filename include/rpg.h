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
} rpg_t;

character_t *create_main_character_ui(powers_t *powers);
ennemies_t *create_ennemie_ui(void);
void draw_ui(rpg_t *game, character_t *character,
    ennemies_t *ennemies);
void draw_character_ui(rpg_t *game, character_t *character);
void draw_ennemies_ui(rpg_t *game, ennemies_t *ennemies);
powers_t *load_weapons_in_list(powers_t *weapons);

void game_event(rpg_t *game);

void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

sfRenderWindow *create_window(bool fullscreen);

#endif
