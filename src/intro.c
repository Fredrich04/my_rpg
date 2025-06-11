#include "../include/rpg.h"

#define ASTRE_COUNT 5

typedef struct {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f target;
    float speed;
    float angle;
    float radius;
    sfFloatRect bounds;
    sfVector2f center;
    int finished;
} Astre;

void update_orbit(Astre *a, float dt) 
{
    a->angle += 30.f * dt;
    if (a->angle > 360.f)
        a->angle -= 360.f;
    if (a->radius > 5.f)
        a->radius -= a->speed * dt * 0.2f;
    a->position.x = a->center.x + cos(a->angle * M_PI / 180.f) * a->radius;
    a->position.y = a->center.y + sin(a->angle * M_PI / 180.f) * a->radius;
    sfSprite_setPosition(a->sprite, a->position);
}

int main() {
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = create_window(false);
    sfRenderWindow_setFramerateLimit(window, 60);

   // sfTexture *bgTex = sfTexture_createFromFile("background.png", NULL);
  //  sfSprite *bgSprite = sfSprite_create();
//    sfSprite_setTexture(bgSprite, bgTex, sfTrue);

    const char *files[ASTRE_COUNT] = {
        "sun.png", "p1.png", "p2.png", "p3.png", "p4.png"
    };

    Astre astres[ASTRE_COUNT];
    float centerY = 360.f;
    float spacing = 150.f;


    for (int i = 0; i < ASTRE_COUNT; i++) {
    astres[i].texture = sfTexture_createFromFile(files[i], NULL);
    astres[i].sprite = sfSprite_create();
    sfSprite_setTexture(astres[i].sprite, astres[i].texture, sfTrue);
    astres[i].bounds = sfSprite_getLocalBounds(astres[i].sprite);
    sfSprite_setOrigin(astres[i].sprite, (sfVector2f){astres[i].bounds.width / 2.0f, astres[i].bounds.height / 2.0f});
    astres[i].target = (sfVector2f){400.f + i * spacing, centerY};
    astres[i].center = astres[i].target;
    astres[i].radius = 200.f + rand() % 100;
    astres[i].angle = 0.f;
    astres[i].speed = 90.f + rand() % 30;
    astres[i].finished = 0;

    astres[i].position.x = astres[i].center.x + cos(0) * astres[i].radius;
    astres[i].position.y = astres[i].center.y + sin(0) * astres[i].radius;

    sfSprite_setPosition(astres[i].sprite, astres[i].position);
    sfSprite_setScale(astres[i].sprite, (sfVector2f){1.0f, 1.0f});
}

    sfClock *clock = sfClock_create();

    while (sfRenderWindow_isOpen(window)) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        float dt = sfTime_asSeconds(sfClock_restart(clock));
        sfRenderWindow_clear(window, sfBlack);
        //sfRenderWindow_drawSprite(window, bgSprite, NULL);

        for (int i = 0; i < ASTRE_COUNT; i++) {
            sfSprite_rotate(astres[i].sprite, 0.4);
            //update_orbit(&astres[i], dt);
            sfRenderWindow_drawSprite(window, astres[i].sprite, NULL);
        }
        sfRenderWindow_display(window);
    }
    for (int i = 0; i < ASTRE_COUNT; i++) {
        sfTexture_destroy(astres[i].texture);
        sfSprite_destroy(astres[i].sprite);
    }
    //sfTexture_destroy(bgTex);
    //sfSprite_destroy(bgSprite);
    sfRenderWindow_destroy(window);
    return 0;
}
