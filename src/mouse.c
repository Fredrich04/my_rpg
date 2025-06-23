/*
** EPITECH PROJECT, 2025
** mouse
** File description:
** mouse
*/

#include "../include/rpg.h"

void sfmouse_get_position_resized(rpg_t *game)
{
    game->mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    game->mouse_pos.x *= game->new_scale.x;
    game->mouse_pos.y *= game->new_scale.y;
}
