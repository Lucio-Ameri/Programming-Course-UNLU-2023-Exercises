#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

/*Function Prototypes*/
int Firsts_Letters(char word_1[], char word_2[], char word_3[]);
void Valid_String(char word[], int size);
void Testing();

int main(){
    /*I declare the variables*/
    int size = 24, result;
    char chain_1[size], chain_2[size], chain_3[size];

    /*I call the testing function*/
    Testing();

    /*To input the string, I call 'Valid_String'*/
    printf("FIRST STRING \n");
    Valid_String(chain_1, size);

    /*Clean the buffer*/
    fflush(stdin);


    printf("SECOND STRING \n");
    Valid_String(chain_2, size);
    fflush(stdin);

    
    printf("THIRD STRING \n");
    Valid_String(chain_3, size);
    fflush(stdin);
    printf("\n");

    /*I call the function*/
    result = Firsts_Letters(chain_1, chain_2, chain_3);
    system("pause");
    system("cls");
    
    /*display the result on the screen with a switch, where 'result' defines the case to be printed*/
    switch(result){
        
        case 0:
            printf("The first two entered strings are equal!\n");
            break;
        
        case 2:
            printf("The last two entered strings are equal!\n");
            break;

        case 3:
            printf("All entered strings are equal!\n");
            break;

        case 4:
            printf("All entered strings are unique!\n");
            break;
    }

    return 0;
}

/*I declare the function*/
int Firsts_Letters(char word_1[], char word_2[], char word_3[]){
    /*I declare the variables*/
    int flag;
    char letters[4]; 

    /*I concatenate the first letter of each string and add the null character*/
    letters[0] = word_1[0];
    letters[1] = word_2[0];
    letters[2] = word_3[0];
    letters[3] = '\0';

    /*I show the result of the concatenate*/
    printf("The result of concatenating the first letter of the strings is: %s\n", letters);

    /*Compare the strings to determine if they are equal or different*/
    if ((strcmp(word_1, word_2) == 0) && (strcmp(word_2, word_3) == 0)) {
        flag = 3; 
    } 
    
    else if ((strcmp(word_1, word_2) == 0) && (strcmp(word_2, word_3) != 0)) {
        flag = 0;
    }
    
    else if ((strcmp(word_1, word_2) != 0) && (strcmp(word_2, word_3) == 0)) {
        flag = 2;
    }
    
    else if ((strcmp(word_1, word_2) != 0) && (strcmp(word_2, word_3) != 0) && (strcmp(word_1, word_3) != 0)) {
        flag = 4;
    }
    
    else{
        flag = -1;
    }

    return flag;
}

void Valid_String(char word[], int size) {
    /*I declare a variable*/
    int flag;

    /*Run the loop even once, if something is wrong, run it until the error is corrected*/
    do {
        flag = 0;

        /* Enter a string */
        printf("Enter the string (maximum %d characters): ", size - 1);
        fgets(word, size, stdin);
        fflush(stdin);
        /* Replace the newline character with the null character */
        if (word[strlen(word) - 1] == '\n') {
            word[strlen(word) - 1] = '\0';
        }

        /*If the string size is 0, flag = 1*/
        if (strlen(word) == 0) {
            printf("\nYou cannot have an empty string, please enter a new string!\n");
            flag = 1;
            continue;
        }

        /*If the string contains anything other than letters, flag = 1*/
        for (int i = 0; i < strlen(word); i++) {
            if (!isalpha(word[i])) {
                flag = 1;
                printf("\nThe string must contain only letters, please enter a new string!\n");
                break;
            }
        }

    } while (flag == 1);
}

void Testing(){

    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I am testing the function 'Firsts Letters'*/
    assert(Firsts_Letters("aaaa", "bbbb", "cccc") == 4);
    assert(Firsts_Letters("aaaa", "aaaa", "cccc") == 0);
    assert(Firsts_Letters("aaaa", "cccc", "cccc") == 2);
    assert(Firsts_Letters("aaaa", "aaaa", "aaaa") == 3);
    assert(Firsts_Letters("aaaa", "bbbb", "aaaa") == -1);
    system("cls");

    printf("The program is working correctly!\n");
    system("Pause");
    system("cls");
}