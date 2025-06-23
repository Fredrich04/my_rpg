/*
** EPITECH PROJECT, 2025
** draw_ui
** File description:
** A file that will handle the drawing of ui during fights
*/
#include "decor.h"

character_t *create_main_character_ui(powers_t *powers)
{
    character_t *characters = malloc(sizeof(character_t));

    characters->exp = 0;
    characters->level = 1;
    characters->all_ranks = malloc(sizeof(char *) * 8);
    characters->all_ranks[0] = strdup("Profane");
    characters->all_ranks[1] = strdup("Initié");
    characters->all_ranks[2] = strdup("Exorciste errant");
    characters->all_ranks[3] = strdup("Apôtre du voile");
    characters->all_ranks[4] = strdup("Gardien du Pacte");
    characters->all_ranks[5] = strdup("Héritier Sacrificiel");
    characters->all_ranks[6] = strdup("Prophète Oublié");
    characters->all_ranks[7] = strdup("Gardien des âmes");
    characters->all_ranks[8] = NULL;
    characters->rank = characters->all_ranks[0];
    characters->manas = 0;
    characters->pv = 100;
    characters->powers = powers;
    return characters;
}

ennemies_t *create_ennemie_ui(void)
{
    ennemies_t *ennemies = malloc(sizeof (ennemies_t));

    ennemies->level = 50;
    ennemies->pv = 1000;
    ennemies->rank = "Loas de niveau Intermédiaire";
    return ennemies;
}