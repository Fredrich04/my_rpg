#include "../include/rpg.h"

void destroy_ennemy_and_mc(sfTexture *mc_t, sfTexture *emy_t, sfSprite *mc_s, sfSprite *emy_s)
{
    sfTexture_destroy(mc_t);
    sfSprite_destroy(mc_s);
    sfTexture_destroy(emy_t);
    sfSprite_destroy(emy_s);
}

void destroy_decor(sfTexture *decor_texture, sfSprite *decor_sprite)
{
    sfTexture_destroy(decor_texture);
    sfSprite_destroy(decor_sprite);
}
