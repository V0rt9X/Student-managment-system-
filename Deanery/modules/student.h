#ifndef FINALPROJECT_STUDENT_H
#define FINALPROJECT_STUDENT_H

typedef enum { F=1,D,C,B,A } grade;

typedef struct {
    int id;
    char name[50];
    char surname[50];
    grade gradeOfStudent;
    char password[20];
} student;

//The function takes student data and allocates a new struct element on the heap.
student* createStudent(int id, const char* name, const char* surname, grade gradeOfStudent, const char* password);

#endif