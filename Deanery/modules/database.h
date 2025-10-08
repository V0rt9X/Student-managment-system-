#ifndef FINALPROJECT_DATABASE_H
#define FINALPROJECT_DATABASE_H
#include <stdio.h>

// Structure for storing student data in a chain of structures.
typedef struct Node {
    struct s *data;
    struct Node *next;
}Node;

//Function adds an element to the end of a linked list.
int student_add(Node* head);

//Function prints the student data from the chain element.
void student_print(Node* head);

//Function finds a student by id in a linked list.
Node* find_student_by_id(Node* head, unsigned id);

//Function removes student by id from linked list.
int delete_student_by_id(Node* head, unsigned id);

//Function saves a linked list to a file.
int save_to_file(Node* head);

//Function unloads student data from a file into a linked list.
int load_from_file(Node* head, FILE* fname);

//Function frees memory from the linked list.
void free_list(Node** head);

#endif
