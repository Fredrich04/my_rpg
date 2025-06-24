#include "../weapons.h"
#include "errno.h"

powers_t *mana_transfusion(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Transforme la moitiée des pv en manas");
    power->name = strdup("Transfusion de mana");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}