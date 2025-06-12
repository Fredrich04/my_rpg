/*
** EPITECH PROJECT, 2025
** MY_WORLD
** File description:
** macro file.
*/

#ifndef HEADER_H_
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window/Export.h>
    #include <SFML/Window/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Types.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #define HEADER_H_

typedef struct powers {
    int id;
    bool active_state;
    char *comment;
    char *name;
    sfText *comm;
    sfTexture *weapon_texture;
    sfSprite *weapon_sprite;
    sfSprite *inventory_sprite;
    sfTexture *inventory_texture;
    sfSprite *stuff_sprite;
    sfTexture *stuff_texture;
    sfVector2f scale_on_stuff;
    sfVector2f position_on_stuff;
    int damage;
    char *level;
    struct powers *next;
    struct powers *prev;
    float delta_time;
} powers_t;

#endif
