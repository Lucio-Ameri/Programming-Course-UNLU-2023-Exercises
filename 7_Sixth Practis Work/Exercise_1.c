#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define SIZE_MONTH 50

int Get_Number();
int Get_Option();
int Get_Month(char *month);
void Create_Text_File(char file[], char option[]);
void Load_Text_File(char file[], char option[], char month[], int days);
void Read_Text_File(char file[], char option[]);
void Load_The_Rainfall_Statistics(char file[], char option[], char month[]);

int main(){
    /**/
    srand(time(NULL));

    /**/
    char file[] = "rain.txt"; 
    char month[SIZE_MONTH];
    printf("En que mes del año estamos?(ingrese un numero del 1 al 12): "); 
    int days = Get_Month(month);
    int flag = - 1;

    /**/
    while(flag != 0){
        system("cls");
        printf("\t\t\t\t Menu \n\n");
        printf("\t\t 1. Crear archivo de lluvia.\n");
        printf("\t\t 2. Escribir en el archivo de Prueba(Automaticamente).\n");
        printf("\t\t 3. Leer el contenido del archivo de Prueba.\n");
        printf("\t\t 4. Estadisticas del archivo.\n");
        printf("\n\t\t Ingrese 0 para salir del menu: "); 
        flag = Get_Option();

        switch(flag){
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
                Load_Text_File(file, "a", month, days);
                system("Pause");
                break;
            
            case 3:
                system("cls");
                Read_Text_File(file, "r");
                system("Pause");
                break; 
            case 4:
                system("cls");
                Load_The_Rainfall_Statistics(file, "r", month);
                system("Pause");
                break;
        }
    }
    
    return 0;
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 1, Number;

    /*validates that what is entered by keyboard is a number between 1 and 12*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  || Number < 1 || Number > 12){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 1 and 12)\n");
            printf("Enter a valid number: ");
        }
            
        else{flag = 0;};
    }
    
    printf("\n");
    system("cls");

    return Number;
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

int Get_Month(char *month){
    /**/
    int option = Get_Number();
    int days;
    
    /**/
    switch(option){
        case 1:
            strcpy(month, "January");
            days = 31;
            break;
        
        case 2:
            strcpy(month, "February");
            days = 28;
            break;

        case 3:
            strcpy(month, "March");
            days = 31;
            break;

        case 4:
            strcpy(month, "April");
            days = 30;
            break;

        case 5:
            strcpy(month, "May");
            days = 31;
            break;

        case 6:
            strcpy(month, "June");
            days = 30;
            break;   

        case 7:
            strcpy(month, "July");
            days = 31;
            break;

        case 8:
            strcpy(month, "August");
            days = 31;
            break;

        case 9:
            strcpy(month, "September");
            days = 30;
            break;   

        case 10:
            strcpy(month, "October");
            days = 31;
            break;

        case 11:
            strcpy(month, "November");
            days = 30;
            break;

        case 12:
            strcpy(month, "December");
            days = 31;
            break;    
    }

    return days;
}

void Create_Text_File(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);
    fclose(fp);
}

void Load_Text_File(char file[], char option[], char month[], int days){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp==NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int i = 0, year = 2023, precipitations;

    /**/
    while(i < days){
        precipitations = rand() % 101;
        fprintf(fp, "%02i-%s-%02i %i\n", i + 1, month, year, precipitations);
        i++;
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
    char Month[SIZE_MONTH];
    int day, year, precipitations;

    /**/
    fscanf(fp,"%d-%[^-]-%d %d", &day, Month, &year, &precipitations);
    while(feof(fp) == 0){
        printf("%02i-%s-%02i %i\n", day, Month, year, precipitations);
        fscanf(fp,"%d-%[^-]-%d %d", &day, Month, &year, &precipitations);
    }

    /**/
    fclose(fp);
    printf("\n Se termino de leer el archivo!\n");
}

void Load_The_Rainfall_Statistics(char file[], char option[], char month[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp==NULL){
        perror("Error de apertura!\n");
    }

    /**/
    char Month[SIZE_MONTH];
    int day, year, precipitations;
    int rain_free_days = 0, days_less_50mm = 0, days_greater_50mm = 0;

    /**/
    while(feof(fp) == 0){
        fscanf(fp,"%d-%[^-]-%d %d", &day, Month, &year, &precipitations);
        if (precipitations > 0){
            if (precipitations < 50){
                days_less_50mm += 1;
            }
            else{
                days_greater_50mm += 1;
            }
        }
        else{
            rain_free_days += 1; 
        }
    }
    
    /**/
    fclose(fp);

    /**/
    printf("Las estadisticas de lluvias en %s son: \n", month);
    printf("Dias sin lluvia: %i\n", rain_free_days);
    printf("Dias con lluvias menores a 50mm: %i\n", days_less_50mm);
    printf("Dias con lluvias mayores a 50mm: %i\n", days_greater_50mm);
}