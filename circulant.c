#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ToRight(int x[], int len); 
void doCirculant(int yourVector[], int finalMatrix[],int counter);

int main(){


    char vectors[100]; /*Variable to stoper user input*/
    /*Where to store the matrix*/
    /*User-Prompt*/
    printf("Enter your vector below\n");
    printf("\tSeperate elements using commas (,) e.g : 23,46,69\n\t");

    /*GET input*/
    scanf("%s", vectors);
    int counter = 0; 
    int yourVector[100]; /**/

    //convert the vectors string to array
    for (char *p = strtok(vectors, ","); p != NULL; p = strtok(NULL, ",")){
        yourVector[counter] = atoi(p); 
        counter++;
    }

    int vectorElementsSlice[counter];

    for(int i = 0; i < counter; i++) {
        vectorElementsSlice[i] = yourVector[i];
    }


    /*DO CIRCULANT*/
    int circulantMatrixVector[counter * counter];
    int circulantMatrix[counter][counter];



    doCirculant(vectorElementsSlice, circulantMatrixVector, counter);

    int numberofrows = sizeof(circulantMatrix[0]) / sizeof(int);

     /*PRINT CIRCULANT MATRIX*/

    /*CONVERT ARRAY TO MATRIX*/
    for(int i = 0; i < counter; i ++){
        for(int j = 0; j < counter; j++){
            circulantMatrix[i][j] = circulantMatrixVector[j*counter + i];
    }}

    /*PRINT FINAL MATRIX*/
    for(int i = 0; i < counter; i++){
        for(int j = 0; j < numberofrows; j++){
            printf("%d\t", circulantMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}


/*CIRCULANT FUNCTION*/

void doCirculant(int yourVector[], int finalMatrix[], int vectorSize){
    
    
    /*n by n matrix*/
    /*i by j matrix*/
    int mat[vectorSize][vectorSize];

    
    for(int i = 0; i < vectorSize; i ++){
        for(int j = 0; j < vectorSize; j++){
            mat[i][j] = yourVector[j];
        }
        /*Shift elements right after every row*/
        ToRight(yourVector, vectorSize);
    }


    for(int i = 0; i < vectorSize; ++i){
        for(int j = 0; j < vectorSize; ++j){
        finalMatrix[i + j*vectorSize] = mat[i][j];
        }
    }
    
    // puts("Cirulant Done");

    // for(int i = 0; i < vectorSize; i++){

    //     for(int j = 0; j < vectorSize; j++){
    //         printf("%d\t", mat[i][j]);
    //     }
    //     printf("\n");
    // }
    
}

void ToRight(int x[],int len){
    int placeholder = x[len - 1]; /*The last element*/
    /*This creates an empty slot at the last element*/
    /*Start shifting from second last element*/
    for(int i = 0;i <= len; i++){
        x[len - i] = x[len- (i+1)];
    }
    /*Move element to the beginning*/
    x[0] = placeholder;
}













