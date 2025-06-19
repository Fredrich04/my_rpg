/*
** EPITECH PROJECT, 2025
** start.h
** File description:
** start.h
*/

#ifndef START_H
  #define START_H

    #include <SFML/OpenGL.h>
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
    #define INTRO_FRAME 52

typedef struct intro {
    sfSprite *sprite[INTRO_FRAME];
    sfTexture *txt[INTRO_FRAME];
    sfClock *clock, *man_clock, *play_clock;
    float time, man_time, play_time, play_duration;
    sfSprite *tambour, *man, *playing;
    sfTexture *tambour_txt, *man_txt, *playing_txt;
    sfIntRect walk, play;
} intro_t;

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
    intro_t *intro;
} rpg_t;


void load_intro_frames(rpg_t *game);
void play_intro(rpg_t *game);

void close_event(rpg_t *game);
void game_event(rpg_t *game);

void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

sfRenderWindow *create_window(bool fullscreen);

#endif
