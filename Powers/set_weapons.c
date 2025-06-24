/*
** EPITECH PROJECT, 2025
** set_weapons
** File description:
** The base of the loadable weapons
*/

#include "weapons.h"

static powers_t *create_weapon(void)
{
    powers_t *powers_list = malloc(sizeof(powers_t));

    return powers_list;
}

powers_t *fill_data_part1(powers_t *new, powers_t *to_add)
{
    new->active_state = to_add->active_state;
    new->charging_sprite = to_add->charging_sprite;
    new->charging_texture = to_add->charging_texture;
    new->comment = strdup(to_add->comment);
    new->comment_text = to_add->comment_text;
    new->damage = to_add->damage;
    new->delta_time = to_add->delta_time;
    new->dissipation_sprite = to_add->dissipation_sprite;
    new->dissipation_texture = to_add->dissipation_texture;
    new->final_sprite = to_add->final_sprite;
    new->final_texture = to_add->final_texture;
    return new;
}

powers_t *fill_data_part2(powers_t *new, powers_t *to_add)
{
    new->id = to_add->id;
    new->lauching_song = to_add->lauching_song;
    new->lauching_song = to_add->lauching_song;
    new->level = to_add->level;
    new->middle_sprite = to_add->middle_sprite;
    new->middle_texture = to_add->middle_texture;
    new->name = strdup(to_add->name);
    new->required_manas = to_add->required_manas;
    new->side_effects = to_add->side_effects;
    return new;
}

powers_t *add_weapon(powers_t **head, powers_t *to_add)
{
    powers_t *new = create_weapon();

    new = fill_data_part1(new, to_add);
    new = fill_data_part2(new, to_add);
    if (*head == NULL) {
        new->next = NULL;
        new->prev = NULL;
        *head = new;
    } else {
        new->next = *head;
        new->prev = NULL;
        (*head)->prev = new;
        *head = new;
    }
   // free(to_add->name);
    //free(to_add->comment);
    free(to_add);
    return *head;
}

powers_t *load_weapons_in_list(powers_t *weapons)
{
    weapons = NULL;
    add_weapon(&weapons, ultimate_judgement());
    add_weapon(&weapons, field_of_exorcist());
    add_weapon(&weapons, hunting_hand());
    add_weapon(&weapons, spiritual_push());
    add_weapon(&weapons, blade_of_darkness());
    add_weapon(&weapons, blood_shout());
    add_weapon(&weapons, wandering_spirits());
    add_weapon(&weapons, mana_transfusion());
    add_weapon(&weapons, suzano_shield());
    add_weapon(&weapons, untouchable());
    add_weapon(&weapons, voil_ancien());
    return weapons;
}