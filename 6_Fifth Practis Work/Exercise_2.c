#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define SIZE_ARRAY 1000

int Get_Number();
void Show_Array(int array[], int size);
void Load_Array(int *array, int size);
void Eliminating_Duplicates(int *array, int *size);
void Sort_Array(int *array, int size);
int Append_to_the_Array(int *array, int *size, int number);
int Find_Element(int *array, int *size, int number, int *found);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int size, array[SIZE_ARRAY], number, position, found = 0;

    /*I ask the user to enter a number. If it exceeds the established range, it asks for the number again until it is within the allowed range*/
    printf("Enter the size of the array (up to a maximum of 999): ");
    size = Get_Number();
    while(size > 999){
        printf("Invalid input! Please enter a size equal to or less than 999: ");
        size = Get_Number();

    }

    /*I load the array, remove any duplicates that may exist, and then display the array on the screen*/
    Load_Array(array, size);
    Eliminating_Duplicates(array, &size);
    Show_Array(array, size);
    system("pause");
    system("cls");

    /*I sort the array from smallest to largest and display it sorted on the screen*/
    Sort_Array(array, size);
    Show_Array(array, size);
    system("pause");
    system("cls");

    /*I ask the user to enter a number to search in the array*/
    printf("What number do you want to search for in the array?: ");
    number = Get_Number();

    /*If the entered number is found, the function returns its position. However, if it is not found, that number is added to the array at 
    the corresponding position. Then I display the array with the modification made or not, and print the message indicating whether the 
    number was added or not and in which position it was added or found*/
    position = Find_Element(array, &size, number, &found);
    Show_Array(array, size);

    if(found == 0){
        printf("The element was not originally in the array, but it was added at position %d as can be seen!\n", position);
    }
    else{
        printf("The searched element was found at position %d as can be seen in the array!\n", position);
    }
    system("pause");
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

void Show_Array(int array[], int size){
    /*I declare the variables*/
    int i;

    /*With each iteration, I print the content of array[i]*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }

    printf("\n");
}

void Load_Array(int *array, int size){
    /*I declare the variables*/
    int i;

    /*I load the array with random numbers between 1 and 100*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 100) + 1;
    }
}

void Eliminating_Duplicates(int *array, int *size){
    /*I declare the variables*/
    int i, j, temp, counter = 0;

    /*If the number in array[i] is not equal to 0, and if array[j] is equal, array[j] becomes 0, and the counter increases by 1*/
    for(i = 0; i < *size + 1; i++){
        if(array[i] != 0){
            for(j = i + 1; j < *size; j++){

                if(array[i] == array[j]){
                    array[j] = 0;
                    counter++;
                }
            }

        }
    }

    /*Positions of array[i] and array[j] are exchanged if array[i] equals 0*/
    for(i = 0; i < *size - 1; i++){
        for(j = i + 1; j < *size; j++){
            if(array[i] == 0){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    /*I modify the size of the array so that later it does not count the 0s*/
    *size -= counter;
}

void Sort_Array(int *array, int size){
    /*I declare the variables*/
    int i, j, temp;
    
    /*I sort the array from smallest to largest, swapping positions of array[i] if it is greater than array[j]*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            if(array[j] < array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        
        }
    }

}

int Append_to_the_Array(int *array, int *size, int number){
    /*I declare the variables*/
    int i, counter = 0;

    /*I count the elements that are smaller than the number being searched for, to later move the rest one position to 
    the right without touching those that are smaller than the searched number*/
    for(i = 0; i < *size; i++){
        if(array[i] < number){
            counter += 1;
        }
        else{
            break;
        }
    }

    /*I move the numbers larger than the number being searched for, one position to the right*/
    for(i = *size - 1; i >= counter; i--){
        array[i + 1] = array[i];
    }
    array[counter] = number;

    /*I return the position where the number is placed*/
    return counter + 1;
}

int Find_Element(int *array, int *size, int number, int *found){
    /*I declare the variables*/
    int First_Half = 0, Second_Half = *size - 1, center, pos;

    /*While the number is not found or the other condition is not met, the loop will continue iterating*/
    while(*found == 0 && First_Half <= Second_Half){
        /*I calculate the central position of the array*/
        center = (First_Half + Second_Half) / 2;

        /*If the number is found, it exits the loop and returns the position where the searched number is located*/
        if(array[center] == number){
            *found = 1;
            pos = center + 1;
        }

        /*If the number to be searched for is larger than array[center], the variable 'firsthalf' changes its value; otherwise, 
        the variable 'second half' changes its value*/
        else{
            if(array[center] < number){
                First_Half = center + 1;
            }

            else{
                Second_Half = center - 1;
            }
        }
    }

    /*If the searched number is not found, it is added, and the position where it was added is returned*/
    if(*found == 0){
        pos = Append_to_the_Array(array, size, number);
    }

    return pos;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int i;
    int found = 0;
    int size1 = 5;
    int number1 = 2;
    int pos = 1;
    int test_Array[5] = {2, 1, 3, 4, 4};
    int result_array[4] = {1, 2, 3, 4};

    int found2 = 0;
    int size2 = 5;
    int number2 = 5;
    int pos2 = 4;
    int test_Array2[5] = {2, 1, 3, 4, 4};
    int result_array2[5] = {1, 2, 3, 4, 5};

    /*I am testing the functions*/
    Eliminating_Duplicates(test_Array, &size1);
    Eliminating_Duplicates(test_Array2, &size2);

    Sort_Array(test_Array, size1);
    Sort_Array(test_Array2, size2);

    Find_Element(test_Array, &size1, number1, &found);
    Find_Element(test_Array2, &size2, number2, &found2);

    for(i = 0; i < size1; i++){
        assert(test_Array[i] == result_array[i]);
    }
    assert(test_Array[pos] == number1);

    for(i = 0; i < size2; i++){
        assert(test_Array2[i] == result_array2[i]);
    }
    assert(test_Array2[pos2] == number2);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}