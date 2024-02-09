#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
void Show_Array(int array[], int size, int flag);
void Load_Array(int *array, int size);
void Order_the_Array(int *array, int size);
void Testing();
int Eliminating_Duplicates(int *array, int size);
void Combining_Arrays(int array_A[], int array_B[], int *array_C, int size, int size2);
int Get_Number();

int main(){
    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    printf("Enter the size of the first array: ");
    int size1 = Get_Number();

    printf("Enter the size of the second array: ");
    int size2 = Get_Number();

    system("Pause");
    system("cls");

    int size3 = (size1 + size2), flag = 1, duplicates;
    int array_A[size1], array_B[size2], array_C[size3];


    /*I load the arrays and display it on the screen*/
    printf("Now we will load the content of the arrays!");
    system("Pause");

    printf("FIRST ARRAY: \n");
    Load_Array(array_A, size1);
    Show_Array(array_A, size1, flag);
    flag += 1;
    system("Pause");

    printf("SECOND ARRAY: \n");
    Load_Array(array_B, size2);
    Show_Array(array_B, size2, flag);
    flag += 1;
    system("Pause");

    /*I sort the arrays provided by the user*/
    Order_the_Array(array_A, size1);
    Order_the_Array(array_B, size2);
    
    /*I combine both arrays provided by the user*/
    Combining_Arrays(array_A, array_B, array_C, size1, size2);

    /*I sort the array C*/
    Order_the_Array(array_C, size3);

    /*I eliminate the duplicate elements from this array and display it on the screen*/
    duplicates = Eliminating_Duplicates(array_C, size3);
    Show_Array(array_C, size3, flag);

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

void Show_Array(int array[], int size, int flag){
    /*I declare the variables*/
    int i;

    printf("ARRAY NUMBER %d: \n", flag);
    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        if(array[i] != 0){
            printf("%4d", array[i]);
        }
    }
    printf("\n\n");
}

void Load_Array(int *array, int size){
    /*I declare the variables*/
    int i;

    /*With each interaction, I ask the user for a new number*/
    printf("You should enter %d numbers (one at a time)!\n", size);
    for(i = 0; i < size; i++){
        printf("Please enter number number %d (other than 0): ", i + 1);
        array[i] = Get_Number();
    }
    system("Pause");
    system("cls");
}

void Order_the_Array(int *array, int size){
    /*I declare the variables*/
    int i, j, aux;

    /*I use nested loops to traverse the array, looking for values that are greater than the next one in order 
    to sort the array from smallest to largest*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            
            if((array[i] > array[j]) || (array[i] == 0)){
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void Combining_Arrays(int array_A[], int array_B[], int *array_C, int size, int size2){
    /*I declare the variables*/
    int i, j, aux = 0;

    /*I load the arrays individually into the array c*/
    for(i = 0; i < size; i++){
        array_C[aux] = array_A[i];
        aux++;
    }

    for(j = 0; j < size2; j++){
        array_C[aux] = array_B[j];
        aux++;
    }
}


int Eliminating_Duplicates(int *array, int size){
    /*I declare the variables*/
    int i, j, dup = 0;

    /*If there are repeated elements, I transform them into zeros and then call the 'order the array' function to move 
    them to the end of the array as if they were not vector elements*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if((array[i] == array[j]) && (array[i] != 0)){
            array[j] = 0;
            dup++;
            }
        }
    }
    Order_the_Array(array, size);

    return dup;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);
    
    /*I declare the variables*/
    int arr[] = {1, 1, 1};
    int arr2[] = {2, 2, 3};
    int arr3[6];
    int expected_array[] = {1, 2, 3, 0, 0, 0};
    int dup1 = 2, dup2 = 1;

    /*I am testing the function*/
    assert(Eliminating_Duplicates(arr, 3) == dup1);
    assert(Eliminating_Duplicates(arr2, 3) == dup2);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}