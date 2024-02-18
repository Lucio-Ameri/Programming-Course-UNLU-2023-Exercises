#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define ROW 100
#define COLUMN 100

int Get_Number();
void Show_Array(int array[ROW][COLUMN], int size_row, int size_column);
void Load_Array(int array[ROW][COLUMN], int size_row, int size_column);
void Transpose_Operation(int array[ROW][COLUMN], int size_row, int size_column);
void Permutation(int array[ROW][COLUMN], int row, int column);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[ROW][COLUMN], row, column;

    /*I ask for the sizes of the array*/
    printf("Enter the number of rows the matrix will have: ");
    row = Get_Number();
    
    printf("Enter the number of columns the matrix will have: ");
    column = Get_Number();

    /*If the sizes of the arrays are not equal, prompt for one of the values again until it matches the other*/
    if(row != column){
        while(row != column){
            printf("To perform the transpose operation, we must have a square matrix. Please input a matrix with an equal number of rows and columns: ");

            column = Get_Number();
        }
    }
    system("Pause");
    system("cls");

    /*load the array and display it on the screen*/
    Load_Array(array, row, column);
    printf("The matrix is:\n");
    Show_Array(array, row, column);
    system("Pause");

    /*transpose the original matrix*/
    Transpose_Operation(array, row, column);

    system("Pause");
    system("cls");

    return 0; 
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 0, Number;

    /*validates that what is entered by keyboard is a number*/
    if(scanf("%d", &Number) != 1 ){
        fflush(stdin);
        flag = 1;
        printf("\nInvalid input. Please enter a valid number!\n");
        
        while(flag == 1){
            printf("Enter a valid number: ");
            
            if(scanf("%d", &Number) != 1){
                fflush(stdin);
                printf("\nInvalid input. Please enter a valid number!\n");
            }
            
            else{flag = 0;}
        }
    }

    return Number;
}

void Show_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C;

    /*I print the content of array[R][C] with each iteration*/
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            printf("%4d", array[R][C]);
        }
        
        printf("\n");
    }
}

void Load_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C;

    /*I load the array with random numbers between 1 and 10*/
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            array[R][C] = (rand() % 50) + 1;
        }
    }
}

void Transpose_Operation(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C, aux = 0;

    /*with each iteration of C, swap a position in the matrix and display the result on the screen. This process 
    continues until the original matrix is transposed*/
    for(R = 0; R < size_row - 1; R++){

        for(C = R + 1; C < size_column; C++){
            Permutation(array, R, C);
            aux++;
            printf("After permutation %d:\n", aux);
            Show_Array(array, size_row, size_column);
            printf("------------------------\n");
            system("Pause");
        }
    }

}

void Permutation(int array[ROW][COLUMN], int row, int column){
    /*I declare the variables*/
    int aux;

    /*swap the values of the matrix[R][C] with the matrix[C][R]*/
    aux = array[column][row];
    array[column][row] = array[row][column];
    array[row][column] = aux; 
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int Testing_array[ROW][COLUMN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3, column = 3;
    int Transpose_Array[ROW][COLUMN] = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};


    /*I am testing the functions*/
    Transpose_Operation(Testing_array, row, column);
    system("cls");
    
    for(int R = 0; R < row; R++){
        for(int C = 0; C < column; C++){
            assert(Testing_array[R][C] == Transpose_Array[R][C]);
        }
    }

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}