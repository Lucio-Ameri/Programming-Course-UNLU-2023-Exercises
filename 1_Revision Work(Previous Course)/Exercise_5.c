#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <unistd.h>

/*Functions Prototypes*/
int Entered_Text(char text[]);
void Testing();

int main(){
    /*I declare the variables*/
    int letter_count = 0, size = 1000;
    char text[size];

    /*I call the testing function*/
    Testing();

    /*I input the text via the keyboard, storing it in 'text[]'*/
    printf("Enter the text you want (up to 1000 letters maximum): "); fgets(text, sizeof(text), stdin); 

    /*Replace the last character if the condition holds*/
    if (text[strlen(text)-1] == '\n'){
        text[strlen(text)-1] = '\0';
    }
    
    /*Clean the buffer*/
    fflush(stdin);

    /*Line break*/
    printf("\n");

    /*I call the function and display the result on the screen*/
    letter_count = Entered_Text(text);
    printf("\nThe entered text has %d number of letters\n", letter_count);

    return 0;
}

/*I declare the function*/
int Entered_Text(char text[]){
    /*I declare the variables*/
    int i = 0, letters = 0;

    /*Loop that terminates when the condition is met*/
    while(text[i] != '\0'){
        
        /*Prints letter by letter to form a word*/
        if(isalpha(text[i])){
            letters += 1;
            printf("%c", text[i]);
        }
        /*If a space is found in the text, insert a line break*/
        else{
            if((text[i] == ' ' )){
                printf("\n");
            }
        }
        
        i += 1;
    }
    
    return letters;
}

void Testing(){

    printf("Verifying the proper operation of the program!\n");
    sleep(3);

    /*I am testing the function 'Entered Text'*/
    assert(Entered_Text("Hello World!") == 10); 
    printf("\n");
    assert(Entered_Text("He3ll5o Wo1r1l224d!") == 10);
    printf("\n");
    assert(Entered_Text("Hello World! 1234") == 10);
    printf("\n");
    
    system("cls");

    printf("The program is working correctly!\n");
    system("pause");
}