#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database/database.h"

// Function of Ceasar cipher.
static void ceasarEnc(char buffer[],size_t size,const char* str) {
    const unsigned key=5;
    snprintf(buffer, size, "%s", str);
    size_t buffLen = strlen(buffer);

    for (int i = 0; i < buffLen; i++) {
        if (buffer[i] > 31 && buffer[i] < 127) {
            buffer[i] = (char)(((buffer[i] - 32 + key) % 95) + 32);
        }
    }
}

student* createStudent(int id, const char* name, const char* surname, grade gradeOfStudent, const char* password,
    contactType conType, const char* correspondence) {

    // Allocating memory for structure "student"
    student *s = (student*)malloc(sizeof(student));
    if (!s) {
        printf("Error allocating memory for student\n");
        return NULL;
    }

    // Ceasar cipher for encryption user password
    size_t bufferSize = sizeof(s->password);
    char buffer[bufferSize];
    ceasarEnc(buffer,bufferSize,password);


    // Assigning data to a new structure
    s->id = id;
    snprintf(s->name, sizeof(s->name), "%s", name);
    snprintf(s->surname, sizeof(s->surname), "%s", surname);
    s->gradeOfStudent = gradeOfStudent;
    snprintf(s->password, sizeof(s->password), "%s", buffer);
    if (conType == EMAIL) {
        s->contactOfStudent = EMAIL;
        snprintf(s->correspondence.eMail,sizeof(s->correspondence.eMail),"%s",correspondence);
    }else if (conType == PHONE) {
        s->contactOfStudent = PHONE;
        snprintf(s->correspondence.phone,sizeof(s->correspondence.phone),"%s",correspondence);
    }else {
        s->contactOfStudent = NONE;
        snprintf(s->correspondence.eMail, sizeof(s->correspondence.eMail), "Address of correspondence wasn't added.");
    }

    return s;
}

// Function off converting decimal digit to binary digit.
static void decBin(char *buffer,size_t size,int dig) {
    memset(buffer,48,size); buffer[size-1]='\0'; // Setting buffer by char 0
    for (int i = (int)size-2; i >= 1; i--) {
        if (dig == 0) {break;}
        buffer[i] = (char)((dig % 2) + 48);
        dig /= 2;
    }
}

void printStudent(student* data) {
    if (data==NULL) {
        printf("Empty struct.\n");
        return;
    }

    printf("Name Surname: %s\t", data->name);
    printf("%s. ", data->surname);
    printf("Grade: %c. ", data->gradeOfStudent + 65 - 1);

    if (data->contactOfStudent == EMAIL) {
        printf("Correspondence: %s. ", data->correspondence.eMail);
    } else if (data->contactOfStudent == PHONE) {
        printf("Correspondence: %s. ", data->correspondence.phone);
    } else {
        printf("Address of correspondence wasn't added.\n");
    }

    printf("Student ID: %d. ", data->id);
    printf("Student ID in octal system: %o. ", data->id);
    printf("Student ID in hexadecimal system: %x.\n", data->id);


    char buffer[33]; // buffer for 32 bit binary ID
    decBin(buffer,33,data->id);
    printf("Student ID in binary system: %s\n", buffer);
    printf("\n");
}
