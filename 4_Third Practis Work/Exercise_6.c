#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCHOOL 10
#define GRADE 100
#define STUDENTS_NOTE 100

int Get_Number();
void Show_Array(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students);
void Load_array(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students);
void General_Average(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students);
float Student_Average();
void Top_Student_In_Each_Grade(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students);

int main(){
    /*I create a seed to enable the use of random numbers*/
    srand(time(NULL));

    /*I declare the variables*/
    float Tensor[SCHOOL][GRADE][STUDENTS_NOTE];
    int schools, grades, students;

    /*I ask the user to enter the quantity of schools, grades, and students that will be on the list*/
    printf("How many schools will be on the list?: ");
    schools = Get_Number();

    printf("How many grades are there in each school?: ");
    grades = Get_Number();

    printf("How many students are there in each grade?: ");
    students = Get_Number();

    /*I load and display the list on the screen */
    Load_array(Tensor, schools, grades, students);
    Show_Array(Tensor, schools, grades, students);

    /*I calculate all the requested averages*/
    printf("The averages will be loaded next!...\n");
    General_Average(Tensor, schools, grades, students);

    /*I display on the screen the top averages of each grade from the schools*/
    Top_Student_In_Each_Grade(Tensor, schools, grades, students);

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

float Student_Average(){
    /*I declare the variables*/
    float note = 0.0, accumulator = 0.0, average = 0.0;
    int i;
    
    /*I sum the three grades of each student*/
    for(i = 0; i < 3; i++){
        note = ((float)rand() / RAND_MAX) * 10.0;

        accumulator += note;
    }

    /*I calculate the average of their grades*/
    average = accumulator / 3;

    return average;
}

void Show_Array(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students){
    /*I declare the variables*/
    int s, g, p;
    
    /*I display the list of schools with their respective grades and the averages of the students*/
    for (s = 0; s < schools; s++){
        printf("SCHOOL N %d: \n", s + 1);
        
        for (g = 0; g < grades; g++){
            printf("Grade number %d: ", g + 1);
            
            for (p = 0; p < students; p++){
                printf("%2.2f   ", Tensor[s][g][p]);
            }
            printf("\n");
        }
        printf("\n");
        system("Pause");
        
    }
    printf("\n");
    system("cls");
}

void Load_array(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students){
    /*I declare the variables*/
    int s, g, p;

    /*I load the list with the averages of the students received from the 'Student Average' function*/
    for(s = 0; s < schools; s++){

        for(g = 0; g < grades; g++){

            for(p = 0; p < students; p++){
                Tensor[s][g][p] = Student_Average();
            }
        }
    }

}

void General_Average(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students){
    /*I declare the variables*/
    int s, g, p;
    float accumulator, grade_average, school_average, total_average = 0.0;

    /*I calculate and display the averages of the grades, the schools, and overall for all the schools*/
    for(s = 0; s < schools; s++){
        printf("SCHOOL NUMBER %d! \n", s + 1);
        school_average = 0.0;

        for(g = 0; g < grades; g++){
            /*I reset the variables and sum the averages of the grade*/
            accumulator = 0.0;
            grade_average = 0.0;

            for(p = 0; p < students; p++){
                accumulator += Tensor[s][g][p];

            }
            /*I obtain the average of the grade and display it*/
            grade_average += accumulator / students;
            printf("The average of grade n %d is: %2.f!\n", g + 1, grade_average);

            /*I add the grade average to the school average*/
            school_average += grade_average;
        }
        /*I calculate the total average of the school and display it on the screen*/
        school_average = school_average / grades; 
        printf("The average of the entire school number %d is: %2.f!\n", s + 1, school_average);
        system("Pause");

        /*I add the school average to the overall average of the schools*/
        total_average += school_average;
    }
    
    /*I calculate and display the overall average of the schools*/
    total_average = total_average / schools;
    printf("The total average of all the schools is: %2.f!\n", total_average);
}

void Top_Student_In_Each_Grade(float Tensor[SCHOOL][GRADE][STUDENTS_NOTE], int schools, int grades, int students){
    /*I declare the variables*/
    int s, g, p, counter;
    float highest_average;

    /*Through this nested loop, I search for the largest averages of each grade*/
    for(s = 0; s < schools; s++){
        printf("SCHOOL NUMBER %d! \n", s + 1);

        for(g = 0; g < grades; g++){
            /*I reset the variables*/
            counter = 0;
            highest_average = 0.0;
            
            for(p = 0; p < students; p++){
                /*If the average is greater than that of the variable, student p will be the new content of the variables*/
                if(Tensor[s][g][p] > highest_average){
                    highest_average = Tensor[s][g][p];
                    counter = p;
                }

            }
            /*I display the highest grade average, along with its respective grade*/
            printf("The student %d has the highest average in grade %d. Their average is: %2.f!\n", counter + 1, g + 1, highest_average);
        
        }
        
        system("Pause");
        system("cls");
    }
}