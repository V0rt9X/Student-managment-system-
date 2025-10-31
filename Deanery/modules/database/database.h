#ifndef FINALPROJECT_DATABASE_H
#define FINALPROJECT_DATABASE_H
#include "../student/student.h"

#define MALLOC_FAILE (-1) // for student_add
#define EMPTY_DATA_ERROR (-2)// for student_add

#define EMPTY_LIST_ERROR (-1) // for save_to_file

#define LIST_ERROR (-1) // for load_from_file
#define ERROR_DATABASE_DATA (-2) // for load_from_file
#define ADD_ERROR (-3) // for load_from_file

// Structure for storing student data in a chain of structures.
typedef struct Node {
    student *data;
    struct Node *next;
}Node;

//Function adds an element to the end of a linked list, and returns true if everything is successful, -1 if an error occurred while allocating memory.
int student_add(student* data, Node** element);

//Function prints the student data from the linked list.
void print_list(Node* head);

//Function finds a student by id in a linked list.
student* find_student_by_id(Node* head, int id);

//Function removes student by id from linked list.
int delete_student_by_id(Node** head, int id);

//Function saves a linked list to a file.
int save_to_file(Node* head);

//Function unloads student data from a file into a linked list.
int load_from_file(Node** head);

//Function frees memory from the linked list.
int free_list(Node** head);

#endif
