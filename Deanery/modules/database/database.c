#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "database.h"
#include "../../utilities/utils/utils.h"



int student_add(student* data, Node** element) {
    // Checking data for NULL
    if (data == NULL) {
        return EMPTY_DATA_ERROR;
    }

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

student* find_student_by_id(Node* head, int id) {
    //Temporary pointer for traversing a linked list
    Node* current = head;

    //Loop to find the target element
    while (current != NULL) {
        if (current->data->id == id) {
            return current->data;
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
        return EMPTY_LIST_ERROR;
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
        printf("Student with %d ID not found.\n\n", id);
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

int save_to_file(Node* head) {
    if (head == NULL) {
        printf("Empty list.\n");
        return EMPTY_LIST_ERROR;
    }

    //Opening the file and checking
    FILE* database = fopen("/Users/vortexskyshaker/CLionProjects/FinalProject/Deanery/modules/database/database.txt", "w");
    if (database == NULL) {
        return OPEN_FILE_ERROR;
    }

    //Cycle for writing data
    Node* current = head;
    while (current != NULL) {
        fprintf(database, "%d,", current->data->id);
        fprintf(database, "%s,", current->data->name);
        fprintf(database, "%s,", current->data->surname);
        grade grade = current->data->gradeOfStudent;
        if (grade < 1 || grade > 5) {
            fprintf(database, "WITHOUT_GRADE,");
        }else {
            fprintf(database, "%c,", current->data->gradeOfStudent + '@');
        }
        fprintf(database, "%s,", current->data->password);

        switch (current->data->contactOfStudent) {
            case PHONE:
                fprintf(database, "PHONE,");
                fprintf(database, "%s", current->data->correspondence.phone);
                break;
            case EMAIL:
                fprintf(database, "EMAIL,");
                fprintf(database, "%s", current->data->correspondence.eMail);
                break;
            default:
                fprintf(database, "NONE");
                break;
        }

        fprintf(database, "\n");
        current = current->next;
    }

    //Closing a file
    fclose(database);
    return 1;
}

int load_from_file(Node** head) {
    // Checking if a linked list is empty
    if ((*head) != NULL) {
        printf("Header pointer must be NULL.\n");
        return LIST_ERROR;
    }

    // Opening and checking if a file is open
    FILE* database = fopen("/Users/vortexskyshaker/CLionProjects/FinalProject/Deanery/modules/database/database.txt", "r");
    if (database == NULL) {
        return OPEN_FILE_ERROR;
    }

    //Declaring a variable to count the number of students read in a loop
    int read_counter = 0;
    while (1) {
        //Reading student data into the buffer
        int character;
        char buffer[1024]; memset(buffer, 0, sizeof(buffer));
        for (int i=0; i < sizeof(buffer)-2; i++) {
            if ((character = fgetc(database)) == '\n' || character == EOF) {
                break;
            }
            buffer[i] = (char)character;
        } buffer[sizeof(buffer)-1] = '\0';

        // Checking the length of the read string
        if (character != '\n' && character != EOF) {
            fclose(database);
            return ERROR_DATABASE_DATA;
        }

        //Сhecking for correct string format
        unsigned delim_counter=0;
        for (int i=0; buffer[i]!='\0'; i++) {
            if (buffer[i] == ',') {delim_counter++;}
        }
        if (delim_counter < 5 || delim_counter > 6) {
            fclose(database);
            return ERROR_DATABASE_DATA;
        }

        // Declaration of parameters required for parsing
        char *savertok;
        char *delimiter = ",";
        char *toldelim;

        //Start parsing the buffer
        char* token = strtok_r(buffer, delimiter,&savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        long dig = strtol(token, &toldelim, 10);

        //Сhecking the read id
        int id;
        if (dig <= 0 || dig > INT_MAX) {
            fclose(database);
            return ERROR_DATABASE_DATA;
        }else {
            id = (int)dig;
        }

        //Reading and checking the reading of the name
        char name[sizeof(((student*)0)->name)];
        token = strtok_r(NULL, delimiter, &savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        snprintf(name, sizeof(name), "%s", token);

        //Reading and checking the reading of the surname
        char surname[sizeof(((student*)0)->surname)];
        token = strtok_r(NULL, delimiter,&savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        snprintf(surname, sizeof(surname), "%s", token);

        //Reading and checking the reading of the grade
        grade grade;
        token = strtok_r(NULL, delimiter,&savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        dig = token[0] - 'A' + 1;

        //Valuation range check
        if (dig < 1 || dig > 5) {
            grade = WITHOUT_GRADE;
        }else {
            grade = dig;
        }

        //Reading and checking password reading
        char password[sizeof(((student*)0)->password)];
        token = strtok_r(NULL, delimiter,&savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        snprintf(password, sizeof(password), "%s", token);


        //Reading the type and data of correspondence and checking the reading
        char email[sizeof(((contactInfo*)0)->eMail)];
        char phone[sizeof(((contactInfo*)0)->phone)];
        contactType type;
        token = strtok_r(NULL, delimiter,&savertok);
        if (!token) {fclose(database); return PARSING_ERROR;}
        if (strcmp(token,"EMAIL") == 0) {
            type = EMAIL;
            token = strtok_r(NULL, delimiter,&savertok);
            if (!token) {fclose(database); return PARSING_ERROR;}
            snprintf(email, sizeof(email), "%s", token);
        }else if (strcmp(token,"PHONE") == 0) {
            type = PHONE;
            token = strtok_r(NULL, delimiter,&savertok);
            if (!token) {fclose(database); return PARSING_ERROR;}
            snprintf(phone, sizeof(phone), "%s", token);
        }else {
            type = NONE;
        }

        //(switch case) To call a function with the correct parameters
        int validator;
        switch (type) {
            case EMAIL:
                validator = student_add(createStudent(id, name, surname, grade, password, type, email,1),head);
                if (validator != 1) {
                    fclose(database);
                    return ADD_ERROR;
                }
                break;
            case PHONE:
                validator = student_add(createStudent(id, name, surname, grade, password, type, phone,1),head);
                if (validator != 1) {
                    fclose(database);
                    return ADD_ERROR;
                }
                break;
            default:
                validator = student_add(createStudent(id, name, surname, grade, password, type, "",1),head);
                if (validator != 1) {
                    fclose(database);
                    return ADD_ERROR;
                }
                break;
        }

        //EOF check
        if ((character = fgetc(database)) == EOF) {
            read_counter++;
            break;
        }else {
            ungetc(character,database);
        }
        read_counter++;
    }

    fclose(database);
    return read_counter;
}

