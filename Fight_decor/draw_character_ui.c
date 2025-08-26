/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that will handle the drawing of ui during fights
*/

#include "../include/rpg.h"

static void set_mc_texts_features(rpg_t *game)
{
    sfVector2f pv_rectangle_pos = sfRectangleShape_getPosition(game->character->pv_mc);
    sfVector2f pv_text_position = pv_rectangle_pos;
    sfVector2f level_text_position = {pv_text_position.x, pv_text_position.y + 25};
    sfVector2f name_text_position = {pv_text_position.x, pv_text_position.y + 50};

    sfText_setPosition(game->character->pv_text, pv_text_position);
    sfText_setFillColor(game->character->pv_text, sfGreen);
    sfText_setOutlineThickness(game->character->pv_text, 2.0);
    sfText_setOutlineColor(game->character->pv_text, sfWhite);
    sfText_setCharacterSize(game->character->pv_text, 20);

    sfText_setPosition(game->character->level_text, level_text_position);
    sfText_setFillColor(game->character->level_text, sfGreen);
    sfText_setOutlineThickness(game->character->level_text, 2.0);
    sfText_setOutlineColor(game->character->level_text, sfWhite);
    sfText_setCharacterSize(game->character->level_text, 20);

    sfText_setPosition(game->character->name_text, name_text_position);
    sfText_setFillColor(game->character->name_text, sfGreen);
    sfText_setOutlineThickness(game->character->name_text, 2.0);
    sfText_setOutlineColor(game->character->name_text, sfWhite);
    sfText_setCharacterSize(game->character->name_text, 20);
}

static void display_newly_filled(rpg_t *game)
{
    sfRenderWindow_drawText(game->window, game->character->pv_text, NULL);
    sfRenderWindow_drawText(game->window, game->character->level_text, NULL);
    sfRenderWindow_drawText(game->window, game->character->name_text, NULL);
}

void updated_filling_mc_texts(rpg_t *game)
{
    char *temp = malloc(sizeof(char) * 10000);
    sfText_setString(game->character->name_text, game->character->name);
    sprintf(temp, "%d", game->character->pv);
    sfText_setString(game->character->pv_text, temp);
    sprintf(temp, "%d", game->character->level);
    sfText_setString(game->character->level_text, temp);
    free(temp);
    set_mc_texts_features(game);
    display_newly_filled(game);
}

void create_related_to_mc_texts(rpg_t *game)
{
    game->character->font = sfFont_createFromFile("./Fight_decor/Namaku.ttf");
    game->character->pv_text = sfText_create();
    game->character->level_text = sfText_create();
    game->character->name_text = sfText_create();
    
    sfText_setFont(game->character->pv_text, game->character->font);
    sfText_setFont(game->character->level_text, game->character->font);
    sfText_setFont(game->character->name_text, game->character->font);
}

void draw_mc_ui_infos(rpg_t *game)
{
    sfRectangleShape *mc_pv = sfRectangleShape_create();
    sfRectangleShape_setPosition(mc_pv, (sfVector2f) {10, 0});//1080 - 150});
    sfRectangleShape_setSize(mc_pv, (sfVector2f) {200, 150});
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