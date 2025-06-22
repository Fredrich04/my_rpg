/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that will handle the drawing of ui during fights
*/
#include "decor.h"

sfCircleShape **draw_ui(void)
{
    sfCircleShape **tab = create_circle_for_powers();
    return tab;
}