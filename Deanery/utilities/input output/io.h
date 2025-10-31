#ifndef FINALPROJECT_IO_H
#define FINALPROJECT_IO_H

#include "student.h"

//A function for safely reading a string from stdin. The function takes a pointer to a buffer and its size and safely truncates the string in case of overflow.
unsigned read_line(char *buffer, size_t buff_size);

//The function takes pointers and buffers and safely fills them with data.
int read_user_data(int *id, char* name, char* surname, grade *gradeOfStudent, char *password,
                       contactType *conType,char *correspondence);

#endif