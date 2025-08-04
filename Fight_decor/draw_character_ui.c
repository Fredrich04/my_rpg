/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that will handle the drawing of ui during fights
*/

#include "../include/rpg.h"

void draw_mc_ui_infos(rpg_t *game)
{
    sfRectangleShape *mc_pv = sfRectangleShape_create();
    sfRectangleShape_setPosition(mc_pv, (sfVector2f) {10, 1080 - 150});
    sfRectangleShape_setSize(mc_pv, (sfVector2f) {200, 50});
    sfRectangleShape_setOutlineColor(mc_pv, sfWhite);
    sfRectangleShape_setOutlineThickness(mc_pv, 2.0);
    sfRectangleShape_setFillColor(mc_pv, sfBlack);
    game->character->pv_mc = mc_pv;
}

void spawn_mc_for_fighting(sfTexture *mc_texture, sfSprite *mc_sprite)
{
    sfVector2u mc_sprite_size;
    sfVector2f mc_position;
    sfVector2f mc_scale;

    mc_sprite_size = sfTexture_getSize(mc_texture);
    sfSprite_setTexture(mc_sprite, mc_texture, sfTrue);
    sfSprite_setTextureRect(mc_sprite, (sfIntRect) {0, 0, mc_sprite_size.x / 3, mc_sprite_size.y});
    mc_scale = (sfVector2f) {(double)  (mc_sprite_size.x / 3) / 200, (double) (mc_sprite_size.y) / 350};
    mc_position = (sfVector2f) {0, 900 - (double) (mc_sprite_size.y) * (mc_sprite_size.y) / 350};
    sfSprite_setPosition(mc_sprite, mc_position);
    sfSprite_setScale(mc_sprite, mc_scale);
 }