#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Functions Prototypes*/
int Get_Number();
int Random_Number(int maximum, int minimum);
void Load_Array(int *array, int number, int maximum, int minimum);
void Show_Array(int *array, int number);

int main(){
    /*I create a seed to be able to use random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    /*I use 'get number' to load the variables*/
    printf("Enter the size of the array: ");
    int number = Get_Number();
    int array[number], minimum, maximum;
    
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
    Load_Array(array, number, maximum, minimum);
    Show_Array(array, number);

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