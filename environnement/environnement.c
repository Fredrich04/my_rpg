#include"../include/rpg.h"

void my_envelement(sfVector2f size, sfRenderWindow *wind, sfVector2f position)
{
    sfRectangleShape *arriere_plan = sfRectangleShape_create();
    sfRectangleShape_setFillColor(arriere_plan, sfTransparent);
    sfRectangleShape_setOutlineColor(arriere_plan, sfWhite);
    sfRectangleShape_setOutlineThickness(arriere_plan, 10);
    sfRectangleShape_setPosition(arriere_plan, position);
    sfRectangleShape_setSize(arriere_plan,(sfVector2f){(float)size.x, (float)size.y});
   // sfRenderWindow_drawRectangleShape(wind, arriere_plan, NULL);
}

void my_environnement(char *filename, sfRenderWindow *wind)
{
    sfTexture *fond = sfTexture_createFromFile(filename, NULL);
    sfRectangleShape *arriere_plan = sfRectangleShape_create();
    sfVector2u size = sfRenderWindow_getSize(wind);
    sfView* view = sfView_create();
    sfView_setSize (view, (sfVector2f){(float)size.x, (float)size.y});
    //sfRenderWindow_setView(wind, view);
    //sfView_setRotation(view,0.8);
   // sfRenderWindow_setView(wind, view);
    sfRectangleShape_setSize(arriere_plan,(sfVector2f){(float)size.x, (float)size.y});
    sfRectangleShape_setTexture(arriere_plan, fond, sfTrue);
    //sfRenderWindow_drawRectangleShape(wind, arriere_plan, NULL);
    sfRectangleShape_destroy(arriere_plan);
    sfTexture_destroy(fond);
}

player_t righ_mouvement(sfIntRect area, sfClock *clock, player_t player)
{
    static int r = 0;
    sfTime mov_frame = sfClock_getElapsedTime (clock);
    float scond = sfTime_asSeconds(mov_frame);

    // if (player.area.left < 408/*player.area.width*6 && r < 7*/ && scond > 0.1) {
    if (scond > 0.1) {
	player.area.left += 52;
	if (player.area.left >= 388) {
	    player.area.left = 24;
        puts("oky");
        printf("%d", r);
    //    sfClock_restart(clock);
	    r = 0;
	}
	printf("[%d]\n", player.area.left);
        r++;
	 sfClock_restart(clock);
    }// else /*if (r >= 6)*/ {
    //  player.area.left = 0;
    //    r = 0;
    // }
    return player;
}

bool collision(player_t player,  sfVector2f size, sfVector2f position) {
   if (player.position.x >= position.x+ size.x
    || player.position.x + 300 <=  position.x
        || player.position.y >= position.y + size.y                 
        || player.position.y + 300 <= position.y) {
       return false;
        }
   return true;
}

player_t mouvement(sfClock *clock, sfRenderWindow *wind, player_t player)
{
    int a = 1;
    sfVector2u size = sfRenderWindow_getSize(wind);

    /*if (player.position.x >= 600+1000 
    || player.position.x + 300 <= 600
	|| player.position.y >= 200+ 600
        || player.position.y + 300 <= 200) {
	a = 1;
        //my_player("environnement/arriere_plan/player_frame.png", wind, player);
        //return player;
	}*/
    if (sfKeyboard_isKeyPressed(sfKeyRight) && a == 1) {
        player.position.x += 5;
	player = righ_mouvement(player.area, clock, player);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && a == 1) {
        player.position.x -= 5;
        //a = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) && a == 1 && player.position.y >= size.y/2 -200) {
        player.position.y -= 5;
        a = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) && a == 1) {
        player.position.y += 5;
        a = 1;
    }
/*    if (player.position.x >= 600+1000
    || player.position.x + 300 <= 600
        || player.position.y >= 200+ 600
        || player.position.y + 300 <= 200) {
        a = 1;
        //my_player("environnement/arriere_plan/player_frame.png", wind, player);
        //return player;
	}*/

    my_player("environnement/arriere_plan/player_frame.png", wind, player);
    return player;
}

player_t my_player(char *filename, sfRenderWindow *wind, player_t player)
{
//     sfIntRect area = {0, 0, 80, 100};
     sfTexture *fond = sfTexture_createFromFile(filename, NULL);
     sfRectangleShape *arriere_plan = sfRectangleShape_create();
     sfVector2u size = {216, 320};
     sfVector2u siz = sfRenderWindow_getSize(wind);
     if (player.position.x < siz.x && player.position.y < siz.y/*&& player.position.y > siz.y/2*/)
	 sfRectangleShape_setOutlineColor(arriere_plan, sfWhite);
        sfRectangleShape_setPosition(arriere_plan, player.position);
//sfRectangleShape_setOutlineThickness(arriere_plan, 10);
//position = mouvement(position, arriere_plan, wind, area);
     sfRectangleShape_setSize(arriere_plan,(sfVector2f){(float)size.x, (float)size.y});
     sfRectangleShape_setTexture(arriere_plan, fond, sfTrue);
     sfRectangleShape_setTextureRect(arriere_plan, player.area);
     sfRectangleShape_rotate(arriere_plan, 4);
     sfRenderWindow_drawRectangleShape(wind, arriere_plan, NULL);
     sfRectangleShape_destroy(arriere_plan);
     sfTexture_destroy(fond);
     return player;
}
