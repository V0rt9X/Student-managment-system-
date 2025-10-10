#ifndef FINALPROJECT_DATABASE_H
#define FINALPROJECT_DATABASE_H
#include <stdio.h>
#include "../student/student.h"

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
Node* find_student_by_id(Node* head, int id);

//Function removes student by id from linked list.
int delete_student_by_id(Node** head, int id);

//Function saves a linked list to a file.
int save_to_file(Node* head);

//Function unloads student data from a file into a linked list.
int load_from_file(Node* head, FILE* fname);

//Function frees memory from the linked list.
int free_list(Node** head);

#endif
