/*
** EPITECH PROJECT, 2021
** myjam2
** File description:
** epitech jam 2 theme blue
*/

#include "../include/my.h"

int my_jam(void)
{
    object *img = malloc(sizeof(object));
    rounde *R = malloc(sizeof(rounde) * NB);
    sfRenderWindow *window = init_var(R, img);
    sfMusic *music = sfMusic_createFromFile("songs/song.ogg");

    sfMusic_play(music);
    while (sfRenderWindow_isOpen(window)) {
        evenment(window);
        sfRenderWindow_clear(window, sfWhite);
        display_circle(window, R);
        change_img(window, img);
        sfRenderWindow_display(window);
    }
    free_var(window, R, img);
    sfMusic_destroy(music);
    return (0);
}

void display_circle(sfRenderWindow *window, rounde *R)
{
    for (int i = 0; i < NB; i++) {
        R[i].rad = (R[i].rad <= 0) ? LONG : R[i].rad - 0.1;
        R[i].pos = (sfVector2f) {LONG / 2 - R[i].rad,
            LARG / 2 - R[i].rad};
        sfCircleShape_setRadius(R[i].circle, R[i].rad);
        R[i].color = sfColor_fromRGB(0, 0, R[i].rad * 255 / LONG);
        sfCircleShape_setPosition(R[i].circle, R[i].pos);
        sfCircleShape_setOutlineColor(R[i].circle, R[i].color);
        sfRenderWindow_drawCircleShape(window, R[i].circle, NULL);
    }
}

void change_img(sfRenderWindow *window, object *img)
{
    if (img->size.x > 0) {
        img->size.x -= LONG / 10000.0;
        img->size.y -= LARG / 10000.0;
    } else {
        img->size = (sfVector2f){LONG / 4, LARG / 4};
        img->img[9] = (img->img[9] != '9') ? img->img[9] + 1 : '1';
        (img->texture) ? sfTexture_destroy(img->texture) : 0;
        img->texture = sfTexture_createFromFile(img->img, NULL);
    }
    sfRectangleShape_setPosition(img->rect, (sfVector2f)
        {(LONG - img->size.x) / 2, (LARG - img->size.y) / 2} );
    sfRectangleShape_setSize(img->rect, img->size);
    sfRectangleShape_setTexture(img->rect, img->texture, sfTrue);
    sfRenderWindow_drawRectangleShape(window, img->rect, NULL);
}

int main(int ac, char **av)
{
    if (ac != 1)
        return (84);
    my_jam();
    return (0);
}
