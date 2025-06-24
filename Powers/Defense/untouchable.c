#include "../weapons.h"
#include "errno.h"

powers_t *untouchable(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Active l'invincibilité pendant deux minutes");
    power->name = strdup("L'intouchable");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}