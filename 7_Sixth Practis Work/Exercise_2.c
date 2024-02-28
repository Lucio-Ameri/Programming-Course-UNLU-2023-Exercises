#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Get_Option();
int Get_Days_Month(int month);
void Get_Temperatures(float *minimum, float *maximum);
void Create_Text_File(char file[], char option[]);
void Load_Temperatures_of_the_Month(char file[], char option[]);
void Read_Text_File(char file[], char option[]);
void Load_Temperatures_Statistics(char file[], char option[]);

int main(){
    /**/
    srand(time(NULL));

    /**/
    char file[] = "temperature.txt";
    int option = - 1;

    /**/
    while(option != 0){
        system("cls");
        printf("\t\t\t\t MENU: \n\n");
        printf("\t\t 1. Crear archivo de 'temperatures.txt'!\n");
        printf("\t\t 2. Cargar las temperaturas del año(Automaticamente)!\n");
        printf("\t\t 3. Leer el contenido del archivo!.\n");
        printf("\t\t 4. Estadisticas del archivo!\n");
        printf("\n\t\t Ingrese 0 para salir del menu: "); 
        option = Get_Option();

        switch(option){
            case 0: 
                system("cls");
                printf("\n\n\n\t\t\t Hasta la proxima\n");
                system("Pause");
                break;
            
            case 1:
                system("cls");
                Create_Text_File(file, "w");
                system("Pause");
                break;
            
            case 2:
                system("cls");
                Load_Temperatures_of_the_Month(file, "a");
                system("Pause");
                break;
            
            case 3:
                system("cls");
                Read_Text_File(file, "r");
                system("Pause");
                break; 
            case 4:
                system("cls");
                Load_Temperatures_Statistics(file, "r");
                system("Pause");
                break;
        }
    }

    return 0;
}

int Get_Option(){
    /*I declare the variables*/
    int flag = 1, Number;

    /*validates that what is entered by keyboard is a number between 0 and 4*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  && (Number < 0 || Number > 4)){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 0 and 4)\n");
            printf("Enter a valid number: ");
        }
            
        else{flag = 0;};
    }
    
    printf("\n");
    system("cls");

    return Number;
}

int Get_Days_Month(int month){
    /**/
    int days = 0;
    
    /**/
    switch(month){
        case 1:
            days = 31;
            break;
        
        case 2:
            days = 28;
            break;

        case 3:
            days = 31;
            break;

        case 4:
            days = 30;
            break;

        case 5:
            days = 31;
            break;

        case 6:
            days = 30;
            break;   

        case 7:
            days = 31;
            break;

        case 8:
            days = 31;
            break;

        case 9:
            days = 30;
            break;   

        case 10:
            days = 31;
            break;

        case 11:
            days = 30;
            break;

        case 12:
            days = 31;
            break;    
    }

    return days;
}

void Get_Temperatures(float *minimum, float *maximum){
    /**/
    *maximum = ((rand() % 11)+ 20) + (rand() % 100) / 100.0;
    *minimum = *maximum - rand() % 23  + (rand() % 100) / 100.0;
}

void Create_Text_File(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    fclose(fp);
}

void Load_Temperatures_of_the_Month(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp==NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int i = 0, days, month = 1, year = 2023;
    float temp_max = 0.0, temp_min = 0.0;

    /**/
    while(month < 13){
        /**/
        days = Get_Days_Month(month);
        i = 0;
        
        /**/
        while(i < days){
            Get_Temperatures(&temp_min, &temp_max);
            fprintf(fp, "%02d-%02d-%d %0.2f - %0.2f\n", i + 1, month, year, temp_min, temp_max);

            i++;
        }
        
        month++;
    }

    /**/
    fclose(fp);
}

void Read_Text_File(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp==NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int days, month, year; 
    float temp_min, temp_max;

    /**/
    fscanf(fp, "%d-%d-%d %f - %f", &days, &month, &year, &temp_min, &temp_max);

    while(feof(fp) == 0){
        printf("%02d-%02d-%d %.2f - %.2f\n", days, month, year, temp_min, temp_max);
        fscanf(fp, "%d-%d-%d %f - %f", &days, &month, &year, &temp_min, &temp_max);
    }

    /**/
    fclose(fp);

    printf("Se termino de leer el archivo!...\n");
}

void Load_Temperatures_Statistics(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp==NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int days_temp, days_min = 0, days_max = 0, month_temp, month_min = 0, month_max = 0, year = 0;
    int day_therm = 0, month_therm = 0;
    float temp_min, temp_max, temp_min_year = 1000.0, temp_max_year = -1000.0, temp_thermal_amp, max_thermal_amp = 0.0;

    /**/
    fscanf(fp, "%d-%d-%d %f - %f", &days_temp, &month_temp, &year, &temp_min, &temp_max);
    while(feof(fp) == 0){
        /**/
        temp_thermal_amp = temp_max - temp_min;

        /**/
        if(temp_thermal_amp > max_thermal_amp){
            
            max_thermal_amp = temp_thermal_amp;
            day_therm = days_temp;
            month_therm = month_temp;
        }

        /**/
        else if(temp_min < temp_min_year){
            
            temp_min_year = temp_min;
            days_min = days_temp;
            month_min = month_temp;
        }

        /**/
        else if(temp_max > temp_max_year){

            temp_max_year = temp_max;
            days_max = days_temp;
            month_max = month_temp;
        }

        fscanf(fp, "%d-%d-%d %f - %f", &days_temp, &month_temp, &year, &temp_min, &temp_max);
    }

    /**/
    fclose(fp);

    /**/
    printf("\t\t\tINFORME ANUAL DE TEMPERATURAS: \n");
    printf("Temperatura minima del año %d: %.2f\n", year, temp_min_year);
    printf("Registrada el dia: %i\n", days_min);
    printf("Del mes: %i\n\n", month_min);
    printf("Temperatura maxima del año %d: %.2f\n", year, temp_max_year);
    printf("Registrada el dia: %i\n", days_max);
    printf("Del mes: %i\n\n", month_max);
    printf("\t\t MAXIMA AMPLITUD TERMICA REGISTRADA:\n");
    printf("Termica: %.2f\n", max_thermal_amp);
    printf("Registrada el dia: %i\n", day_therm);
    printf("Del mes: %i\n", month_therm);
}