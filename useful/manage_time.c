/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

float manage_time(sfClock *clock)
{
    float secs = 0.0;
    sfTime time = {0};

    time = sfClock_getElapsedTime(clock);
    secs = sfTime_asSeconds(time);
    return secs;
}