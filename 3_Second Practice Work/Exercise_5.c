#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#include <math.h>

int Get_Number();
void Show_Array(int array[], int size);
void Show_Array_Float(float array[], int size);
void Load_ID(int *array, int size);
void Load_Array(float *array, int size);
void Order_the_Array(int *array, int size);
void School_Average(int *array_ID, float *array_N, float *array_A, int size_ID, int size_N);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));
    
    /*I declare the variables*/
    int size_ID = Get_Number();
    int size_N = (size_ID * 3);
    int array_ID[size_ID];
    float array_N[size_N], array_A[size_ID];

    /*I ask the user to specify the number of students in the classroom, so they can then input their IDs one by one. 
    Next, I proceed to sort the IDs and print out the result on the screen*/
    printf("ID ARRAY:\n");
    Load_ID(array_ID, size_ID);
    Order_the_Array(array_ID, size_ID);
    Show_Array(array_ID, size_ID);

    system("Pause");
    system("cls");

    /* I load the grades randomly*/
    Load_Array(array_N, size_N);
    Show_Array_Float(array_N, size_N);

    system("Pause");
    system("cls");

    /*I calculate the averages for each student and store them in an ordered manner (the average of student i in 
    position i of array_A), and display a list on the screen*/
    School_Average(array_ID, array_N, array_A, size_ID, size_N);

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

void Show_Array(int array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4d", array[i]);
    }
    printf("\n\n");
}

void Show_Array_Float(float array[], int size){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] with each iteration*/
    for(i = 0; i < size; i++){
        printf("%4.2f", array[i]);
    }
    printf("\n\n");
}

void Load_Array(float *array, int size){
    /*I declare the variables*/
    int i;

    /*I load the array with random numbers between 1 and 30*/
    for(i = 0; i < size; i++){
        array[i] = (rand() % 10) + 1;
    }

}

void Load_ID(int *array, int size){
    /*I declare the variables*/
    int i;

    /*I load the array with random numbers between 1 and 30*/
    for(i = 0; i < size; i++){
        array[i] = Get_Number();
    }

}

void Order_the_Array(int *array, int size){
    /*I declare the variables*/
    int i, j, aux;

    /*I use nested loops to traverse the array, looking for values that are greater than the next one, in order to sort 
    the array from smallest to largest*/
    for(i = 0; i < size - 1; i++){
        for(j = i + 1; j < size; j++){
            
            if(array[i] > array[j]){
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void School_Average(int *array_ID, float *array_N, float *array_A, int size_ID, int size_N){
    /*I declare the variables*/
    int i = 0, counter = 0, aux = 0;
    float average = 0;

    /*I accumulate 3 grades at a time to calculate the average of a student, then I load it into array_A*/
    while(i != size_N){
        if(counter > 3){
            
            array_A[aux] = average / 3;
            aux++;
            average = 0;
            counter = 0;
        }

        average += array_N[i];
        i++;
        counter++;
    }
    /*I print a list of all students and their respective averages.*/
    for(i = 0; i < size_ID; i++){
        printf("The average of the student with ID %d is: %2.f\n", array_ID[i], array_A[i]);
    }
}