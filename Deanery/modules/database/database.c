#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "../student/student.h"

#define MALLOC_FAILE (-1)

int student_add(student* data, Node** element) {
    Node* new_element = (Node*)malloc(sizeof(Node)); //Creating a target element
    if (new_element == NULL) {
        return MALLOC_FAILE;
    }

    //Assigning data to a target element
    new_element->data = data;
    new_element->next = NULL;

    //Сhecking the past element and attaching the target element
    if (*element == NULL) {
        *element = new_element;
        return 1;
    }

    //Passing to the last element through a temporary pointer
    Node *current = *element;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_element;

    //Return true
    return 1;
}

void print_list(Node *element) {
    if (element == NULL) {
        printf("Empty element.\n");
        return;
    }
    //Temporary pointer for traversing a linked list
    Node* current = element;
    //Loop to traversing a linked list
    while (current != NULL) {
        if (current->data == NULL) {
            printf("Empty element.");
            current = current->next;
            continue;
        }
        //Passing a block of data to the data output function
        printStudent(current->data);
        printf("\n");
        current = current->next;
    }

}

Node* find_student_by_id(Node* head, int id) {
    //Temporary pointer for traversing a linked list
    Node* current = head;

    //Loop to find the target element
    while (current != NULL) {
        if (current->data->id == id) {
            return current;
        }
        current = current->next;
    }

    printf("Student with %d ID not found.\n", id);
    return NULL;
}

int free_list(Node** head) {
    int counter=0;
    Node* current = *head;
    Node* next;

    //Loop for traversing a linked list and free it via a temporary pointer
    while (current!=NULL) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
        counter++;
    }

    *head = NULL;

    return counter;
}

int delete_student_by_id(Node** head, int id) {
    if ((*head) == NULL) {
        printf("Empty list.\n");
        return 0;
    }

    //Loop to find the element to be removed
    Node* current = *head;
    Node* prev;
    while (current != NULL) {
        if (current->data->id == id) {
            break;
        }
        prev = current;
        current = current->next;
    }

    //Check for element detection
    if (current == NULL) {
        printf("Student with %d ID not found.\n", id);
        return 0;
    }

    //Checking if an element is the first
    if (current == *head) {
        *head = current->next;
        free(current->data);
        free(current);
        return 1;
    }

    //Joining a linked list and deleting the found element
    prev->next = current->next;
    free(current->data);
    free(current);
    return 1;
}

