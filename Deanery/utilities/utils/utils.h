#ifndef FINALPROJECT_UTILS_H
#define FINALPROJECT_UTILS_H

#define OPEN_FILE_ERROR (-1)
#define PARSING_ERROR (-2)

//Function with ANSI sequence that clears the terminal
void clear_screen();

//The function takes pointers and buffers and safely fills them with data.
int read_user_data(int *id, char* name, char* surname, grade *gradeOfStudent, char *password,
                       contactType *conType,char *correspondence);

#endif