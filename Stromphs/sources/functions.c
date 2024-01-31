/*
** EPITECH PROJECT, 2021
** myjam2
** File description:
** epitech jam 2 theme blue
*/

#include "../include/my.h"

sfRenderWindow *init_var(rounde *R, object *img)
{
    sfVideoMode mode = {LONG, LARG, 32};
    sfRenderWindow *window = sfRenderWindow_create
        (mode, "Sleep BABY", sfClose, NULL);

    for (int i = 0; i < NB; i++) {
        R[i].circle = sfCircleShape_create();
        R[i].rad = i * LONG / NB;
        sfCircleShape_setOutlineThickness(R[i].circle, 5);
        sfCircleShape_setFillColor(R[i].circle, sfTransparent);
    }
    img->rect = sfRectangleShape_create();
    img->size = (sfVector2f){0, 0};
    strcpy(img->img, "pictures/0.png");
    img->texture = NULL;
    return (window);
}

void evenment(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
}

void free_var(sfRenderWindow *window, rounde *R, object *img)
{
    for (int i = 0; i < NB; i++)
	sfCircleShape_destroy(R[i].circle);
    sfTexture_destroy(img->texture);
    sfRectangleShape_destroy(img->rect);
    sfRenderWindow_destroy(window);
    free(R);
    free(img);
}
