#include <stdio.h>
#include <string.h>
#include "modules/student/student.h"
#include "modules/database/database.h"
#include "modules/stats/stats.h"
#include "utilities/input output/io.h"
#include "utilities/utils/utils.h"

int main(void) {
    char buffer[10]; unsigned command=10;
    int code=1;
    Node* head = NULL;

    printf("Welcome to deanery database! ");
    while (1) {
        //Declaration of hash with command keys.
        const char *hash[] = {"add" ,"printS" ,"printL" ,"delete" ,"save" ,"load" ,"freeL" ,"best" ,"sort" ,"shutdown"};

        //Read command.
        printf("Chose an action: ");
        read_line(buffer, sizeof(buffer));

        //A loop comparing a command and converting it to an integer for a switch case.
        for (int i = 0; i < 10; i++) {
            if (strcmp(buffer, hash[i])==0) {
                command = i;
                break;
            }
        }

        //Declaring variables and buffers for the read_user_data function.
        int id=0;
        grade student_grade;
        contactType contactype;
        char name[sizeof(((student*)0)->name)];
        char surname[sizeof(((student*)0)->surname)];
        char password[sizeof(((student*)0)->password)];
        char correspondence[sizeof(((student*)0)->correspondence)];

        //Switch case for performing a selected action by the user.
        switch (command) {
            case add: //Block for adding data to the end of the chain
                //Reading user data and checking for errors.
                code = read_user_data(&id, name,surname,&student_grade,password,&contactype,correspondence);
                if (code != COMPLETE) {parsingError(&head,code);}
                //Creating a data container, attaching it to a linked list, and checking for errors.
                code = student_add(createStudent(id,name,surname,student_grade,password,contactype,correspondence,0),&head);
                if (code == MALLOC_FAILE) {addError(&head,code);}
                break;

            case printS: //Block for Student data output by ID.
                clear_screen();
                printf("Please enter student id: ");
                strtoDec(&id); //Reading and converting ID.
                //Find an element by ID and check for error.
                student* pointerToStudentData = find_student_by_id(head,id);
                if (pointerToStudentData == NULL) {
                    break;
                }
                printStudent(pointerToStudentData); //Data output.
                break;

            case printL: //Linked list output block
                clear_screen();
                print_list(head); //Linked list output.
                break;

            case delete: //Block for deleting an element by ID.
                clear_screen();
                printf("Please enter student ID for deleting: ");
                strtoDec(&id); //Reading and converting ID.
                //Deleting an element by ID and check for error.
                code = delete_student_by_id(&head,id);
                if (code == COMPLETE) {
                    clear_screen();
                    printf("Student with ID %d completely deleted.\n",id);
                }
                break;

            case save: //Block for saving data to a file.
                clear_screen();
                //Saving data to a file and check for error.
                code = save_to_file(head);
                if (code == OPEN_FILE_ERROR) {
                    saveError(&head,code);
                    break;
                }
                printf("Data completely saved.\n");
                break;

            case load: //Block for loading data into a heap from a file
                //Loading data and checking for errors.
                code = load_from_file(&head);
                if (code < LIST_ERROR) {
                    loadError(code);
                    break;
                }
                //Check for correct data output upon successful reading
                if (code>0) {
                    clear_screen();
                    printf("%d elements loaded completely.\n", code);
                }
                break;

            case freeL: //Linked list clearing block.
                clear_screen();
                free_list(&head); //Linked list clearing.
                printf("Linked list completely freed.\n");
                break;

            case best: //Block for searching and displaying students with the best grades.
                clear_screen();
                //Block search and verification.
                code = find_student_with_best_grade(head);
                if (code == 0) {
                    printf("Student with best grade wasn't found.\n");
                }
                break;

            case sort: //Block for sorting a linked list by surname.
                clear_screen();
                head = sort_student_by_surname(head); // Sorting a linked list.
                printf("Linked list completely sorted.\n");
                break;

            case errKey: //Block for handling the input of an invalid command key.
                clear_screen();
                printf("You wasn't choose availible action.\n");
                break;

            default:
                break;
        }

        //Check for the key word shutdown
        if (command==shutdown) {
            free_list(&head); //Freeing heap memory
            break;
        }
        command = 10; //Resetting the command counter.
    }

    free_list(&head); //Freeing heap memory if they were not freed when exiting the loop.

    return 0;
}

