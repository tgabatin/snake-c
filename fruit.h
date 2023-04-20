#ifndef FRUIT_H
#define FRUIT_H

#include "snake.h"
#include "board.h"

typedef struct {
    Point position;
} Fruit;

void init_fruit(Fruit* fruit);

void place_fruit(Board* board, Fruit* fruit, Snake* snake);

#endif /* FRUIT_H */
