#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define STUDENTS 100
#define SIZE_NAME_SURNAME 50
#define CONDITION 50

typedef struct{
    int note1;
    int note2;
    int note3;
} qualifications;

typedef struct{
    char Name[SIZE_NAME_SURNAME];
    char Surname[SIZE_NAME_SURNAME];
    char Status[CONDITION];
    int Registration;
    qualifications notes;
    float Average;
}record;

int Get_Number();
void Get_Word(char *word);
void Show_Array(record student_information[], int students);
void Load_Array(record *student_information, int students);
void Student_Status(char *condition, float average);
float Student_Average(int note1, int note2, int note3);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    record Student_Information[STUDENTS];
    int students;

    /*I ask the user to input the number of students they have, store it in the variable 'students', 
    and then clear the buffer*/
    printf("Please enter how many students you have: ");
    students = Get_Number();
    while (getchar() != '\n');

    /*I load and display the information and situation of each student*/
    Load_Array(Student_Information, students);
    Show_Array(Student_Information, students);

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
    
}

float Student_Average(int note1, int note2, int note3){
    /*I sum the 3 grades of the student and return the average*/
    return (note1 + note2 + note3) / 3.0;
}

void Student_Status(char *condition, float average){
    /*I load the situation of the student, depending on their average grade, they will be classified as free, 
    regular, or promoted.*/
    if(average < 4){
        strcpy(condition, "FAIL");
    }

    else if(average >= 4 && average <= 7){
        strcpy(condition, "REGULAR");
    }
    else{
        strcpy(condition, "PROMOTED");
    }

    if(condition[strlen(condition) - 1] == '\n'){
            condition[strlen(condition) - 1] = '\0';
        }
}

void Show_Array(record student_information[], int students){
    /*I declare the variables*/
    int i;

    /*I print the information of student[i] to the screen*/
    printf("%-10s | %-15s | %-15s | %-10s | %-10s\n", "NAME", "SURNAME", "REGISTRATION", "AVERAGE", "STATUS");
    for(i = 0; i < students; i++){
        printf("%-10s | %-15s | %-15d | %-10.2f | %-10s\n", student_information[i].Name, student_information[i].Surname, student_information[i].Registration, student_information[i].Average, student_information[i].Status);
    }
    system("Pause");
    system("cls");
}

void Load_Array(record *student_information, int students){
    /*I declare the variables*/
    int i, ID = 1; 
    char word[SIZE_NAME_SURNAME];

    /*In each iteration, I ask for the information of the corresponding student*/
    for(i = 0; i < students; i++){
        /*I ask the user for the name and load it into the respective position*/
        printf("Please enter the name of student %d: ", ID);
        Get_Word(word);
        strcpy(student_information[i].Name, word);

        /*I ask the user for the last name and load it into the respective position*/
        printf("Please enter the last name of student %d: ", ID);
        Get_Word(word);
        strcpy(student_information[i].Surname, word);

        /*I load the ID of the corresponding student*/
        student_information[i].Registration = ID;

        /*I randomly generate the grades for the student to avoid having to ask for them*/
        student_information[i].notes.note1 = (rand() % 10) + 1;
        student_information[i].notes.note2 = (rand() % 10) + 1;
        student_information[i].notes.note3 = (rand() % 10) + 1;

        /*I calculate and load the average grade of the student*/
        student_information[i].Average = Student_Average(student_information[i].notes.note1, student_information[i].notes.note2, student_information[i].notes.note3);
    
        /*I assign the student's status as free, regular, or promoted*/
        Student_Status(student_information[i].Status, student_information[i].Average);

        ID += 100;
        system("cls");
    }
}