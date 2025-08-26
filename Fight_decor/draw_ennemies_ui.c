#include "../include/rpg.h"



static void set_mc_texts_features(rpg_t *game)
{
    sfVector2f pv_rectangle_pos = sfRectangleShape_getPosition(game->ennemies->pv_emy);
    sfVector2f pv_text_position = pv_rectangle_pos;
    sfVector2f level_text_position = {pv_text_position.x, pv_text_position.y + 25};
    sfVector2f rank_text_position = {pv_text_position.x, pv_text_position.y + 50};

    sfText_setPosition(game->ennemies->pv_text, pv_text_position);
    sfText_setFillColor(game->ennemies->pv_text, sfGreen);
    sfText_setOutlineThickness(game->ennemies->pv_text, 2.0);
    sfText_setOutlineColor(game->ennemies->pv_text, sfWhite);
    sfText_setCharacterSize(game->ennemies->pv_text, 20);

    sfText_setPosition(game->ennemies->level_text, level_text_position);
    sfText_setFillColor(game->ennemies->level_text, sfGreen);
    sfText_setOutlineThickness(game->ennemies->level_text, 2.0);
    sfText_setOutlineColor(game->ennemies->level_text, sfWhite);
    sfText_setCharacterSize(game->ennemies->level_text, 20);

    sfText_setPosition(game->ennemies->rank_text, rank_text_position);
    sfText_setFillColor(game->ennemies->rank_text, sfGreen);
    sfText_setOutlineThickness(game->ennemies->rank_text, 2.0);
    sfText_setOutlineColor(game->ennemies->rank_text, sfWhite);
    sfText_setCharacterSize(game->ennemies->rank_text, 20);
}

static void display_newly_filled(rpg_t *game)
{
    sfRenderWindow_drawText(game->window, game->ennemies->pv_text, NULL);
    sfRenderWindow_drawText(game->window, game->ennemies->level_text, NULL);
    sfRenderWindow_drawText(game->window, game->ennemies->rank_text, NULL);
}

void updated_filling_ennemy_texts(rpg_t *game)
{
    char *temp = malloc(sizeof(char) * 10000);
    sfText_setString(game->ennemies->rank_text, game->ennemies->rank);
    sprintf(temp, "%d", game->ennemies->pv);
    sfText_setString(game->ennemies->pv_text, temp);
    sprintf(temp, "%d", game->ennemies->level);
    sfText_setString(game->ennemies->level_text, temp);
    free(temp);
    set_mc_texts_features(game);
    display_newly_filled(game);
}


void create_related_to_ennemies_texts(rpg_t *game)
{
    game->ennemies->font = sfFont_createFromFile("./Fight_decor/Namaku.ttf");
    game->ennemies->level_text = sfText_create();
    game->ennemies->rank_text = sfText_create();
    game->ennemies->pv_text = sfText_create();

    printf("\n\n\n\nLet us all realize that the name of the title of the ennemy is %s\n\n", game->ennemies->rank);
    sfText_setFont(game->ennemies->level_text, game->ennemies->font);
    sfText_setFont(game->ennemies->rank_text, game->ennemies->font);
    sfText_setFont(game->ennemies->pv_text, game->ennemies->font);
}

void draw_ennemy_ui_infos(rpg_t *game)
{
    sfRectangleShape *emy_pv = sfRectangleShape_create();
    sfRectangleShape_setPosition(emy_pv, (sfVector2f) {1920 - 270, 8});
    sfRectangleShape_setSize(emy_pv, (sfVector2f) {200, 50});
    sfRectangleShape_setOutlineColor(emy_pv, sfWhite);
    sfRectangleShape_setOutlineThickness(emy_pv, 2.0);
    sfRectangleShape_setFillColor(emy_pv, sfBlack);
    game->ennemies->pv_emy = emy_pv;
}

void spawn_ennemy_for_fight(sfTexture *ennemy_texture, sfSprite *ennemy_sprite)
{
    sfVector2u ennemy_sprite_size;
    sfVector2f ennemy_position;
    sfVector2f ennemy_scale;
    
    ennemy_sprite_size = sfTexture_getSize(ennemy_texture);
    sfSprite_setTexture(ennemy_sprite, ennemy_texture, sfTrue);
    sfSprite_setTextureRect(ennemy_sprite, (sfIntRect) {0, ennemy_sprite_size.y / 2, ennemy_sprite_size.x / 3.5, ennemy_sprite_size.y / 2});
    ennemy_scale = (sfVector2f) {(double)  (1), (double) 1.5};
    ennemy_position = (sfVector2f) {1800 - ennemy_sprite_size.x / 3.5, 950 - (1.5 * (ennemy_sprite_size.y / 2))};
    sfSprite_setScale(ennemy_sprite, ennemy_scale);   
    sfSprite_setPosition(ennemy_sprite, ennemy_position);
}
