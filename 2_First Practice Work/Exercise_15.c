#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 50

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Odd_Addition(int *array, int number);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    int array[size], Addition;

    /*I load the array and display it on the screen*/
    printf("The array is: ");
    Load_Array(array);
    Show_Array(array);

    system("Pause");

    /*I receive the result of the sum of the odd numbers from the function and then print it on the screen*/
    Addition = Odd_Addition(array, size);
    printf("The result of adding the odd positions is: %d \n", Addition);

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

int Odd_Addition(int *array, int number){
    /*I declare the variables*/
    int i, odd = 0;

    /*If the condition is met, it adds the value of array[i] to the accumulator in each iteration; afterwards, 
    the rest is for beautifying the output*/
    printf("Add odd positions: ");
    for(i = 0; i < number; i++){
        if((i % 2) != 0){
            odd += array[i];
            printf("%d", array[i]);

            if((i < number - 2) && (odd != 0)){
                printf(" + ");
            }
        }
        
    }
    printf("\n");

    return odd;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int array[] = {1, 2, 3, 4, 5}, result = 6;

    /*I am testing the function*/
    assert(Odd_Addition(array, 5) == result);
    system("cls");

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}