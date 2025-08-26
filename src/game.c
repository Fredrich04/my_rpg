/*
** EPITECH PROJECT, 2025
** game main file
** File description:
** game main file
*/

#include "../include/rpg.h"

void game_initialization(rpg_t *game)
{
    game->window = create_window(false);
    game->powers = NULL;
}

void game_loop(rpg_t *game)
{
    sfSprite *decor_sprite = sfSprite_create();
    sfSprite *mc_sprite = sfSprite_create();
    sfSprite *ennemy_sprite = sfSprite_create();
    sfTexture *decor_texture = sfTexture_createFromFile("./src/fight_env.jpeg", NULL);
    sfTexture *mc_texture = sfTexture_createFromFile("./src/mc_fight.png", NULL);
    sfTexture *ennemy_texture = sfTexture_createFromFile("./src/ennemy.png", NULL);
    
    game->character = create_main_character_ui(game->powers);
    game->ennemies = create_ennemie_ui();    
    spawn_decor(decor_sprite, decor_texture);
    spawn_ennemy_for_fight(ennemy_texture, ennemy_sprite);
    spawn_mc_for_fighting(mc_texture, mc_sprite);
    draw_mc_ui_infos(game);
    draw_ennemy_ui_infos(game);
    create_related_to_mc_texts(game);
    create_related_to_ennemies_texts(game);
    while (sfRenderWindow_isOpen(game->window)) {
        game_event(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, decor_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, mc_sprite, NULL);
        sfRenderWindow_drawSprite(game->window, ennemy_sprite, NULL);
        sfRenderWindow_drawRectangleShape(game->window, game->character->pv_mc, NULL);
        sfRenderWindow_drawRectangleShape(game->window, game->ennemies->pv_emy, NULL);
        updated_filling_mc_texts(game);
        updated_filling_ennemy_texts(game);
        sfRenderWindow_display(game->window);
    }
    sfRectangleShape_destroy(game->character->pv_mc);
    sfRectangleShape_destroy(game->ennemies->pv_emy);
    destroy_ennemy_and_mc(mc_texture, ennemy_texture, mc_sprite, ennemy_sprite);
    destroy_decor(decor_texture, decor_sprite);

}

void destroy_game(rpg_t *game)
{
    sfRenderWindow_destroy(game->window);
    // sfText_destroy(game->character->level_text);
    // sfText_destroy(game->character->pv_text);
    // sfText_destroy(game->character->name_text);
    // sfFont_destroy(game->character->font);
}
