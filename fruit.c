#include <stdlib.h>
#include <time.h>
#include "fruit.h"
#include "constants.h"

void init_fruit(Fruit* fruit) {
    // Generate a random position for the fruit
    srand(time(NULL));
    fruit->position.x = rand() % (MAX_WIDTH - 2) + 1;
    fruit->position.y = rand() % (MAX_HEIGHT - 2) + 1;
}

void place_fruit(Board* board, Fruit* fruit, Snake* snake) {
    // Keep generating random positions for the fruit until it doesn't overlap with the snake
    do {
        fruit->position.x = rand() % (MAX_WIDTH - 2) + 1;
        fruit->position.y = rand() % (MAX_HEIGHT - 2) + 1;
    } while (board->board[fruit->position.y][fruit->position.x] != ' ' ||
             is_snake_body(snake, fruit->position.x, fruit->position.y));

    // Place the fruit on the game board
    board->board[fruit->position.y][fruit->position.x] = 'F';
}

int is_snake_body(Snake* snake, int x, int y) {
    // Check if the given position is part of the snake's body
    for (int i = 0; i < snake->length; i++) {
        if (snake->body[i].x == x && snake->body[i].y == y) {
            return 1;
        }
    }
    return 0;
}
