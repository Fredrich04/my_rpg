
#include "../weapons.h"
#include "errno.h"

powers_t *ultimate_judgement(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Appelle la colère divine, exorcise tout sur le champ de bataille");
    power->name = strdup("Jugement ultime des dieux");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
   // power->charging_sprite = sfSprite_create();
    power->charging_texture = sfTexture_createFromFile("./Powers/global_images/load_judgements.png", NULL);
    //power->middle_sprite = sfSprite_create();
    //power->middle_texture = sfTexture_createFromFile("./Powers/global_images/end_judgements.png", NULL);
    //power->dissipation_sprite = sfSprite_create();
    //power->dissipation_texture = sfTexture_createFromFile("./Powers/global_images/dissipate_judgements.png", NULL);
   
   
    power->tab = malloc(sizeof(sfSprite *) * 3);
    (power->tab)[0] = (sfSprite *) sfSprite_create();
    power->charging_texture = sfTexture_createFromFile("./Powers/global_images/load_judgements.png", NULL);
    sfSprite_setTexture(power->tab[0], power->charging_texture, sfTrue);
    power->texture_size = sfTexture_getSize(power->charging_texture);
    power->scale = (sfVector2f){(double)1920 / power->texture_size.x, (double)1080 / power->texture_size.y};
    sfSprite_setScale(power->tab[0], power->scale);
     (power->tab)[1] = sfSprite_create();
    sfSprite_setTexture(power->tab[1], power->middle_texture, sfTrue);
    power->texture_size = sfTexture_getSize(power->middle_texture);
    power->scale = (sfVector2f){(double)1920 / power->texture_size.x, (double)1080 / power->texture_size.y};
    sfSprite_setScale(power->middle_sprite, power->scale);
    (power->tab)[2] = sfSprite_create();
     sfSprite_setTexture(power->tab[2], power->final_texture, sfTrue);
      power->texture_size = sfTexture_getSize(power->final_texture);
    power->scale = (sfVector2f){(double)1920 / power->texture_size.x, (double)1080 / power->texture_size.y};
    sfSprite_setScale(power->final_sprite, power->scale);
    return power;
}