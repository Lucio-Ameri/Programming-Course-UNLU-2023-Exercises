#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
float Student_Average(float test_1, float test_2);
int Student_Condition(float test_1, float test_2, float average);
void Testing();

int main(){
    /*I create a seed to be able to use random numbers*/
    srand(time(NULL));
    
    /*I declare the variables*/
    float note_1, note_2, average;
    int container;
    
    /*I call the testing function*/
    Testing();

    /*I randomly generate the student's grades between 1.0 and 10.0 and display them on the screen*/
    note_1 = ((float)rand() / RAND_MAX) * 9.0 + 1.0;
    printf("First Exam: %.2f\n", note_1);
    note_2 = ((float)rand() / RAND_MAX) * 9.0 + 1.0;
    printf("Second Exam: %.2f\n", note_2);

    /*I call the functions*/
    average = Student_Average(note_1, note_2);
    container = Student_Condition(note_1, note_2, average);

    return 0;
}

/*I declare the function*/
float Student_Average(float test_1, float test_2){
    /*I declare the variables*/
    float average;

    /*I calculate the average*/
    average = (test_1 + test_2) / 2.0;
    return average;
}

int Student_Condition(float test_1, float test_2, float average){
    int flag;

    /*According to the grade the student has, they will meet one of the conditions and the program will display their status on the screen*/
    if((test_1 < 4.0) && (test_2 < 4.0)){
        printf("The student's average is %.2f. They failed both partial exams and are in the 'free' status.\n", average);
        flag = 1;
    }
    else if((test_1 >= 4.0) && (test_2 >= 4.0)){
        if((test_1 >= 7.0) && (test_1 >= 7.0)){
            printf("The student has an average of %.2f and passed both partial exams with a grade higher than '7.0'. Their status is: 'promoted'.\n", average);
            flag = 2;
        }
        else{
            printf("The student has an average of %.2f and passed both partial exams. Their status is: 'regular' (Must take the final exam).\n", average);
            flag = 3;
        }
    }
    else{
        printf("The student has failed one of the two partial exams. They must take a makeup exam, and if they pass it, they will be eligible to take a final exam.\n");
        flag = 4;
    }
    return flag;
}

void Testing(){
    
    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I am testing the functions*/
    assert(Student_Average(10.0, 10.0) == 10.0);
    assert(Student_Average(4.0, 4.0) == 4.0);
    assert(Student_Average(5.3, 5.7) == 5.5);

    assert(Student_Condition(1.0, 3.0, 2.0) == 1);
    assert(Student_Condition(10.0, 10.0, 10.0) == 2);
    assert(Student_Condition(4.0, 4.0, 4.0) == 3);
    assert(Student_Condition(5.0, 3.0, 4.0) == 4);
    system("cls");

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}