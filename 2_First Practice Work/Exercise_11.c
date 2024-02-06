#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Quantity_of_Zero(int *array, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[size], zero;

    /*I load the array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array);
    Show_Array(array);

    /*I call the 'Quantity of Zero' function to find out the number of Zeros in the array*/
    zero = Quantity_of_Zero(array, size);

    /*I display on the screen the quantity of Zeros in the array*/
    printf("The array has %d zeros.\n", zero);

    system("Pause");
    system("cls");

    return 0;
}

void Show_Array(int array[]){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    printf("\n\n");
}

void Load_Array(int *array){
    /*I declare the variables*/
    int i;

    /*I use random numbers between -10 and 10 to fill the array*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 20) - 10;
    }
}

int Quantity_of_Zero(int *array, int number){    
    /*I declare the variables*/
    int i, zero = 0;

    /*each time array[i] is a Zero Number, the 'zero' counter increments by 1*/
    for(i = 0; i < number; i++){
        if(array[i] == 0){
            zero += 1;
        }
    }

    return zero;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int vector[] ={-1, 2, 1}, vector2[] ={0, 0, 0}, vector3[] ={0, 3, 3};

    /*I am testing the function*/
    assert(Quantity_of_Zero(vector, 3) == 0);
    assert(Quantity_of_Zero(vector2, 3) == 3);
    assert(Quantity_of_Zero(vector3, 3) == 1);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}