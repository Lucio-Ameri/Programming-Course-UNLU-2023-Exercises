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
int Summation(int array[ROW][COLUMN], int size_row, int size_column);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[ROW][COLUMN], row, column, accumulator = 0;

    /*I ask for the sizes of the arrays*/
    printf("Enter the number of rows the matrix will have: ");
    row = Get_Number();
    
    printf("Enter the number of columns the matrix will have: ");
    column = Get_Number();

    /*I load the array automatically and then display it on the screen*/
    Load_Array(array, row, column);
    Show_Array(array, row, column);

    /*I calculate the result of the summation of the elements of the matrix, display on the screen how the elements 
    are summed, and show the result*/
    accumulator = Summation(array, row, column);

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
    printf("\n");
    system("cls");

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
    system("Pause");
    system("cls");
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

int Summation(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C, sum = 0;

    /*I print the list of all the additions that will be made along with their result*/
    printf("the result of adding: ");
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            printf("%d", array[R][C]);
            
            if (R != size_row - 1 || C != size_column - 1) {
                printf(" + ");
            }

            sum += array[R][C];
        }
    }
    printf(" is: %d\n", sum);

    return sum;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int size_row = 3, size_column = 4;
    int array[ROW][COLUMN] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int sum = 78;

    /*I am testing the functions*/
    assert(Summation(array, size_row, size_column) == sum);
    system("cls");

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}