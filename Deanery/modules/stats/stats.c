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

//Static function for finding middle element in a linked array
static Node* find_middle(Node* head) {
    if (!head) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

static Node* merge() {

}

void sort_student_by_surname(Node **head) {

}