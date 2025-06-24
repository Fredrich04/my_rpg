#include "../weapons.h"
#include "errno.h"

powers_t *field_of_exorcist(void)
{

    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = strdup("L'équivalent de Adan, provoque le hessi chez l'ennemie");
    power->name = strdup("Domaine de l'exorciste");
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
    return power;
}