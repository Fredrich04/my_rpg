/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

sfRenderWindow *create_window(bool fullscreen, sfVector2u size)
{
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    sfUint32 style = fullscreen ? sfFullscreen : (sfClose);

    if (size.x != 0 && size.y != 0) {
        mode.height = size.y;
        mode.width = size.x;
    }
    return sfRenderWindow_create(mode, GAME_NAME, style, NULL);
}
