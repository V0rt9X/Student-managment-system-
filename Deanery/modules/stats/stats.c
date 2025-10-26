#include "stats.h"
#include <stdio.h>
#include <string.h>


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

//The function merges two already sorted lists (left and right) into one new, completely sorted list.
static Node* merge(Node* left, Node* right) {
    Node dummy;
    Node* current = &dummy;
    dummy.next = NULL;

    while (left && right) {
        if (strcmp(left->data->surname, right->data->surname) <= 0) {
            current->next = left;
            left = left->next;
        }else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    if (left) {
        current->next = left;
    }
    if (right) {
        current->next = right;
    }

    return dummy.next;
}

Node* sort_student_by_surname(Node *head) {
    if (!head || !(head->next)) {
        return head;
    }

    Node* middle = find_middle(head);

    Node* right = middle->next;
    middle->next = NULL;

    Node* sortLeft = sort_student_by_surname(head);
    Node* sortRight = sort_student_by_surname(right);

    return merge(sortLeft, sortRight);
}
