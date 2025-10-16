#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "database/database.h"
#include "utils.h"

void clear_screen() {
    printf("\033[H\033[J");
}


//function to safely read a string from stdin
static unsigned read_line(char *buffer, size_t buff_size) {
    unsigned counter = 0;
    int character;

    //Loop for reading characters from stdin
    memset(buffer,0,buff_size);
    for (int i = 0; i < (buff_size - 2); i++) {
        character = fgetc(stdin);

        if (character == '\n') {
            buffer[i] = (char)character;
            break;
        }

        buffer[i] = (char)character;
        counter++;
    }buffer[buff_size - 1] = '\0';

    return counter;
}

int read_user_data(int *id, char* name, char* surname, grade *gradeOfStudent, char *password,
                       contactType *conType,char *correspondence) {

    char buffer[1024];
    char* saver;
    char* token;
    char* delimiter = "\n";
    char* saver_strtol;
    long digit;

    //Reading student ID
    printf("Enter student ID: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check
    // Converting a string to a number and checking its size
    digit = strtol(token, &saver_strtol,10);
    if (digit>INT_MAX) {
        *id = 0;
    }else { *id = (int)digit; }

    clear_screen();

    //Reading a student's name
    printf("Enter student name: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check
    snprintf(name,sizeof(((student*)0)->name),"%s",token);

    clear_screen();

    //Reading a student's surname
    printf("Enter surname: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check
    snprintf(surname,sizeof(((student*)0)->surname),"%s",token);

    clear_screen();

    //Reading a student's grade
    printf("Enter grade of student: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check
    digit = buffer[0] - 'A' + 1; //Converting a letter to a number to check if the grade is entered correctly
    if (digit<1 || digit>5) {
        *gradeOfStudent = WITHOUT_GRADE;
    }else { *gradeOfStudent = (grade)digit; }

    clear_screen();

    //Reading a student's password
    printf("Enter a password: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check
    snprintf(password,sizeof(((student*)0)->password),"%s",token);

    clear_screen();

    //Reading the type of student correspondence
    printf("Enter type of correspondence: ");
    read_line(buffer,sizeof(buffer));
    token = strtok_r(buffer, delimiter, &saver);
    if (!token){return PARSING_ERROR;} //strtok_r parsing check

    //Checking the type and assigning a correspondence address
    if (strcmp(token,"EMAIL") == 0) {
        *conType = EMAIL;

        clear_screen();

        printf("Enter email: ");
        read_line(buffer,sizeof(buffer));
        token = strtok_r(buffer, delimiter, &saver);
        if (!token){return PARSING_ERROR;} //strtok_r parsing check
        snprintf(correspondence,sizeof(((student*)0)->correspondence.eMail),"%s",token);

        //Checking the type and assigning a correspondence address
    }else if (strcmp(token,"PHONE") == 0) {
        *conType = PHONE;

        clear_screen();

        printf("Enter phone number: ");
        read_line(buffer,sizeof(buffer));
        token = strtok_r(buffer, delimiter, &saver);
        if (!token){return PARSING_ERROR;} //strtok_r parsing check
        snprintf(correspondence,sizeof(((student*)0)->correspondence.phone),"%s",token);

    }else {
        *conType = NONE;
    }

    //Return true if everything is successful
    return 1;
}

