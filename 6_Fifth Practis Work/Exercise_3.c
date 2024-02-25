#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define SIZE_ARRAY 1000

int Get_Number();
void Show_Array(int ID_array[], float Average_array[], int size);
void Load_Array(int *ID_array, float *Average_array, int size);
void Sort_Array(int *ID_array, float *Average_array, int size);
void Testing();


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int ID_array[SIZE_ARRAY], size;
    float Average_array[SIZE_ARRAY];

    /*I ask the user to enter a size within the established range. If the maximum is exceeded, it asks for the number again until it 
    is within the range*/
    printf("Enter the size of the array (up to a maximum of 1000): ");
    size = Get_Number();
    while(size > 1000){
        printf("Invalid input! Please enter a size equal to or less than 1000: ");
        size = Get_Number();

    }

    /*I load and display the array on the screen*/ 
    Load_Array(ID_array, Average_array, size);
    Show_Array(ID_array, Average_array, size);

    /*I sort the arrays and display them on the screen*/
    Sort_Array(ID_array, Average_array, size);
    Show_Array(ID_array, Average_array, size);

    return 0;
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 0, Number;

    /*validates that what is entered by keyboard is a number*/
    if(scanf("%d", &Number) != 1 || Number == 0){
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

void Show_Array(int ID_array[], float Average_array[], int size){
    /*I declare the variables*/
    int i;

    /*With each iteration, I print the content of arrays[i]*/
    printf("IDS | AVERAGES | \n");
    for(i = 0; i < size; i++){
        printf("%04d | \t %2.2f | \n", ID_array[i], Average_array[i]);
    }

    system("pause");
    system("cls");
}

void Load_Array(int *ID_array, float *Average_array, int size){
    /*I declare the variables*/
    int i, j, ID;

    /*I fill the array with 0s*/
    for(i = 0; i < size; i++){
        ID_array[i] = 0;
    }

    /*While y is less than size, the loop will continue to execute*/
    i = 0;
    while(i < size){
        /*I ask the user for the ID of student[i]*/
        printf("Enter the ID of student %d (greater than 0): ", i + 1);
        ID = Get_Number();

        /*If the entered ID is repeated, I ask for the ID again until it is one that is not in the array*/
        for(j = 0; j < i; j++){
            if(ID_array[j] == ID){
                printf("Repeated ID!! Please enter a different ID: ");
                ID = Get_Number();
                
                j = 0;
            }
            if(ID_array == 0){
                j = 0;
                break;
            }
        }
        
        /*I load the provided ID into the array and generate a random average between 1 and 10*/
        ID_array[i] = ID;
        Average_array[i] = (((float)rand() / RAND_MAX) * 9) + 1;
        
        i++;
    }
}

void Sort_Array(int *ID_array, float *Average_array, int size){
    /*I declare the variables*/
    int i, j, temp;

    /*If the ID of array[i] is greater than the ID of array[j], their contents are swapped, so that the IDs are sorted from 
    smallest to largest and there is correlation with their grades*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){

            if(ID_array[i] > ID_array[j]){
                temp = ID_array[j];
                ID_array[j] = ID_array[i];
                ID_array[i] = temp;

                temp = Average_array[j];
                Average_array[j] = Average_array[i];
                Average_array[i] = temp;
            }
        }
    }
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int i;
    int ID_testing[5] = {1, 3, 2, 4, 5};
    float Average_testing[5] = {5.5, 4.3, 7.0, 9.3, 2.2};

    int ID_result[5] = {1, 2, 3, 4, 5};
    float Average_result[5] = {5.5, 7.0, 4.3, 9.3, 2.2};

    Sort_Array(ID_testing, Average_testing, 5);

    for(i = 0; i < 5; i++){
        assert(ID_testing[i] == ID_result[i]);
        assert(Average_testing[i] == Average_result[i]);
    }

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}