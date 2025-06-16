int main(void)
{
    sfRenderWindow *window = sfRenderWindow_create(
        (sfVideoMode){WIDTH, HEIGHT, 32}, "Logo Fade In", sfClose, NULL);
    sfClock *clock = sfClock_create();
    sfEvent event;

    // Chargement du logo
    sfTexture *logo_tex = sfTexture_createFromFile("logo.png", NULL);
    if (!logo_tex)
        return 1;

    sfSprite *logo = sfSprite_create();
    sfSprite_setTexture(logo, logo_tex, sfTrue);

    // Centrage du logo
    sfFloatRect bounds = sfSprite_getLocalBounds(logo);
    sfSprite_setOrigin(logo, (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfSprite_setPosition(logo, (sfVector2f){WIDTH / 2, HEIGHT / 2});

    // Initialisation alpha à 0 (transparent)
    sfSprite_setColor(logo, (sfColor){255, 255, 255, 0});

    // Animation fade-in
    float fade_duration = 2.5f;  // durée du fondu en secondes
    float elapsed = 0.f;

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        float dt = sfTime_asSeconds(sfClock_restart(clock));
        if (elapsed < fade_duration) {
            elapsed += dt;
            float ratio = fminf(elapsed / fade_duration, 1.f);
            sfColor color = sfSprite_getColor(logo);
            color.a = (sfUint8)(255 * ratio);
            sfSprite_setColor(logo, color);
        }

        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, logo, NULL);
        sfRenderWindow_display(window);
    }

    sfTexture_destroy(logo_tex);
    sfSprite_destroy(logo);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(window);
    return 0;
}
