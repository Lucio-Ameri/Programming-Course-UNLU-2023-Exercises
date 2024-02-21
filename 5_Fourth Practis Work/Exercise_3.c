#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define SIZE_OF_STUDENTS 1000
#define SIZE_NAME_SURNAME 50
#define CLASSES 10
#define NOTES 10

typedef struct{
    int day;
    int month;
    int year;
}birthday;

typedef struct{
    char name[SIZE_NAME_SURNAME];
    char surname[SIZE_NAME_SURNAME];
    birthday date_of_birthday;
    float note[NOTES];
}student_data;

typedef struct{
    char teacher[SIZE_NAME_SURNAME];
    student_data students[SIZE_OF_STUDENTS];
}class;

int Get_Number();
void Get_Word(char *word);
float Get_Note();
void Show_Register(class classroom, int index, int quantity_of_students, int quantity_of_notes);
void Load_Register(class *classroom, int quantity_of_classes);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    class classroom[CLASSES];
    int quantity_of_classes;
    
    /*I ask the user to enter the number of classrooms the elementary school has*/
    printf("How many classrooms does the elementary school have? (There can't be more than 10): ");
    quantity_of_classes = Get_Number();

    /*I validate that the number of classrooms entered meets the parameters set by me*/
    while(quantity_of_classes >= 10 || quantity_of_classes <= 0){
        printf("Invalid input! You must enter less than 10 classrooms and more than 0 classrooms: ");
        quantity_of_classes = Get_Number();
    }

    /*I load the record of each class with all the data*/
    Load_Register(classroom, quantity_of_classes);

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
    printf("\n");
    system("cls");

    return Number;
}

void Get_Word(char *word){
    /*I declare the variables*/
    int i, aux = 1;
    
    /*I ask the user for the name or the last name of the person they are going to enter into the list*/
    while(aux == 1){
        aux = 0;
        fgets(word, SIZE_NAME_SURNAME, stdin);
        fflush(stdin);
        
        /*I replace the newline character with the empty character*/
        if(word[strlen(word) - 1] == '\n'){
            word[strlen(word) - 1] = '\0';
        }

        /*I check that what the user entered consists only of letters*/
        for(i = 0; word[i] != '\0'; i++){
            if(!isalpha(word[i])){
                printf("\nInvalid Name/Surname! Please enter a name/surname without numbers or special characters!: ");
                aux = 1;
                break;
            }
            
            
        }
    }

    /*Convert the entered word to uppercase*/
    i = 0;
    while (word[i] != '\0') {
        word[i] = toupper(word[i]);
        i++;
    }

    printf("\n");
    system("cls");
    
}

float Get_Note(){
    /*genero aleatoriamente un numero flotante entre 1 y 10*/
    return (((float)rand() / RAND_MAX) * 9) + 1;
}

void Show_Register(class classroom, int index, int quantity_of_students, int quantity_of_notes) {
    /*I declare the variables*/
    int j = index;

    /*I print the teacher's name and the header*/
    printf("THE TEACHER IN CHARGE OF THIS CLASS IS: %s\n", classroom.teacher);

    printf("%-15s | %-15s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", "NAME", "SURNAME", "BIRTHDAY", "NOTE 1", "NOTE 2", "NOTE3", "NOTE 4", "NOTE 5", "NOTE 6", "NOTE 7", "NOTE 8", "NOTE 9", "NOTE 10");
    
    /*I print all the information of each student with each iteration*/
    if (j >= 0 && j < quantity_of_students) {
        printf("%-15s | %-15s | %-02d-%02d-%04d | ", classroom.students[j].name, classroom.students[j].surname, classroom.students[j].date_of_birthday.day, classroom.students[j].date_of_birthday.month, classroom.students[j].date_of_birthday.year);

        for (int k = 0; k < quantity_of_notes; k++) {
            printf("%-10.2f | ", classroom.students[j].note[k]);
        }
        printf("\n");
    } 
    
    else {
        printf("Index out of range\n");
    }
    
    printf("\n");
    system("Pause");
}

void Load_Register(class *classroom, int quantity_of_classes){
    /*I declare the variables*/
    int i, j, k, quantity_of_notes = 0, quantity_of_students = 0, day, month, year;
    char name[SIZE_NAME_SURNAME], surname[SIZE_NAME_SURNAME];

    /*With each iteration, I load all the information of the classroom at index [i]*/
    for(i = 0; i < quantity_of_classes; i++){
        /*I ask the user to provide the number of students in the classroom [i]*/
        printf("How many students are in class %d?: ", i + 1);
        quantity_of_students = Get_Number();
        while (getchar() != '\n');

        /*I ask the user to provide the name of the teacher for classroom [i]*/
        printf("Who is the teacher of class %d?: ", i + 1);
        Get_Word(name);
        strcpy(classroom[i].teacher, name);

        /*I ask the user to enter the number of exams the students had during the year, ensuring that 
        it's not more than 10 exams*/
        printf("How many grades did the students in class %d have during the year? (There can't be more than 10): ", i + 1);
        quantity_of_notes = Get_Number();
        while(quantity_of_notes > 10){
            printf("Invalid number of grades! Please enter less than 11 grades: ");
            quantity_of_notes = Get_Number();
        }
        while (getchar() != '\n');
    
        /*I load all the information of student[j] from classroom[i]*/
        for(j = 0; j < quantity_of_students; j++){
            /*I ask the user to provide the name of student[j] in classroom[i]*/
            printf("Enter the name of the student %d: ", j + 1);
            Get_Word(name);
            strcpy(classroom[i].students[j].name, name);


            /*I ask the user to provide the last name of student[j] in classroom[i]*/
            printf("Enter the last name of student %d: ", j + 1);
            Get_Word(surname);
            strcpy(classroom[i].students[j].surname, surname);


            /*I ask the user to provide the date of birth of student[j] in classroom[i], ensuring that the 
            entered date is valid*/
            printf("Enter the date of birth of student %d!\n", j + 1);
            printf("day: "); day = Get_Number();
            while(day <= 0 || day >= 32){
                printf("Invalid day! Please enter a valid day!: "); day = Get_Number();
            }
            classroom[i].students[j].date_of_birthday.day = day;

            printf("Enter the student %d's date of birth!\n", j + 1);
            printf("month: "); month = Get_Number();
            while(month <= 0 || month >= 13){
                printf("Invalid month! Please enter a valid month!: "); month = Get_Number();
            }
            classroom[i].students[j].date_of_birthday.month = month;

            printf("Enter the date of birth of student %d!\n", j + 1);
            printf("year: "); year = Get_Number();
            while(year <= 1970 || year >= 2016){
                printf("Invalid year! Please enter a valid year!: "); year = Get_Number();
            }
            classroom[i].students[j].date_of_birthday.year = year;
            

            /*I load the grades of student[j] from classroom[i]*/
            for(k = 0; k < quantity_of_notes; k++){
                classroom[i].students[j].note[k] = Get_Note();
            }

            while (getchar() != '\n');
        }
        /*Display the information provided on the screen for student[j] from classroom[i]*/
        Show_Register(classroom[i], i, quantity_of_students, quantity_of_notes);
    
    }
}
