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

typedef struct rpg {
    sfRenderWindow *window;
    sfEvent event;
} rpg_t;

typedef struct player {
    sfVector2f position;
    sfIntRect area;
    sfClock *clock;
} player_t;

typedef struct objet {
    sfVector2f position;
    sfVector2f size;
} objet_t;

void my_envelement(sfVector2f size, sfRenderWindow *wind, sfVector2f position);
player_t mouvement(sfClock *clock, sfRenderWindow *wind, player_t player);
bool collision(player_t player,  sfVector2f size, sfVector2f position);
void game_event(rpg_t *game);

void game_initialization(rpg_t *game);
void destroy_game(rpg_t *game);
void game_loop(rpg_t *game);

sfRenderWindow *create_window(bool fullscreen);

player_t my_player(char *filename, sfRenderWindow *wind, player_t player);
void my_environnement(char *filename, sfRenderWindow *wind);
#endif
