#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "snake.h"
#include "fruit.h"
#include "constants.h"

int main() {
    // Initialize the game board, snake, and fruit
    Board board;
    board.width = MAX_WIDTH;
    board.height = MAX_HEIGHT;
    init_board(&board);

    Snake snake;
    init_snake(&snake, board.width / 2, board.height / 2);

    Fruit fruit;
    init_fruit(&fruit);
    place_fruit(&board, &fruit, &snake);

    int score = 0;

    // Main game loop
    while (1) {
        // Move the snake and update the board
        move_snake(&board, &snake, &fruit, &score);
        draw_board(&board, &snake, &fruit, score);

        // End the game if the snake collides with the game board or itself
        if (snake_collision(&snake)) {
            printf("Game over!\n");
            break;
        }

        // Wait for a single character of input from the user
        printf("Press a key to continue...");
        fflush(stdout);
        getchar();

        // Clear the console screen
        system("clear");
    }

    return 0;
}
