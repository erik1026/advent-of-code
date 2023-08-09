#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLENGTH 100

// This only works for a rectangluar prism
int calculateVolume(int* dim){
    return dim[0]*dim[1]*dim[2];
}

int findSmallestArea(int* dim, int lenOfArray){
    int smallestArea = 2147483647;
    int area;

    for(int i = 0; i < lenOfArray; ++i){
        for(int j = 0; j < lenOfArray; ++j){
            if(j != i){
                area = 2*dim[i] + 2*dim[j];
                if(area < smallestArea)
                    smallestArea = area;            
            }
        } 
    }

    return smallestArea;
}

int calculateAmountOfRibbon(int* dim, int lenOfArray){
    int totalNeeded = 0;

    totalNeeded = findSmallestArea(dim, lenOfArray) + calculateVolume(dim);
    
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
       total = total + calculateAmountOfRibbon(dimensions, 3); 
    }
    
    fclose(file);

    printf("Total amount of ribbon in ft: %ld\n", total);
    return 0;
}
