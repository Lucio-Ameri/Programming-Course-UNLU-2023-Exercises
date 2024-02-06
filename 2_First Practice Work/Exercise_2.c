#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
int Get_Number();
int Random_Number(int maximum, int minimum);
void Load_Array(int *array, int number, int maximum, int minimum);
void Show_Array(int *array, int number);
int Dot_Product(int *array_1, int *array_2, int number);
void Testing();

int main(){
    /*I create a seed to be able to use random numbers*/
    srand(time(NULL));
    
    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    /*I use 'get number' to load the variables*/
    printf("Enter the size of the array: ");
    int number = Get_Number();
    int array_1[number], array_2[number], minimum, maximum, result;
    
    printf("Enter a minimum number: ");
    minimum = Get_Number();

    printf("Enter a maximum number: ");
    maximum = Get_Number();

    /*If the condition is met, it allows the number to be entered again*/
    if (maximum <= minimum){
        while(maximum <= minimum){
            printf("Invalid maximum input!. Please enter a number higher than %d\n", minimum);
            maximum = Get_Number();
        }
    }

    /*calls the 'load array' and 'show array' functions*/
    printf("Array one! \n");
    Load_Array(array_1, number, maximum, minimum);
    Show_Array(array_1, number);

    printf("Array two! \n");
    Load_Array(array_2, number, maximum, minimum);
    Show_Array(array_2, number);

    /*I call 'Dot product'*/
    result = Dot_Product(array_1, array_2, number);

    return 0;
}

/*I declare the functions*/
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

int Random_Number(int maximum, int minimum){
    /*Generates a random number between minimum and maximum*/
    return rand() % (maximum - minimum + 1) + minimum; 
}

void Load_Array(int *array, int number, int maximum, int minimum){
    /*I declare the variables*/
    int i;

    /* loads the array*/
    for(i = 0; i < number; i++){
        array[i] = Random_Number(maximum, minimum);
    }

}

void Show_Array(int *array, int number){
    /*I declare the variables*/
    int i;
    
    /*Shows the vector*/
    printf("The vector ended up in the following way: \n");
    for(i = 0; i < number; i++){
        printf("%3d", array[i]);
    }
    printf("\n");
}

int Dot_Product(int *array_1, int *array_2, int number){
    /*I declare the variables*/
    int i, accumulator = 0;

    /*I iterate through the vectors, accumulating the product of both at position i*/
    printf("To take the dot product of: ");
    for(i = 0; i < number; i++){
        printf("(%d x %d) ", array_1[i], array_2[i]);
        accumulator += (array_1[i] * array_2[i]);

        if(i != number - 1){
            printf("+ ");
        }
    }
    printf("its %d\n", accumulator);

    return accumulator;
}


void Testing() {
    printf("Verifying the proper operation of the program!\n");
    sleep(3);
    
    /*I declare the variables*/
    int array1[] = {1, 2, 3}, array2[] = {3, 2, 1}, result = 10, result2 = 11, result3 = 12; 

    /*I am testing the function*/
    assert(Dot_Product(array1, array2, 3) == result);
    assert(Dot_Product(array1, array2, 3) != result2);
    assert(Dot_Product(array1, array2, 3) != result3);
    system("cls");

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}