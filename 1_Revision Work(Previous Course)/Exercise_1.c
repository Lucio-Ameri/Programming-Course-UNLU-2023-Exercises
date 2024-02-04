#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>


/*Functions prototypes*/
float Get_Number();
float Arithmetic_Addition(float x, float y);
void Testing();

int main(){
    
    /*I declare the variables*/
    float a, b, addition;

    /*I call testing function*/
    Testing();

    /*A validated number is entered in the variables*/
    printf("Enter the first number: ");
    a = Get_Number();
    printf("Enter the second number: ");
    b = Get_Number();

    /*I call the arithmetic addition function*/
    addition = Arithmetic_Addition(a, b);

    /*I show the result on the screen*/
    printf("\n Adding %0.1f + %0.1f results in %0.1f\n", a, b, addition);

    return 0;
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

float Arithmetic_Addition(float x, float y){
    return (x + y);
}

void Testing(){
    printf("Verifying the proper operation of the program!\n");
    sleep(3);
    
    /*I am testing the function*/
    assert(Arithmetic_Addition(4, 5) == 9);
    assert(Arithmetic_Addition(4, -5) == -1);
    assert(Arithmetic_Addition(0, 0) == 0);
    assert(Arithmetic_Addition(-4, -5) == -9);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}