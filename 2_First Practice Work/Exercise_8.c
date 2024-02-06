#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Equality(int *array_1, int *array_2, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int array_1[size], array_2[size], option;

    /*I load the first array and display it on the screen*/
    printf("First array:\n");
    Load_Array(array_1);
    Show_Array(array_1);

    system("Pause");
    
    /*I load the second array and display it on the screen*/
    printf("Second array:\n");
    Load_Array(array_2);
    Show_Array(array_2);
    
    /*I save the result of comparing the two arrays in 'option'*/
    option = Equality(array_1, array_2, size);

    /*I use a 'switch' to print the result of the comparison*/
    switch(option){
        case 0:
            printf("They are not identical.\n");
            break;
        
        case 1:
            printf("A miracle happened, they are two identical arrays!! You won't see it ever again!\n");
            break;
    }

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

int Equality(int *array_1, int *array_2, int number){
    /*I declare the variables*/
    int i, flag = 1;

    /*it compares the two arrays, and if the content is not equal, it breaks the loop and returns 0, 
    otherwise, it returns 1.*/
    for(i = 0; i < number; i++){
        if(array_1[i] != array_2[i]){
            flag = 0;
            break;
        }
    }
    
    return flag;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int vector[] ={1, 1, 1}, vector2[] ={2, 2, 2}, vector3[] ={1, 1, 1};

    /*I am testing the function*/
    assert(Equality(vector, vector2, 3) == 0);
    assert(Equality(vector3, vector2, 3) == 0);
    assert(Equality(vector, vector3, 3) == 1);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}