#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define size 1000

/*Functions Prototypes*/
void Show_Array(int array[]);
void Load_Array(int *array);
int Most_Common_Age(int *array, int number);
void Testing();


int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[size], age;

    /*I load the array and display it on the screen*/
    Load_Array(array);
    Show_Array(array);

    /*I call 'most common age' and save it in 'age', then, I show it on the screen*/
    age = Most_Common_Age(array, size);
    printf("The age that repeats the most in the array is: '%d'\n", age);

    system("Pause");
    system("cls");

    return 0;
}


void Show_Array(int array[]){
    /*I declare the variables*/
    int i;

    /*I print the content of array[i] on each iteration*/
    for(i = 0; i < size; i++){
        printf("%d", array[i]);
        printf("---");
    }
    printf("\n\n");
}

void Load_Array(int *array){
    /*I declare the variables*/
    int i;

    /*I fill the array with random numbers between 18 and 100*/
    for(i = 0; i < size; i++){
        array[i] = rand() % (100 - 18 + 1) + 18;
    }
}

int Most_Common_Age(int *array, int number){
    /*I declare the variables*/
    int current_age, appears, most_repeated = 0, times = 0;
    int i, j;

    /*this loop sets 'current age' to the content of array[i]*/
    for(i = 0; i < number; i++){
        current_age = array[i];
        appears = 1;

        /*this 'while' skips array positions until the content of array[i] is different from the currently 
        most repeated age, to save iterations*/
        while(current_age == most_repeated){
            i += 1;
            current_age = array[i];
        }

        /*this second loop compares 'current age' with the rest of the array, if they are equal, it adds 1 to 'appears'*/
        for(j = i + 1; j < number; j++){
            if (array[j] == current_age){
                appears += 1;
            }
        }

        /*if 'appears' is greater, it changes the content of the variables*/
        if(appears > times){
            times = appears;
            most_repeated = current_age;
        }
    }

    return most_repeated;  
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int vector[] = {1, 1, 2, 3, 4}, vector2[] = {1, 2, 2, 3, 4};
    int result1 = 1, result2 = 2;

    /*I am testing the function*/
    assert(Most_Common_Age(vector, 5) == result1);
    assert(Most_Common_Age(vector2, 5) == result2);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}

