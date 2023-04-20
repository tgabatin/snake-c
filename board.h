#ifndef BOARD_H
#define BOARD_H

#include "snake.h"
#include "fruit.h"

// Define a struct to represent the game board
typedef struct {
    int width;      // Width of the board
    int height;     // Height of the board
    char** board;   // 2D array of characters to represent the board
} Board;

// Function to initialize a Board object
void init_board(Board* board);

// Function to draw the game board on the console
void draw_board(Board* board, Snake* snake, Fruit* fruit, int score);

#endif
