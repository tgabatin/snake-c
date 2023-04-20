#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "snake.h"

void init_snake(Snake* snake, int x, int y) {
    // Initialize the snake's head and body length
    snake->head.x = x;
    snake->head.y = y;
    snake->length = 3;
    snake->body = malloc(sizeof(Point) * snake->length);
    for (int i = 0; i < snake->length; i++) {
        snake->body[i].x = x - i - 1;
        snake->body[i].y = y;
    }
}

void move_snake(Board* board, Snake* snake, Fruit* fruit, int* score) {
    // Move the snake in response to user input
    int dx = 0, dy = 0;
    char input;
    if (scanf("%c", &input) == 1) {
        getchar();  // consume newline character
        switch (input) {
            case 'a':
                dx = -1;
                break;
            case 'd':
                dx = 1;
                break;
            case 'w':
                dy = -1;
                break;
            case 's':
                dy = 1;
                break;
        }
    }
    Point prevHead = snake->head;
    snake->head.x += dx;
    snake->head.y += dy;

    // Check for collisions with the game board
    if (snake->head.x < 0 || snake->head.x >= board->width ||
        snake->head.y < 0 || snake->head.y >= board->height) {
        return;
    }
    for (int i = 0; i < snake->length; i++) {
        if (snake->body[i].x == snake->head.x && snake->body[i].y == snake->head.y) {
            return;
        }
    }

    // Check for collisions with the fruit
    if (snake->head.x == fruit->position.x && snake->head.y == fruit->position.y) {
        // Increase the score and create a new fruit
        *score += 10;
        place_fruit(board, fruit, snake);
        snake->length++;
        snake->body = realloc(snake->body, sizeof(Point) * snake->length);
        for (int i = snake->length - 1; i > 0; i--) {
            snake->body[i] = snake->body[i - 1];
        }
        snake->body[0] = prevHead;
    }
    else {
        // Move the body of the snake forward
        for (int i = snake->length - 1; i > 0; i--) {
            snake->body[i] = snake->body[i - 1];
        }
        snake->body[0] = prevHead;
    }
}
