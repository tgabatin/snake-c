#include <stdlib.h>
#include "board.h"

void init_board(Board* board) {
    // Allocate memory for the board array
    board->board = malloc(sizeof(char*) * board->height);
    for (int i = 0; i < board->height; i++) {
        board->board[i] = malloc(sizeof(char) * board->width);
        for (int j = 0; j < board->width; j++) {
            // Fill the board array with empty spaces
            board->board[i][j] = ' ';
        }
    }
}

void draw_board(Board* board, Snake* snake, Fruit* fruit, int score) {
    // Clear the console
    system("cls");

    // Draw the border of the game board
    for (int i = 0; i < board->height; i++) {
        for (int j = 0; j < board->width; j++) {
            if (i == 0 || i == board->height - 1 || j == 0 || j == board->width - 1) {
                printf("#");
            }
            else {
                // If the current position is the snake's head, draw an 'O'
                if (snake->head.x == j && snake->head.y == i) {
                    printf("O");
                }
                // If the current position is the fruit, draw an 'F'
                else if (fruit->position.x == j && fruit->position.y == i) {
                    printf("F");
                }
                else {
                    // Check if the current position is part of the snake's body
                    int body = 0;
                    for (int k = 0; k < snake->length; k++) {
                        if (snake->body[k].x == j && snake->body[k].y == i) {
                            body = 1;
                            printf("o");
                            break;
                        }
                    }
                    if (!body) {
                        // If the current position is not part of the snake's body, draw the board character
                        printf("%c", board->board[i][j]);
                    }
                }
            }
        }
        printf("\n");
    }

    // Draw the score
    printf("Score: %d\n", score);
}
