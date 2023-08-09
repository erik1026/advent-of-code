#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 100

int findSmallestDimension(int* dim, int lenOfArray){
    int smallest = 2147483647;

    for(int i = 0; i < lenOfArray; ++i){
        if(dim[i] < smallest)
            smallest = dim[i];
    }

    return smallest;
}

int calculateAmountOfPaper(int* dim, int lenOfArray){
    int totalNeeded = 0;
    int sides[3];
    sides[0] = dim[0]*dim[1];
    sides[1] = dim[1]*dim[2];
    sides[2] = dim[2]*dim[0];

    totalNeeded = 2*sides[0] + 2*sides[1] + 2*sides[2] + findSmallestDimension(sides, lenOfArray);

    //printf("Sides: %dx%dx%d with area:%d\n", dim[0], dim[1], dim[2], totalNeeded);

    return totalNeeded;
}


int main(){
    
    long total;
    int dimensions[3];
    char str[MAXLENGTH];
    FILE *file;
    char* token;

    total = 0;
    file = fopen("input.txt", "r");

    // Read through each line of the file
    while(fgets(str, MAXLENGTH, file) != NULL){
        // Split each line based on the delimiter (x)
        token = strtok(str, "x");
        
        for(int i = 0; i < 3 && token != NULL; ++i){
            dimensions[i] = atoi(token);
            token = strtok(NULL, "x");
        }

       // Calculate the amount of wrapping paper needed
       total = total + calculateAmountOfPaper(dimensions, 3); 
    }
    
    fclose(file);

    printf("Total amounf of paper in sqft: %ld\n", total);
    return 0;
}
