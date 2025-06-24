
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
    return power;
}