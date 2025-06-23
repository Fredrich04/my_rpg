/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that will handle the drawing of ui during fights
*/

#include "../include/rpg.h"

void draw_ui(rpg_t *game, character_t *character,
    ennemies_t *ennemies)
{
    draw_character_ui(game, character);
    draw_ennemies_ui(game, ennemies);
    return;
}