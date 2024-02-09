#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define SIZE 100

int Get_Number();
void Show_Array(int array[], int size);
void Load_Array(int *array, int size);
void Order_the_Array(int *array, int size);
void Repeated_Numbers(int *array_A, int *array_B, int *array_C, int size, int *size_C);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array_A[SIZE], array_B[SIZE], array_C[SIZE], size_array, size_array_C;

    /*I ask for the size of the arrays*/
    printf("Enter the size of the arrays: "); size_array = Get_Number();

    /*I automatically load the array, sort it from largest to smallest, and display it on the screen*/
    printf("FIRST ARRAY!\n");
    Load_Array(array_A, size_array);
    Order_the_Array(array_A, size_array);
    Show_Array(array_A, size_array);

    system("Pause");

    /*I automatically load the array, sort it from largest to smallest, and display it on the screen*/
    printf("SECOND ARRAY!\n");
    Load_Array(array_B, size_array);
    Order_the_Array(array_B, size_array);
    Show_Array(array_B, size_array);

    system("Pause");

    /*I load 'array_C' with the numbers found repeated in the other 2 arrays*/
    Repeated_Numbers(array_A, array_B, array_C, size_array, &size_array_C);

    /*sort it from largest to smallest, and display it on the screen*/
    printf("THIRD ARRAY!\n");
    Order_the_Array(array_C, size_array_C);
    Show_Array(array_C, size_array_C);
    
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

    return Number;
}

void Show_Array(int array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array, int size){
    /*I declare the variables*/
    int i;

    /*I load the array with random numbers between 1 and 30*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 30) + 1;
    }

}

void Order_the_Array(int *array, int size){
    /*I declare the variables*/
    int i, j, aux;

    /*I use nested loops to traverse the array, looking for values that are smaller than the next one, in order 
    to sort the array from largest to smallest*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            
            if(array[i] < array[j]){
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void Repeated_Numbers(int *array_A, int *array_B, int *array_C, int size, int *size_C){
    /*I declare the variables*/
    int i, j, coincidence = 0, counter = 0;

    /*I search for duplicates present in both arrays, and load them into array_C, not allowing 
    repeated numbers in array_C*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if((array_A[i] == array_B[j]) && (coincidence == 0)){
                if(counter == 0){
                    array_C[counter] = array_A[i];
                    counter++;
                    coincidence++;
                }
                else{
                    if(array_C[counter - 1] > array_A[i]){
                        array_C[counter] = array_A[i];
                        counter++;
                        coincidence++;
                    }
                }
            }
        }
        coincidence = 0;
    }
    
    /*I update the size of array_C*/
    *(size_C) = counter;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int i, arr1[SIZE] = {1, 2, 3}, arr2[SIZE] = {3, 2, 5}, n = 3, m;
    int test_arr[SIZE] = {3, 2}, arr3[SIZE];

    /*I am testing the functions*/
    Order_the_Array(arr1, n);
    Order_the_Array(arr2, n);

    Repeated_Numbers(arr1, arr2, arr3, n, &m);

    Order_the_Array(arr3, m);

    for(i = 0; i < m; i++){
        assert(arr3[i] == test_arr[i]);
    }

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}