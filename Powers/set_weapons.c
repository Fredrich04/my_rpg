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
    new->delta_time = to_add->delta_time;
    new->damage = to_add->damage;
    new->level = strdup(to_add->level);
    new->active_state = to_add->active_state;
    new->comment = strdup(to_add->comment);
    new->weapon_sprite = to_add->weapon_sprite;
    new->weapon_texture = to_add->weapon_texture;
    return new;
}

powers_t *fill_data_part2(powers_t *new, powers_t *to_add)
{
    new->inventory_sprite = to_add->inventory_sprite;
    new->inventory_texture = to_add->inventory_texture;
    new->stuff_texture = to_add->stuff_texture;
    new->stuff_sprite = to_add->stuff_sprite;
    new->scale_on_stuff = to_add->scale_on_stuff;
    sfSprite_setTexture(new->inventory_sprite, new->inventory_texture, sfTrue);
    sfSprite_setTexture(new->stuff_sprite, new->stuff_texture, sfTrue);
    new->name = strdup(to_add->name);
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
    free(to_add->name);
    free(to_add->comment);
    free(to_add);
    return *head;
}

powers_t *load_weapons_in_list(powers_t *weapons)
{
    weapons = NULL;
    return weapons;
}