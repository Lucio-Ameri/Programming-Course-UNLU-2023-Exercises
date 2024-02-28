#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_SURVEY_RESPONDENTS 1000

typedef struct{
    int gender;
    int age;
    int marital_status;
    int are_employed;
    int are_student;
} person;

int Get_Option();
int Get_Number();
void Load_register(person *survey, int persons);
void Create_Text_File(char file[], char option[]);
void Load_Survey(char file[], char option[], person survey[], int persons);
void Read_Text_File(char file[], char option[]);
void Load_Survey_Statistics(char file[], char option[]);

int main(){
    /**/
    srand(time(NULL));

    /**/
    char file[] = "Survey.txt";
    person Survey_data[SIZE_SURVEY_RESPONDENTS];
    int option = -1, number_of_respondents;

    /**/
    printf("Cuantos encuestados habra?(maximo 1000): ");
    number_of_respondents = Get_Number();

    /**/
    Load_register(Survey_data, number_of_respondents);

    /**/
    while(option != 0){
        printf("\t\t\t\t Menu \n\n");
        printf("\t\t 1. Crear archivo de 'Survey.txt'!\n");
        printf("\t\t 2. Escribir en el archivo 'Survey.txt'(Automaticamente)!\n");
        printf("\t\t 3. Leer el contenido del archivo 'Survey.txt'!\n");
        printf("\t\t 4. Estadisticas del archivo!\n");
        printf("\n\t\t Ingrese 0 para salir del menu: "); 
        option = Get_Option();
        system("cls");

        switch(option){
            case 0: 
                printf("\n\n\n\t\t\t Hasta la proxima\n");
                system("Pause");
                system("cls");
                break;
            
            case 1:
                Create_Text_File(file, "w");
                system("Pause");
                system("cls");
                break;
            
            
            case 2:
                Load_Survey(file, "a", Survey_data, number_of_respondents);
                system("Pause");
                system("cls");
                break;
            
            
            case 3:
                Read_Text_File(file, "r");
                break; 
            
            case 4:
                Load_Survey_Statistics(file, "r");
                system("Pause");
                system("cls");
                break;
        
        }
    }
    
    return 0;
}

int Get_Number(){
    /*I declare the variables*/
    int flag = 1, Number;

    /*validates that what is entered by keyboard is a number between 1 and 1000*/
    while(flag == 1){
        
        if((scanf("%d", &Number) != 1)  || Number < 1 || Number > 1000){
            fflush(stdin);
            printf("\nInvalid input. Please enter a valid number! (The number must be between 1 and 1000)\n");
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

void Load_register(person *survey, int persons){
    /**/
    int i = 0;

    /**/
    while(i < persons){
        survey[i].gender = (rand() % 2) + 1;
        survey[i].age = (rand() % 80) + 15;
        survey[i].marital_status = (rand() % 3) + 1;
        survey[i].are_employed = (rand() % 2);
        survey[i].are_student = (rand() % 2);

        i++;
    }
}

void Create_Text_File(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);
    
    /**/
    fclose(fp);
}

void Load_Survey(char file[], char option[], person survey[], int persons){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp == NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int i = 0;

    /**/
    while(i < persons){
        fprintf(fp, "%d-%d-%d-%d-%d\n", survey[i].gender, survey[i].age, survey[i].marital_status, survey[i].are_employed, survey[i].are_student);

        i++;
    }

    /**/
    fclose(fp);
}

void Read_Text_File(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp == NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int gender, age, martial_status, employed, student;

    /**/
    printf("| GENDER | \t | AGE | \t | MARTIAL STATUS | \t | WORKS | \t | STUDENT |\n");
    fscanf(fp, "%d-%d-%d-%d-%d", &gender, &age, &martial_status, &employed, &student);
    while(feof(fp) == 0){
        printf("| %-8d | \t | %-3d | \t | %-14d | \t | %-5d | \t | %-7d |\n", gender, age, martial_status, employed, student);
        fscanf(fp, "%d-%d-%d-%d-%d", &gender, &age, &martial_status, &employed, &student);
    }

    /**/
    fclose(fp);

    system("Pause");
    system("cls");
}

void Load_Survey_Statistics(char file[], char option[]){
    /**/
    FILE *fp = fopen(file, option);

    /**/
    if(fp == NULL){
        perror("Error de apertura!\n");
    }

    /**/
    int gender, age, martial_status, employed, student;
    int male = 0, female = 0, workers_sub_18 = 0, single = 0, married = 0, work_and_study = 0, female_workers = 0;

    /**/
    fscanf(fp, "%d-%d-%d-%d-%d", &gender, &age, &martial_status, &employed, &student);
    while(feof(fp) == 0){
        
        if(gender == 1){
            male++;
            
            if(employed == 1){
                if(age < 18){
                    workers_sub_18++;
                }
                
                if(student == 1){
                    work_and_study++;
                }
            }

            if(martial_status == 1){
                single++;
            }

            if(martial_status == 2){
                married++;
            }
        }

        else{
            female++;
            
            if (employed == 1){
                female_workers++;
                
                if (age < 18){
                    workers_sub_18++;
                }
                
                if (student == 1){
                    work_and_study++; 
                }
            }

            if (martial_status == 1){
                single++;
            }

            if (martial_status == 2){
                married++;
            }
        }

        fscanf(fp, "%d-%d-%d-%d-%d", &gender, &age, &martial_status, &employed, &student);
    }

    /**/
    fclose(fp);

    /**/
    printf("\t\tESTADISTICAS DE LA ENCUESTA:\n\n");
    printf("varones: %d\n", male);
    printf("mujeres: %d\n", female);
    printf("menores de 18 anios que trabajan: %d\n", workers_sub_18);
    printf("solteros: %d\n", single);
    printf("casados: %d\n", married);
    printf("encuestados que trabajan y estudian: %d\n", work_and_study);
    printf("mujeres que trabajan: %d\n", female_workers);
}