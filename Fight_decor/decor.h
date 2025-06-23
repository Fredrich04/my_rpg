/*
** EPITECH PROJECT, 2025
** start.h
** File description:
** start.h
*/

#ifndef START_D
  #define START_D

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

typedef struct character {
  powers_t *powers;
  char *rank;
  int level;
  int pv;
  int manas;
  int exp;
  char **all_ranks;
} character_t;

typedef struct ennemies {
  char *rank;
  int level;
  int pv;
} ennemies_t;

#endif