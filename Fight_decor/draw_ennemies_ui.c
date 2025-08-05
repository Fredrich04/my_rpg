#include "../include/rpg.h"

void create_related_to_ennemies_texts(rpg_t *game)
{

}

void draw_ennemy_ui_infos(rpg_t *game)
{
    sfRectangleShape *emy_pv = sfRectangleShape_create();
    sfRectangleShape_setPosition(emy_pv, (sfVector2f) {1920 - 270, 8});
    sfRectangleShape_setSize(emy_pv, (sfVector2f) {200, 50});
    sfRectangleShape_setOutlineColor(emy_pv, sfWhite);
    sfRectangleShape_setOutlineThickness(emy_pv, 2.0);
    sfRectangleShape_setFillColor(emy_pv, sfBlack);
    game->ennemies->pv_emy = emy_pv;
}

void spawn_ennemy_for_fight(sfTexture *ennemy_texture, sfSprite *ennemy_sprite)
{
    sfVector2u ennemy_sprite_size;
    sfVector2f ennemy_position;
    sfVector2f ennemy_scale;
    
    ennemy_sprite_size = sfTexture_getSize(ennemy_texture);
    sfSprite_setTexture(ennemy_sprite, ennemy_texture, sfTrue);
    sfSprite_setTextureRect(ennemy_sprite, (sfIntRect) {0, ennemy_sprite_size.y / 2, ennemy_sprite_size.x / 3.5, ennemy_sprite_size.y / 2});
    ennemy_scale = (sfVector2f) {(double)  (1), (double) 1.5};
    ennemy_position = (sfVector2f) {1800 - ennemy_sprite_size.x / 3.5, 950 - (1.5 * (ennemy_sprite_size.y / 2))};
    sfSprite_setScale(ennemy_sprite, ennemy_scale);   
    sfSprite_setPosition(ennemy_sprite, ennemy_position);
}
