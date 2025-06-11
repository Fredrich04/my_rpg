/*
** EPITECH PROJECT, 2025
** music
** File description:
** music
*/

#include "../include/rpg.h"

void handle_music(sfMusic *music)
{
    if (!music)
        return;
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}
