/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** prototypes of myradar project
*/
#ifndef _MY_H_
    #define _MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Time.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <string.h>
    #include <unistd.h>
    #define LONG 800
    #define LARG 650
    #define NB 20

typedef struct round {
    sfCircleShape *circle;
    sfColor color;
    sfVector2f pos;
    float rad;
} rounde;

typedef struct object {
    char img[50];
    sfRectangleShape *rect;
    sfTexture *texture;
    sfVector2f size;
} object;

sfRenderWindow *init_var(rounde *R, object *img);

void evenment(sfRenderWindow *window);

void display_circle(sfRenderWindow *window, rounde *R);

void change_img(sfRenderWindow *window, object *img);

void free_var(sfRenderWindow *window, rounde *R, object *img);

#endif
