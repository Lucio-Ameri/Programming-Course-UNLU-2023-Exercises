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
void Summation(int array[ROW][COLUMN], int size_row, int size_column, int *vector_row, int *vector_column);
void Show_vector(int vector[], int size);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[ROW][COLUMN], row, column, vector_row[ROW], vector_column[COLUMN];

    /*I ask for the sizes of the arrays*/
    printf("Enter the number of rows the matrix will have: ");
    row = Get_Number();
    
    printf("Enter the number of columns the matrix will have: ");
    column = Get_Number();

    /*I load the array automatically and then display it on the screen*/
    Load_Array(array, row, column);
    Show_Array(array, row, column);

    /*I load the vectors with their corresponding sum contents*/
    Summation(array, row, column, vector_row, vector_column);

    /*I show the result of the sums on the screen*/
    printf("The result of summing the rows of the matrix will be displayed: \n");
    Show_vector(vector_row, row);

    printf("The result of summing the columns of the matrix will be displayed: \n");
    Show_vector(vector_column, column);

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
    printf("\n");
    system("cls");

    return Number;
}

void Show_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C;

    /*I print the content of array[R][C] with each iteration*/
    printf("Array:\n");
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            printf("%4d", array[R][C]);
        }
        
        printf("\n");
    }
    system("Pause");
    system("cls");
}

void Show_vector(int vector[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", vector[i]);
    }
    printf("\n\n");

    system("Pause");
}

void Load_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C;

    /*I load the array with random numbers between 1 and 10*/
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            array[R][C] = (rand() % 10) + 1;
        }
    }
}

void Summation(int array[ROW][COLUMN], int size_row, int size_column, int *vector_row, int *vector_column){
    /*I declare the variables*/
    int R, C, sum_row, sum_column;

    /*I load the result of summing all the elements of a row into the vector_row[R]*/
    for(R = 0; R < size_row; R++){
        sum_row = 0; 

        for(C = 0; C < size_column; C++){
            sum_row += array[R][C];
        }

        vector_row[R] = sum_row;
    }
    
    /*I load the result of summing all the elements of a column into the vector_column[C]*/
    for(R = 0; R < size_row; R++){
        sum_column = 0; 

        for(C = 0; C < size_column; C++){
            sum_column += array[C][R];
        }

        vector_column[R] = sum_column;
    }
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int Testing_array[ROW][COLUMN] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3, column = 3, vector_R[ROW], vector_C[COLUMN];
    int Test_vector_R[ROW] = {6, 15, 24};
    int Test_vector_C[COLUMN] = {12, 15, 18};

    /*I am testing the functions*/
    Summation(Testing_array, row, column, vector_R, vector_C);

    for(int i = 0; i < row; i++){
        assert(Test_vector_R[i] == vector_R[i]);
    }

    for(int C = 0; C < column; C++){
        assert(Test_vector_C[C] == vector_C[C]);
    }

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}