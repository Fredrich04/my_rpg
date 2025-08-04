#include "../include/rpg.h"

void spawn_decor(sfSprite *decor_sprite, sfTexture *decor_texture)
{
    sfVector2u decor_sprite_size;
    sfVector2f decor_scale;

    decor_sprite_size = sfTexture_getSize(decor_texture);
    sfSprite_setTexture(decor_sprite, decor_texture, sfTrue);
    decor_scale = (sfVector2f) {(double) 1920 / decor_sprite_size.x, (double) 1080 / decor_sprite_size.y};
    sfSprite_setScale(decor_sprite, decor_scale);
}