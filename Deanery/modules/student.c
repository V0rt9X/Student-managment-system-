#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                       contactType conType,const char* correspondence) {

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

