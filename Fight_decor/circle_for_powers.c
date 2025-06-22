/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that hand
*/

#include "decor.h"

void draw_circle_for_powers(sfRenderWindow *window, sfCircleShape **tab)
{
    int l = 0;
    while (l < 4) {
    sfRenderWindow_drawCircleShape(window, tab[l], NULL);
        l++;
    }
}

sfCircleShape **create_circle_for_powers(void)
{
    sfCircleShape **circles_tab = malloc(sizeof(sfCircleShape *) * 4);
    int x = 0;
    sfVector2f pos = {1920 - (70 * 5), 800};

    while (x < 4) {
        circles_tab[x] = sfCircleShape_create();
        sfCircleShape_setRadius(circles_tab[x], 35);
        sfCircleShape_setOutlineColor(circles_tab[x], sfGreen);
        sfCircleShape_setFillColor(circles_tab[x], sfTransparent);
        sfCircleShape_setOutlineThickness(circles_tab[x], 2.5);
        sfCircleShape_setPosition(circles_tab[x], pos);
        pos.x = pos.x + 70;
        x++;
    }
    return circles_tab;
}