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
    powers_t *test = game->powers;
    while (test != NULL) {
        printf("The current loading weapon is %s\n", test->name);
        test = test->next;
    }
   // printf("The current loading weapon is %s\n", game->powers->comment);
    game_loop(game);
    destroy_game(game);
    return 0;
}
