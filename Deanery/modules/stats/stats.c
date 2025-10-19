#include "stats.h"
#include <stdio.h>


void find_student_with_best_grade(Node* head) {
    //Checking head pointer for NULL
    if (!head) {
        printf("Empty list\n");
        return;
    }

    //Loop to find the best grade in a linked list
    Node* current = head;
    int best=0;
    while (current) {
        if (current->data->gradeOfStudent > best) {
            best = current->data->gradeOfStudent;
        }
        current = current->next;
    }

    // Loop to display students with the best grades
    current = head;
    while (current) {
        if (current->data->gradeOfStudent == best) {
            printStudent(current->data);
        }
        current= current->next;
    }

}


