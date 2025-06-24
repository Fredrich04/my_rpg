#include "../weapons.h"
#include "errno.h"

powers_t *hunting_hand(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Une main, qui chasse les mauvais esprits");
    power->name = strdup("Main chasseuse");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}