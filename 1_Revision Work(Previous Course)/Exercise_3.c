#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
float Multiplication(float x, float y);
float Get_Number();
void Testing();

int main(){
    /*I declare the variables*/
    float a, b, mult; 

    /*I call the testing function*/
    Testing();

    /*A validated number is entered in the variables*/
    printf("Enter the First Number: ");
    a = Get_Number();
    printf("Enter the Second Number: ");
    b = Get_Number();

    /*I call the multiplication function*/
    mult = Multiplication(a, b);

    /*I show the result on the screen*/
    printf("\n multiplication of %0.1f x %0.1f results in %0.1f\n", a, b, mult);

    return 0;
}

/*I declare the function*/
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
    
    /*I am testing the function*/
    assert(Multiplication(4, 5) == 20);
    assert(Multiplication(4, -5) == -20);
    assert(Multiplication(0, 0) == 0);
    assert(Multiplication(-4, -5) == 20);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}