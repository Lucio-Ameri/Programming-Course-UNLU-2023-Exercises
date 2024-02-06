#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Modification(int *array, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int array[size], modifications;

    /*I load the first array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array);
    Show_Array(array);

    system("Pause");

    /*I save the number of modifications in this variable*/
    modifications = Modification(array, size);

    /*I print the following message on the screen and display the modified array*/
    printf("%d modifications were made to the array, and it is now as follows: \n", modifications);
    Show_Array(array);

    system("Pause");
    system("cls");

    return 0;
}

void Show_Array(int array[]){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%-4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array){
    /*I declare the variables*/
    int i;

    /*I use random numbers between 1 and 20 to fill the array*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 20) + 1;
    }
}

int Modification(int *array, int number){
    /*I declare the variables*/
    int i, j, modifications = 0;

    /* in this first loop, it takes the content of 'array[i]' and compares it with the rest 
    of the array to check for repeated numbers; if there are any, it replaces them with -1*/
    for(i = 0; i < number - 1; i++){ 
        
        if(array[i] != -1){
            for(j = i + 1; j < number; j++){
                if(array[i] == array[j]){
                    array[j] = -1;
                    modifications += 1;
                }
            }
        }
    }

    return modifications;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int vector[] ={1, 2, 1}, vector2[] ={2, 1, 3}, vector3[] ={3, 3, 3};

    /*I am testing the function*/
    assert(Modification(vector, 3) == 1);
    assert(Modification(vector2, 3) == 0);
    assert(Modification(vector3, 3) == 2);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}