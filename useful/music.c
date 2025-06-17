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
    sfMusic_setVolume(music, /*game->music->volume*/80);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
}
