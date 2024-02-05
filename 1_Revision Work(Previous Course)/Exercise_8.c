#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
int Student_Average(int test_1, int test_2);
void Testing();

int main(){
    /*I create a seed to be able to use random numbers*/
    srand(time(NULL));

    /*I call the testing function*/
    Testing();
    
    /*I declare the variables*/
    int i, average, Course_average = 0, enrolled_students, Exam_1, Exam_2;

    /*I ask the teacher for the number of students in the course*/
    printf("How many students are in the course?: "); scanf("%d", &enrolled_students); printf("\n");

    for(i = 0; i < enrolled_students; i++){
        /*I input the notes for student i*/
        Exam_1 = ((rand() % 9) + 1);
        Exam_2 = ((rand() % 9) + 1);

        /*call the function to calculate the average for student i*/
        average = Student_Average(Exam_1, Exam_2);

        /*display the average for student i*/
        printf("The student's average %d, is: %d\n", i + 1, average);

        /*sum up the averages for all students*/
        Course_average += average;
    }
    system("Pause");
    system("cls"); 

    /*calculate the overall course average and display it and show it*/
    Course_average = Course_average / enrolled_students;
    printf("The course average is: %d\n", Course_average);

    return 0;
}

/*I declare the function*/
int Student_Average(int test_1, int test_2){
    /*I declare the variables*/
    int average;

    /*I calculate the average*/
    average = (test_1 + test_2) / 2;
    return average;
}

void Testing(){
    
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I am testing the functions*/
    assert(Student_Average(10, 10) == 10);
    assert(Student_Average(4, 4) == 4);
    assert(Student_Average(5, 5) == 5);

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}