#include "../weapons.h"
#include "errno.h"

powers_t *suzano_shield(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Invoque le suzano sur le personnage");
    power->name = strdup("Bouclier du suzano");
    power->level = "";
    power->required_manas = 0;
    power->side_effects = 0;
    return power;
}