#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
float Arithmetic_Subtraction(float x, float y);
float Get_Number();
void Testing();

int main(){
    /*I declare the variables*/
    float a, b, Subtraction; 

    /*I call the testing function*/
    Testing();

    /*A validated number is entered in the variables*/
    printf("Enter the First Number: ");
    a = Get_Number();
    printf("Enter the Second Number: ");
    b = Get_Number();

    /*I call the arithmetic Subtraction function*/
    Subtraction = Arithmetic_Subtraction(a, b);

    /*I show the result on the screen*/
    printf("\n Subtracting %0.1f - %0.1f results in %0.1f\n", a, b, Subtraction);

    return 0;
}

/*I declare the function*/
float Arithmetic_Subtraction(float x, float y){
    return (x - y);
}

float Get_Number(){
    /*I declare the variables*/
    int flag = 0;
    float Number;

    /*validates that what is entered by keyboard is a number*/
    if(scanf("%f", &Number) != 1 ){
        fflush(stdin);
        flag = 1;
        printf("\nInvalid input. Please enter a valid number!\n");
        
        while(flag == 1){
            printf("Enter a valid number: ");
            
            if(scanf("%f", &Number) != 1){
                fflush(stdin);
                printf("\nInvalid input. Please enter a valid number!\n");
            }
            
            else{flag = 0;}
        }
    }

    return Number;
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);
    
    /*I am testing the function*/
    assert(Arithmetic_Subtraction(4, 5) == -1);
    assert(Arithmetic_Subtraction(4, -5) == 9);
    assert(Arithmetic_Subtraction(0, 0) == 0);
    assert(Arithmetic_Subtraction(-4, -5) == 1);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}