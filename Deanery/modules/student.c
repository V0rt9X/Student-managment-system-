#include "student.h"
#include <stdio.h>
#include <stdlib.h>

student* createStudent(int id, const char* name, const char* surname, grade gradeOfStudent, const char* password) {
    student *s = (student*)malloc(sizeof(student));
    if (!s) {
        printf("Error allocating memory for student\n");
        return NULL;
    }

    s->id = id;
    snprintf(s->name, 50, "%s", name);
    snprintf(s->surname, 50, "%s", surname);
    s->gradeOfStudent = gradeOfStudent;
    snprintf(s->password, 20, "%s", password);

    return s;
}
