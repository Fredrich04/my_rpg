#include "../weapons.h"

powers_t blade_of_darkness(void)
{
    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = "Une épée spectrale spirituelle apparaît et inflige des dégâts physique et spirituel à l'ennemi";
    power->name = "Lance spirituelle spectrale de chastifol";
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
}