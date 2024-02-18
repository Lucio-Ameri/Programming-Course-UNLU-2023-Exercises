#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>
#define ROW 100
#define COLUMN 100

int Get_Number();
void Show_Array(int array[ROW][COLUMN], int size_row, int size_column);
void Load_Array(int array[ROW][COLUMN], int size_row, int size_column);
float Average_Temperature(int array[ROW][COLUMN], int size_row, int size_column);
void Lowest_Temperature(int array[ROW][COLUMN], int size_row, int *day, int *temp);
void Highest_Temperature(int array[ROW][COLUMN], int size_row, int *day, int *temp);
void Testing();

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int array[ROW][COLUMN], row, column = 3, day_of_the_minimum, temp_min, day_of_the_maximum, temp_max;
    float monthly_average;
    /*I ask for the sizes of the array*/
    printf("Enter the number of days the matrix will have: ");
    row = Get_Number();

    /*load the array and display it on the screen*/
    Load_Array(array, row, column);
    printf("The matrix is:\n");
    Show_Array(array, row, column);
    system("Pause");

    /* I will calculate the average temperature*/
    monthly_average = Average_Temperature(array, row, column);

    /*I will determine the dates when the highest and lowest temperatures occurred*/
    Lowest_Temperature(array, row, &day_of_the_minimum, &temp_min);
    Highest_Temperature(array, row, &day_of_the_maximum, &temp_max);

    /*I will display the monthly average temperature, along with the date of the highest and lowest temperatures*/
    printf("The average temperature for the month is %2.f degrees!\n", monthly_average);
    printf("On day %d, the temperature was %d degrees, which was the lowest temperature recorded!\n", day_of_the_minimum + 1, temp_min);
    printf("On day %d, the temperature was %d degrees, which was the highest temperature recorded!\n", day_of_the_maximum + 1, temp_max);

    system("pause");
    system("cls");

    return 0;
}

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
    system("cls");

    return Number;
}

void Show_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /* Declare the variables */
    int R, C;

    /* Print the column headers */
    printf("Day: \t    Temp_min: \t   Temp_max:\n");

    /* Iterate through each row of the array */
    for(R = 0; R < size_row; R++){
        
        /* Iterate through each column of the array */
        for(C = 0; C < size_column; C++){
            /* Print the content of array[R][C] */
            printf(" %d \t      ", array[R][C]);
        }
        
        printf("\n");
    }
}

void Load_Array(int array[ROW][COLUMN], int size_row, int size_column){
    /*I declare the variables*/
    int R, C;

    /*I load the array with random numbers between 1 and 10*/
    for(R = 0; R < size_row; R++){
        
        for(C = 0; C < size_column; C++){
            if(C == 0){
                array[R][C] = (R + 1);
            }

            else if(C == 1){
                array[R][C] = (rand() % 21) - 10;
            }
            else{
                array[R][C] = (rand() % 11) + 20;
            }
        }
    }
}

float Average_Temperature(int array[ROW][COLUMN], int size_row, int size_column){
    /* Declare the variables */
    float average = 0.0;
    int sum, R, C;

    /*In each iteration, I sum up the minimum and maximum temperatures in the variable sum 
    to calculate their average. Then, I add this average to the overall monthly average. 
    After performing this procedure for all days, I return the overall monthly average.*/
    for(R = 0; R < size_row; R++){
        sum = 0;
        
        for(C = 1; C < size_column; C++){
            sum += array[R][C];
        }

        average += (sum / 2);
    }

    return (average / size_row);
}

void Lowest_Temperature(int array[ROW][COLUMN], int size_row, int *day, int *temp){
    /* Declare the variables */
    int aux_t = 100, aux_d, R;

    /*In each iteration, I compare the minimum temperature of the day with the auxiliary variable aux_t. 
    If it is lower, the latter is updated with the value of the day's temperature at index R. This way, I 
    obtain the minimum temperature of the month and its corresponding day.*/
    for(R = 0; R < size_row; R++){            
        if(array[R][1] < aux_t){
            aux_t = array[R][1];
            aux_d = R;
        }
    }

    *(day) = aux_d;
    *(temp) = aux_t;
}

void Highest_Temperature(int array[ROW][COLUMN], int size_row, int *day, int *temp){
    /* Declare the variables */
    int aux_t = -100, aux_d, R;

    /*In each iteration, I compare the maximum temperature of the day with the auxiliary variable aux_t. 
    If it is higher, the latter is updated with the value of the day's temperature at index R. This way, I 
    obtain the maximum temperature of the month and its corresponding day.*/
    for(R = 0; R < size_row; R++){            
        if(array[R][2] > aux_t){
            aux_t = array[R][2];
            aux_d = R;
        }
    }

    *(day) = aux_d;
    *(temp) = aux_t;
}

void Testing(){
    /*I am testing the function*/
    printf("Starting the programs!! Please wait a moment!\n");
    sleep(3);

    /*I declare the variables*/
    int Testing_array[ROW][COLUMN] = {{1, 10, 20}, {2, -3, 7}, {3, 5, 19}};
    int row = 3, column = 3, test_daymin, test_temp_min, test_daymax, test_temp_max;
    int day_min = 1, day_max = 0, max = 20, min = -3;

    /*I am testing the functions*/
    Lowest_Temperature(Testing_array, row, &test_daymin, &test_temp_min);
    assert(day_min == test_daymin);
    assert(test_temp_min == min);

    Highest_Temperature(Testing_array, row, &test_daymax, &test_temp_max);
    assert(day_max == test_daymax);
    assert(test_temp_max == max);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");

}