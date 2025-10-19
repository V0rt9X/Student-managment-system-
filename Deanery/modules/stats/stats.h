#ifndef FINALPROJECT_STATS_H
#define FINALPROJECT_STATS_H

#include "database.h"

//The function takes a pointer to the head of the list, analyzes the database and displays the data of students with the best grades.
void find_student_with_best_grade(Node* head);

void sort_student_by_surname(Node **head);

#endif