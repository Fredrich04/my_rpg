#include "../weapons.h"

powers_t blood_shout(void)
{
    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = "Un cri de vengeance, qui fait littéralement tomber la foudre de xeviosso.";
    power->name = "Cri du sang";
    power->level = "";
    power->required_manas = 0;
    power->damage = 0;
    power->side_effects = 0;
}