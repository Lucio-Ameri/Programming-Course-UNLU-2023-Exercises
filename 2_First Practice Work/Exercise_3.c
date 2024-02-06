#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
void Testing();
int Get_Number();
void Load_Array(int *array, int number);
void Show_Array(int *array, int number);
int Conditional_Addition(int *array1, int *array2, int number);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));
    
    /*I call the testing function*/
    Testing();

    /*I declare the variables*/
    printf("Enter the size of the array: ");
    int size = Get_Number();
    
            /*If the entered number is not even, ask for the number again*/
    while((size % 2) != 0){
        printf("Invalid input!! please enter an even number!\n");
        size = Get_Number();
    }

    int array_1[size], array_2[size], sum;
    
    system("cls");

    /*calls the 'load array' and 'show array' functions*/
    printf("Array one!\n");
    Load_Array(array_1, size);
    Show_Array(array_1, size);

    system("Pause");

    printf("Array two!\n");
    Load_Array(array_2, size);
    Show_Array(array_2, size);

    system("Pause");
    /*I perform the summation*/
    sum = Conditional_Addition(array_1, array_2, size);
    printf("The result of adding the even positions of the first array to the odd positions of the second array is %d\n", sum);

    system("Pause");
    system("cls"); 

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

void Load_Array(int *array, int number){
    /*I declare the variables*/
    int i;

    /* loads the array*/
    for(i = 0; i < number; i++){
        array[i] = rand() % 100 + 1;
    }

}

void Show_Array(int *array, int number){
    /*I declare the variables*/
    int i;
    
    /*Shows the vector*/
    for(i = 0; i < number; i++){
        printf("%3d", array[i]);
    }
    printf("\n");
}

int Conditional_Addition(int *array1, int *array2, int number){
    /*I declare the variables*/
    int i, sum = 0; 

    /*I add the even positions of the first array with the odd positions of the second array*/
    for(i = 0; i < number; i++){
        if(i % 2 == 0){
            sum += array1[i];
        }
        else{
            sum += array2[i];
        }
    }

    return sum;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I declare the variables*/
    int array1[] = {1, 2, 3, 4}, array2[] = {4, 3, 2, 1}, array3[] = {5, 4, 3, 2}, sum1 = 8, sum2 = 12;

    /*I am testing the function*/
    assert(Conditional_Addition(array1, array2, 4) == sum1);
    assert(Conditional_Addition(array1, array3, 4) != sum2);
    assert(Conditional_Addition(array3, array2, 4) == sum2);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls"); 
}