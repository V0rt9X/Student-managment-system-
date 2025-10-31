#ifndef FINALPROJECT_UTILS_H
#define FINALPROJECT_UTILS_H

#define OPEN_FILE_ERROR (-2)
#define PARSING_ERROR (-1)
#define COMPLETE (1)
#include "database.h"

//Structure for easy reading switch case command keys.s
typedef enum {
    add,
    printS,
    printL,
    delete,
    save,
    load,
    freeL,
    best,
    sort,
    shutdown,
    errKey
} keys;

//Function with ANSI sequence that clears the terminal.
void clear_screen();

//A function for reading a number and converting it to an int. The function takes a pointer to a variable of type int and safely modifies its contents.
int strtoDec(int* id);

//Function for handling critical parsing errors.
void parsingError(Node** head,int code);

//Function to handle critical errors when adding an element to the end of a linked list.
void addError(Node** head,int code);

//Function for handling critical errors when saving to a file.
void saveError(Node** head,int code);

//Function for handling critical errors when loading from a file.
void loadError(int code);

#endif