#ifndef FINALPROJECT_STUDENT_H
#define FINALPROJECT_STUDENT_H

typedef enum { F=1,D,C,B,A } grade;

typedef enum { NONE=0, PHONE ,EMAIL } contactType;

typedef union {
    char eMail[50];
    char phone[20];
} contactInfo;

typedef struct {
    int id;
    char name[50];
    char surname[50];
    grade gradeOfStudent;
    char password[20];
    contactType contactOfStudent;
    contactInfo correspondence;
} student;

//The function takes student data and allocates a new struct element on the heap. Function is encrypting user password with Caesar cipher.
student* createStudent(int id, const char* name, const char* surname, grade gradeOfStudent, const char* password,
                       contactType conType,const char* correspondence);

// Function of printing student data.
void printStudent(student* s);

#endif

