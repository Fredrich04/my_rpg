/*
11;rgb:3030/0a0a/2424** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void game_initialization(rpg_t *game)
{
    game->window = create_window(false);
}

char **list_env()  {
    char **list = malloc(sizeof(char) * 2);

    list[0] = strdup("environnement/arriere_plan/first_background_1.jpeg");
    list[1] = strdup("environnement/arriere_plan/first_background_2.jpeg");
    return list;
}
void game_loop(rpg_t *game)
{
    player_t player;
    player.position =(sfVector2f){100, 700};
    player.area = (sfIntRect){24, 0, 52, 95};
    sfClock *clock = sfClock_create();
    char **list = list_env();
    int i = 0;
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        my_environnement(list[i], game->window);
        player = mouvement(clock, game->window, player);
        my_envelement((sfVector2f){500, 300}, game->window, (sfVector2f){700,500});
	
	my_envelement((sfVector2f){200, 600}, game->window, (sfVector2f){100,50});
	if (collision(player, (sfVector2f){200, 600}, (sfVector2f){100,50})== true)
	    i = 1;
	my_envelement((sfVector2f){200, 600}, game->window, (sfVector2f){1650,50});
	if (collision(player, (sfVector2f){200, 600}, (sfVector2f){1650,50})== true)
            i = 0;
        sfRenderWindow_display(game->window);
    }
}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
}
