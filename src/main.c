/*
** EPITECH PROJECT, 2025
** main file
** File description:
** main file
*/

#include "../include/rpg.h"

int main(void)
{
    rpg_t *game = malloc(sizeof(rpg_t));
  
    game_initialization(game);
    game->powers = load_weapons_in_list(game->powers);
    game_loop(game);
    destroy_game(game);
    return 0;
}
