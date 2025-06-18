#include "../weapons.h"

powers_t blade_of_darkness(void)
{
    powers_t *power = malloc(sizeof(powers_t));

    power->active_state = 0;
    power->comment = "Une point chargé d'énergie spirituelle, qui inflige de lourds dégàts à l'ennemie";
    power->name = "point spirituel de chastifol";
    power->level = "";
    power->required_manas = 50;
    power->side_effects = 0;
}