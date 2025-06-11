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

typedef struct music {
    sfMusic *music1;
} music_t;

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture1;
    sfSprite *sprite1;
    sfVector2i pos_par;
    sfTexture *texture2;
    sfSprite *sprite2;
    int m;
    music_t *music;
} rpg_t;

void game_event(rpg_t *game);
void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

void handle_music(sfMusic *music);
sfRenderWindow *create_window(bool fullscreen);

#endif
