#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
float Arithmetic_Addition(float x, float y);
float Arithmetic_Subtraction(float x, float y);
float Multiplication(float x, float y);
float Get_Number();
void Testing();

int main(){
    /*I declare the variables*/
    float a, b, accumulator;
    int option = -1;

    /*I call the testing function*/
    Testing();
    
    /*Loop that continues until a 0 is entered as an option*/
    while(option != 0){
        printf("\t\t\t Calculator!!\n");
        printf("Addition (enter 1); Subtract (enter 2); Multiply (enter 3); Exit (enter 0): "); scanf("%d", &option);

        /*Options*/
        switch(option){
            
            /*Program end*/
            case 0:
                printf("\n Until next time!!\n");
                system("Pause");
                system("cls");
                break;

            case 1:
                printf("\n You have selected addition\n");

                /*A validated number is entered in the variables*/
                printf("Enter the First Number: ");
                a = Get_Number();
                printf("Enter the Second Number: ");
                b = Get_Number();

                /*I call the arithmetic addition function*/
                accumulator = Arithmetic_Addition(a, b);

                /*I show the result on the screen*/
                printf("\n Adding %0.1f + %0.1f results in %0.1f\n", a, b, accumulator);
                
                system("Pause");
                system("cls");
                break;

            case 2:
                printf("\n You have selected Subtract\n.");

                /*A validated number is entered in the variables*/
                printf("Enter the First Number: ");
                a = Get_Number();
                printf("Enter the Second Number: ");
                b = Get_Number();

                /*I call the arithmetic subtraction function*/
                accumulator = Arithmetic_Subtraction(a, b);

                /*I show the result on the screen*/
                printf("\n Subtracting %0.1f - %0.1f results in %0.1f\n", a, b, accumulator);

                system("Pause");
                system("cls");
                break; 

            case 3:
                printf("\n You have selected Multiply\n.");

                /*A validated number is entered in the variables*/
                printf("Enter the First Number: ");
                a = Get_Number();
                printf("Enter the Second Number: ");
                b = Get_Number();

                /*I call the multiplication function*/
                accumulator = Multiplication(a, b);

                /*I show the result on the screen*/
                printf("\n multiplication of %0.1f x %0.1f results in %0.1f\n", a, b, accumulator);

                system("Pause");
                system("cls");
                break;
        }
    }

    return 0;
}

/*I declare the functions*/
float Arithmetic_Addition(float x, float y){
    return (x + y);
}

float Arithmetic_Subtraction(float x, float y){
    return (x - y);
}

float Multiplication(float x, float y){
    return (x * y);
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
    
    /*I am testing the functions*/
    /*Testing addition*/
    assert(Arithmetic_Addition(4, 5) == 9);
    assert(Arithmetic_Addition(4, -5) == -1);
    assert(Arithmetic_Addition(0, 0) == 0);
    assert(Arithmetic_Addition(-4, -5) == -9);

    /*Testing subtraction*/
    assert(Arithmetic_Subtraction(4, 5) == -1);
    assert(Arithmetic_Subtraction(4, -5) == 9);
    assert(Arithmetic_Subtraction(0, 0) == 0);
    assert(Arithmetic_Subtraction(-4, -5) == 1);

    /*Testing multiplication*/
    assert(Multiplication(4, 5) == 20);
    assert(Multiplication(4, -5) == -20);
    assert(Multiplication(0, 0) == 0);
    assert(Multiplication(-4, -5) == 20);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}