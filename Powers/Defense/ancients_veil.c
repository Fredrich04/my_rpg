#include "../weapons.h"
#include "errno.h"

powers_t *voil_ancien(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("Réduit les dégâts subis de 30");
    power->name = strdup("voile ancien");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}