#ifndef SNAKE_H
#define SNAKE_H

#include "board.h"
#include "fruit.h"

typedef struct Fruit Fruit;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point head;
    Point* body;
    int length;
} Snake;

void init_snake(Snake* snake, int x, int y);

void move_snake(Board* board, Snake* snake, Fruit* fruit, int* score);

int is_snake_body(Snake* snake, int x, int y);


#endif /* SNAKE_H */
