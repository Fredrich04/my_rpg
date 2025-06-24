#include "../weapons.h"
#include "errno.h"

powers_t *wandering_spirits(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Invoque un esprit errant qui comb at aux côtés du personnage");
    power->name = strdup("Esprit errant");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}