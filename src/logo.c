#include <SFML/Graphics.h>
#include <SFML/System.h>

void fade_in_logo(sfRenderWindow *window, const char *logo_path)
{
    sfTexture *logo_texture = sfTexture_createFromFile(logo_path, NULL);
    if (!logo_texture)
        return;
    sfSprite *logo_sprite = sfSprite_create();
    sfSprite_setTexture(logo_sprite, logo_texture, sfTrue);

    sfVector2u win_size = sfRenderWindow_getSize(window);
    sfVector2u tex_size = sfTexture_getSize(logo_texture);
    sfVector2f pos = {(win_size.x - tex_size.x) / 2.0f, (win_size.y - tex_size.y) / 2.0f};
    sfSprite_setPosition(logo_sprite, pos);

    sfClock *clock = sfClock_create();
    sfUint8 alpha = 0;

    while (alpha < 255) {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        sfTime time = sfClock_getElapsedTime(clock);
        if (sfTime_asMilliseconds(time) > 10) {
            alpha += 3;
            if (alpha > 255) alpha = 255;

            sfColor color = sfColor_fromRGBA(255, 255, 255, alpha);
            sfSprite_setColor(logo_sprite, color);

            sfRenderWindow_clear(window, sfBlack);
            sfRenderWindow_drawSprite(window, logo_sprite, NULL);
            sfRenderWindow_display(window);

            sfClock_restart(clock);
        }
    }
    //sfSleep(sfSeconds(1.5));
    sfTexture_destroy(logo_texture);
    sfSprite_destroy(logo_sprite);
    sfClock_destroy(clock);
}
