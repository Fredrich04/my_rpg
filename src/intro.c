
#include "../include/rpg.h"

typedef struct intro {
    sfRenderWindow *w;
    sfEvent event;
    sfSprite *batteur;
    sfIntRect batteur_cadre;
    sfTexture *batteur_txt;
    sfSprite *logo[4];
} intro_t;

int main(void)
{
    intro_t *intro = malloc(sizeof(intro_t));

    intro->w = create_window(false);
    intro->batteur = sfSprite_create();
    intro->batteur_txt = sfTexture_createFromFile("../asserts/batteur.jpeg", NULL);
    sfSprite_setTexture(intro->batteur, intro->batteur_txt, sfTrue);
    intro->batteur_cadre = (sfIntRect){0, 0, 256, 256};
    sfSprite_setTextureRect(intro->batteur, intro->batteur_cadre);
    while (sfRenderWindow_isOpen(intro->w)) {
        while (sfRenderWindow_pollEvent(intro->w, &intro->event))
            if (intro->event.type == sfEvtClosed)
                sfRenderWindow_close(intro->w);
        sfRenderWindow_clear(intro->w, sfBlack);
        sfRenderWindow_drawSprite(intro->w, intro->batteur, NULL);
        sfRenderWindow_display(intro->w);
    }
}