#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXDIM 500 

typedef struct Pos{
    int x;
    int y;
} Pos;

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
    Pos santa, robot;
    char ch;
    FILE *file;
    bool row, col, isSanta;
    int val; 

    // Initialize Variables
    for(int i = 0; i < MAXDIM; ++i)
        mtx[i][i] = 0;
    santa.x = santa.y = robot.x = robot.y = MAXDIM/2;
    mtx[santa.x][santa.y] = 2;
    row = col = false;
    isSanta = true;
    val = 0;
    file = fopen("input.txt", "r");

    // Read from the input file
    while( (ch = fgetc(file)) != EOF){
        switch (ch){
            case '^':
                val--;
                row = true;
                col = false;
                break;
            case 'v':
                val++;
                row = true;
                col = false;
                break;
            case '>':
                val++;
                col = true;
                row = false;
                break;
            case '<':
                val--;
                col = true;
                row = false;
                break;
            default:
                continue;
        }
        if( (santa.x < MAXDIM && santa.x >= 0) && (santa.y < MAXDIM && santa.y >= 0) && (robot.x < MAXDIM && robot.x >= 0) && (robot.y < MAXDIM && robot.y >= 0)  ){
            if(isSanta){
                if(row)
                    santa.x += val;
                else
                    santa.y += val;

                mtx[santa.x][santa.y]++;
                isSanta = false;
            }
            else{
                if(row)
                    robot.x += val;
                else
                    robot.y += val;

                mtx[robot.x][robot.y]++;
                isSanta = true;
            } 
            val = 0;
        }
        else{
            printf("Exceeded size of mtx...\nExiting...\n");
            freeMem(mtx, MAXDIM);
            exit(1);
        }
    
    }
    printf("Number of houses with at least one present: %d\n", numberOfHousesWithPresents(mtx, MAXDIM)); 

    freeMem(mtx, MAXDIM);
    fclose(file);

    return 0;
}
