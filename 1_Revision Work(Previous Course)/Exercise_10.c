#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Function Prototype*/
void Type_of_Pump(int barcode);

int main(){
    /*I create a seed to be able to use random numbers*/
    srand(time(NULL));

    /*I generate the code for the pump to inquire*/
    int code = rand() % 11;

    /* I call the function*/
    while(code != 9){
        Type_of_Pump(code);
        code = rand() % 11;
    }

    system("Pause");
    system("cls");

    return 0;
}

void Type_of_Pump(int barcode){
    
    /*the switch statement takes care of printing a message depending on the provided code*/
    switch(barcode){
        case 0:
            printf("No defined value for the pump type!\n");
            break;
        
        case 1:
            printf("The pump is a water pump!\n");
            break;
        
        case 2:
            printf("The pump is a gasoline pump!\n");
            break;
        
        case 3:
            printf("The pump is a concrete pump!\n");
            break;

        case 4:
            printf("The pump is a food paste pump!\n");
            break;

        default:
            printf("There is no valid value for the pump type!\n");
            break;   
    }
}