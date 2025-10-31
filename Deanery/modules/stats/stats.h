#ifndef FINALPROJECT_STATS_H
#define FINALPROJECT_STATS_H

#include "database.h"

//The function takes a pointer to the head of the list, analyzes the database and displays the data of students with the best grades.
int find_student_with_best_grade(Node* head);

// The function takes a pointer to a linked list from the heap and sorts it by surname. The function returns a pointer to the sorted list.
Node* sort_student_by_surname(Node *head);

#endif