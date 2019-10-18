//
// Created by Franklin Mao on 9/30/2019.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack_ll.h"
const int MAX_SIZE = 80;
void populateWorld(char fName[], char grid[MAX_SIZE][MAX_SIZE], int *numRows, int *numCols);
void floodFill(char grid[MAX_SIZE][MAX_SIZE], int row, int col, int numRows, int numCols, char color);
void showWorld(char grid[MAX_SIZE][MAX_SIZE], int numRows, int numCols);



int main(int argc, char *argv[]) {
    char grid[MAX_SIZE][MAX_SIZE];
    int numRows;
    int numCols;
    char *fName = argv[1];
    populateWorld(fName, grid, &numRows, &numCols);
    int row;
    int col;
    char color;
    showWorld(grid, numRows, numCols);
    while(1) {
        printf("\nEnter a row: ");
        scanf("%d", &row);
        printf("Enter a column: ");
        scanf("%i", &col);
        printf("Enter a color: ");
        scanf(" %c", &color);
        if((row == -1) || (col == -1)) {                //end condition
            return 0;
        }
        while(((row < -1) || (row >= numRows)) || ((col < -1) || (col >= numCols))) {     //check that input is inbounds
            printf("\nInvalid input\n");
            showWorld(grid, numRows, numCols);
            printf("\nEnter a row: ");
            scanf("%d", &row);
            printf("Enter a column: ");
            scanf("%i", &col);
            printf("Enter a color: ");
            scanf(" %c", &color);
            if((row == -1) || (col == -1)) {                //end condition
                return 0;
            }
        }

//        floodFill(grid, row, col, numRows, numCols, color);

        Stack312 s;
        makeStack(&s);
        StackEntry e;
        e.row = row;
        e.col = col;
        e.color = grid[row][col];
        push(e, &s);

        while (!isEmpty(s)) {
            StackEntry cell = pop(&s);
            row = cell.row;
            col = cell.col;
            if (row > 0) {                                  //check top
                if (grid[row - 1][col] == cell.color) {
                    StackEntry newE;
                    newE.row = row - 1;
                    newE.col = col;
                    newE.color = grid[row - 1][col];
                    push(newE, &s);
                }
            }
            if (row < numRows) {                            //check bottom
                if (grid[row + 1][col] == cell.color) {
                    StackEntry newE;
                    newE.row = row + 1;
                    newE.col = col;
                    newE.color = grid[row + 1][col];
                    push(newE, &s);
                }
            }
            if (col > 0) {
                if (grid[row][col - 1] == cell.color) {     //check left
                    StackEntry newE;
                    newE.row = row;
                    newE.col = col - 1;
                    newE.color = grid[row][col - 1];
                    push(newE, &s);
                }
            }
            if (col < numCols) {
                if (grid[row][col + 1] == cell.color) {     //check right
                    StackEntry newE;
                    newE.row = row;
                    newE.col = col + 1;
                    newE.color = grid[row][col + 1];
                    push(newE, &s);
                }
            }
            if ((row > 0) && (col > 0)) {
                if (grid[row - 1][col - 1] == cell.color) {   //check top left
                    StackEntry newE;
                    newE.row = row - 1;
                    newE.col = col - 1;
                    newE.color = grid[row - 1][col - 1];
                    push(newE, &s);
                }
            }
            if ((row > 0) && (col < numCols)) {
                if (grid[row - 1][col + 1] == cell.color) {   //check top right
                    StackEntry newE;
                    newE.row = row - 1;
                    newE.col = col + 1;
                    newE.color = grid[row - 1][col + 1];
                    push(newE, &s);
                }
            }
            if ((row < numRows) && (col > 0)) {
                if (grid[row + 1][col - 1] == cell.color) {   //check bottom left
                    StackEntry newE;
                    newE.row = row + 1;
                    newE.col = col - 1;
                    newE.color = grid[row + 1][col - 1];
                    push(newE, &s);
                }
            }
            if ((row < numRows) && (col < numCols)) {
                if (grid[row + 1][col + 1] == cell.color) {   //check bottom right
                    StackEntry newE;
                    newE.row = row + 1;
                    newE.col = col + 1;
                    newE.color = grid[row + 1][col + 1];
                    push(newE, &s);
                }
            }

            cell.color = color;
            grid[row][col] = cell.color;
        }

        showWorld(grid, numRows, numCols);
    }
}

void populateWorld(char fName[], char grid[MAX_SIZE][MAX_SIZE], int *numRows, int *numCols) {
    (*numRows) = 0;
    *numCols = 0;
    FILE *fptr;
    fptr = fopen(fName, "r");
    if (fptr == NULL){
        printf("You messed up\n");
        exit(-42);
    }

    char *bufstring = (char*) malloc(MAX_SIZE);
    while(fgets(bufstring, MAX_SIZE, fptr)) {
        (*numRows)++;
    }

    *numCols = strlen(bufstring) - 1;

    free(bufstring);
    fclose(fptr);
    fptr = fopen(fName, "r");               //reset file pointer to beginning
    for(int i = 0; i < *numRows; i++) {
        fgets(grid[i], MAX_SIZE, fptr);
    }
    fclose(fptr);
}


void floodFill(char grid[MAX_SIZE][MAX_SIZE], int row, int col, int numRows, int numCols, char color) {
    char gridColor = grid[row][col];
    grid[row][col] = color;
    if (row > 0) {                                  //check top
        if (grid[row - 1][col] == gridColor) {
            floodFill(grid, row - 1, col, numRows, numCols, color);
        }
    }
    if (row < numRows) {                            //check bottom
        if (grid[row + 1][col] == gridColor) {
            floodFill(grid, row + 1, col, numRows, numCols, color);
        }
    }
    if (col > 0) {
        if (grid[row][col - 1] == gridColor) {     //check left
            floodFill(grid, row, col - 1, numRows, numCols, color);
        }
    }
    if (col < numCols) {
        if (grid[row][col + 1] == gridColor) {     //check right
            floodFill(grid, row, col + 1, numRows, numCols, color);
        }
    }
    if ((row > 0) && (col > 0)) {
        if (grid[row - 1][col - 1] == gridColor) {   //check top left
            floodFill(grid, row - 1, col - 1, numRows, numCols, color);
        }
    }
    if ((row > 0) && (col < numCols)) {
        if (grid[row - 1][col + 1] == gridColor) {   //check top right
            floodFill(grid, row - 1, col + 1, numRows, numCols, color);
        }
    }
    if ((row < numRows) && (col > 0)) {
        if (grid[row + 1][col - 1] == gridColor) {   //check bottom left
            floodFill(grid, row + 1, col - 1, numRows, numCols, color);
        }
    }
    if ((row < numRows) && (col < numCols)) {
        if (grid[row + 1][col + 1] == gridColor) {   //check bottom right
            floodFill(grid, row + 1, col + 1, numRows, numCols, color);
        }
    }

}

void showWorld(char grid[MAX_SIZE][MAX_SIZE], int numRows, int numCols) {
    printf("\n");
    for(int i = 0; i < numRows; i++) {
        printf("%s", grid[i]);
    }
    printf("\n");
}