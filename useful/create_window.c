/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

sfRenderWindow *create_window(bool fullscreen)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfUint32 style = fullscreen ? sfFullscreen : (sfResize | sfClose);

    return sfRenderWindow_create(mode, GAME_NAME, style, NULL);
}
