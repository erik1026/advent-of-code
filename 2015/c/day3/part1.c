#include <stdio.h>
#include <stdlib.h>

#define MAXDIM 500 

void freeMem(char** mtx, int size){
    
    // Free the columns
    for(int i = 0; i < size; ++i)
        free(mtx[i]);

    // Free the rows
    free(mtx);
}
int numberOfHousesWithPresents(char** mtx, int size){
    
    int total = 0;
    
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if( mtx[i][j] > 0 )
                total++;
        }
    }

    return total;
}


int main(int argc, char** argv){
    
    // Define variables
    char **mtx = (char**)malloc(MAXDIM * sizeof(char*));
    for(int i = 0; i < MAXDIM; ++i){
        mtx[i] = (char*)malloc(MAXDIM * sizeof(char));
    }
    int row, column;
    char ch;
    FILE *file;

    // Initialize Variables
    for(int i = 0; i < MAXDIM; ++i)
        mtx[i][i] = 0;
    row = column = MAXDIM/2;
    mtx[row][column] = 1;
    file = fopen("input.txt", "r");

    // Read from the input file
    while( (ch = fgetc(file)) != EOF){

        switch (ch){
            case '^':
                row--;
                break;
            case 'v':
                row++;
                break;
            case '>':
                column++;
                break;
            case '<':
                column--;
                break;
            default:
                continue;
        }

        if( (row < MAXDIM && row >= 0) && (column < MAXDIM && column >= 0)){
            mtx[row][column]++;
        }
        else{
            printf("Exceeded size of mtx...\nExiting...\n");
            freeMem(mtx, MAXDIM);
            exit(1);
        }
    } 

    printf("Number of houses with at least one present: %d\n", numberOfHousesWithPresents(mtx, MAXDIM)); 

    freeMem(mtx, MAXDIM);
    
    return 0;
}
