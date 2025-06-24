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

typedef enum {
    ATTACK,
    DEFENSE,
    EXORCISM,

}type_t;

typedef struct powers {
    int id;
    bool active_state;
    char *comment;
    char *name;
    sfSprite **tab;
    sfSprite *charging_sprite;
    sfVector2u texture_size;
    sfVector2f scale;
    sfTexture *charging_texture;
    sfSprite *middle_sprite;
    sfTexture *middle_texture;
    sfSprite *final_sprite;
    sfTexture *final_texture;
    sfSprite *dissipation_sprite;
    sfTexture *dissipation_texture;
    sfMusic *lauching_song;
    sfText *comment_text;
    int damage;
    int required_manas;
    int side_effects;
    char *level;
    struct powers *next;
    struct powers *prev;
    float delta_time;
} powers_t;

powers_t *ultimate_judgement(void);
powers_t *hunting_hand(void);
powers_t *field_of_exorcist(void);
powers_t *mana_transfusion(void);
powers_t *blade_of_darkness(void);
powers_t *blood_shout(void);
powers_t *spiritual_push(void);
powers_t *voil_ancien(void);
powers_t *suzano_shield(void);
powers_t *untouchable(void);
powers_t *wandering_spirits(void);
#endif
