#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>
#define SIZE 100

int Get_Number();
char Get_Char();
void Show_Array(int array[], int size);
void Load_Array(int *array, int size_array, int option);
void Order_the_Array(int *array, int size);
void Request_Function(int *array, int *size_array, char action, int number);
void Delete_Element(int *array, int *size_array, int number_to_delete);
void Add_Last_Position(int *array, int *size_array, int number);
void Add_Where_Requested(int *array, int *size_array, int number);

int main(){

    int array[SIZE], option = 0, size_array, number, flag = 1;
    char action;

    printf("Enter the size of the array! : ");
    size_array = Get_Number();

    printf("How would you like to load the array? (1 = manually; 2 = empty; 3 = random) : ");
    option = Get_Number();

    Load_Array(array, size_array, option);
    Show_Array(array, size_array);
    system("pause");
    system("cls");

    while(flag == 1){
        printf("What action would you like to perform on the array?\n");
        printf("\t\t press 'I' to add a number in the last position of the array.\n");
        printf("\t\t press 'B' to remove a number of the array.\n");
        printf("\t\t press 'A' to add a number to the desired position of the array.\n");
        printf("\t\t press 'Q' to Exit.\n");
        printf("Enter The action!: "); action = Get_Char();
        system("cls");
        
        if(action != 'Q'){
        Request_Function(array, size_array, action, number);
        }

        else{
            flag = 0;
        }
    }

    return 0;
}
