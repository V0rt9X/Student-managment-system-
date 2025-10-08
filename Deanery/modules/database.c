#include <stdio.h>
#include <stdlib.h>
#include "database.h"
#include "student.h"

#define MALLOC_FAILE -1

int student_add(student* data, Node* element) {
    Node* new_element = (Node*)malloc(sizeof(Node)); //Creating a target element
    if (new_element == NULL) {
        return MALLOC_FAILE;
    }

    //Assigning data to a target element
    new_element->data = data;
    new_element->next = NULL;

    //Сhecking the past element and attaching the target element
    if (element == NULL) {
        element = new_element;
    }else {
        element->next = new_element;
    }

    //Return true
    return 1;
}