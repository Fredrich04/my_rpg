
#include "../include/rpg.h"

#define ASTRE_COUNT 5
#define WIDTH 1920
#define HEIGHT 1080
#define PI 3.14159265

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    float angle;
    float radius;
    float speed;
    sfVector2f center;
    int aligned;
} Astre;

void center_sprite(sfSprite *sprite)
{
    sfFloatRect bounds = sfSprite_getLocalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){bounds.width / 2, bounds.height / 2});
}

void update_orbit(Astre *a, float dt, sfVector2f center) {
    if (a->aligned < 1) {
        a->angle += a->speed * dt;
        a->center.x = center.x + cos(a->angle) * a->radius;
        a->center.y = center.y + sin(a->angle) * a->radius;
        if (a->angle >= (PI + 0.6f))
            a->aligned = 1;
    } else if (a->aligned == 1) {
        if (fabs(a->center.x - center.x) > 2.f)
            a->center.x += (center.x - a->center.x) * dt * 4;
        else {
            a->center.x = center.x;
            a->aligned = 2;
        }
    }

    sfSprite_setPosition(a->sprite, a->center);
}

int main(void) {
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){WIDTH, HEIGHT, 32}, "Cinematique", sfClose, NULL);
    sfClock *clock = sfClock_create();
    sfEvent event;
    float time = 0.f;

    sfTexture *bg_tex = sfTexture_createFromFile("../asserts/bg_start.jpg", NULL);
    sfSprite *bg = sfSprite_create();
    sfSprite_setTexture(bg, bg_tex, sfTrue);

    const char *astre_files[ASTRE_COUNT] = {
        "../asserts/sun.png", "../asserts/p1.png", "../asserts/p2.png", "../asserts/p3.png", "../asserts/p4.png"
    };
    
    Astre astres[ASTRE_COUNT];
    for (int i = 0; i < ASTRE_COUNT; i++) {
        astres[i].texture = sfTexture_createFromFile(astre_files[i], NULL);
        astres[i].sprite = sfSprite_create();
        sfSprite_setTexture(astres[i].sprite, astres[i].texture, sfTrue);
        center_sprite(astres[i].sprite);

        astres[i].angle = (i + 1) * (PI / 5);
            astres[i].radius = 300 + 70 * i;
        astres[i].speed = 1.5f + 0.3f * i;
        astres[i].center = (sfVector2f){
            WIDTH / 2 + cos(astres[i].angle) * astres[i].radius,
            HEIGHT / 2 + sin(astres[i].angle) * astres[i].radius
        };
        astres[i].aligned = (i == 0 ? 2 : 0);
        sfSprite_setPosition(astres[i].sprite, astres[i].center);
    }

    sfMusic *music = sfMusic_createFromFile("assets/music.ogg");
    sfSoundBuffer *flash_buf = sfSoundBuffer_createFromFile("assets/flash.wav");
    sfSound *flash_snd = sfSound_create();
    sfSound_setBuffer(flash_snd, flash_buf);
    sfMusic_play(music);

    sfTexture *logo_tex = sfTexture_createFromFile("assets/logo.png", NULL);
    sfSprite *logo = sfSprite_create();
    sfSprite_setTexture(logo, logo_tex, sfTrue);
    center_sprite(logo);
    sfSprite_setPosition(logo, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfSprite_setColor(logo, (sfColor){255, 255, 255, 0});

    int flash_played = 0;
    int all_aligned = 0;
    float flash_timer = 0;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);

        float dt = sfTime_asSeconds(sfClock_restart(clock));
        time += dt;

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg, NULL);

        all_aligned = 1;
        for (int i = 0; i < ASTRE_COUNT; i++) {
            update_orbit(&astres[i], dt, (sfVector2f){WIDTH / 2, HEIGHT / 2});
            sfRenderWindow_drawSprite(window, astres[i].sprite, NULL);
            if (astres[i].aligned != 2)
                all_aligned = 0;
        }

        if (all_aligned && !flash_played) {
            sfSound_play(flash_snd);
            flash_played = 1;
        }

        if (flash_played && flash_timer < 0.5f) {
            sfRectangleShape *flash = sfRectangleShape_create();
            sfRectangleShape_setSize(flash, (sfVector2f){WIDTH, HEIGHT});
            sfRectangleShape_setFillColor(flash, sfColor_fromRGBA(255, 255, 255, 255 * (1 - flash_timer * 2)));
            sfRenderWindow_drawRectangleShape(window, flash, NULL);
            sfRectangleShape_destroy(flash);
            flash_timer += dt;
            sfRenderWindow_clear(window, sfBlack);
        }
        if (flash_played && flash_timer >= 0.5f) {
            sfRenderWindow_clear(window, sfBlack);
            sfColor color = sfSprite_getColor(logo);
            if (color.a < 255)
                color.a += (sfUint8)(dt * 100);
            sfSprite_setColor(logo, color);
            sfRenderWindow_drawSprite(window, logo, NULL);
        }

        sfRenderWindow_display(window);
    }

    for (int i = 0; i < ASTRE_COUNT; i++) {
        sfTexture_destroy(astres[i].texture);
        sfSprite_destroy(astres[i].sprite);
    }
    sfTexture_destroy(bg_tex);
    sfSprite_destroy(bg);
    sfTexture_destroy(logo_tex);
    sfSprite_destroy(logo);
    sfMusic_destroy(music);
    sfSound_destroy(flash_snd);
    sfSoundBuffer_destroy(flash_buf);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
