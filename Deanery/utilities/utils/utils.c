#include <stdio.h>
#include <limits.h>
#include "utils.h"
#include <stdlib.h>
#include "database.h"
#include "io.h"


void clear_screen() {
    printf("\033[H\033[J");
}

int strtoDec(int* id) {
    char* saver;
    char buffer[13];
    read_line(buffer,sizeof(buffer));

    long dig = strtol(buffer,&saver,10);
    if (dig < 0 || dig > INT_MAX) {
        return 0;
    }

    *id = (int)dig;

    return 1;
}

void parsingError(Node** head,int code){
    int save_valid_code = save_to_file(*head);
    if (save_valid_code == OPEN_FILE_ERROR) {
        fprintf(stderr,"Fatal error of parsing, data lost. Exit code %d", code);
    }else {
        fprintf(stderr,"Fatal error of parsing, data saved. Exit code %d", code);
    }
    free_list(head);
    exit(0);
}

void addError(Node** head,int code) {
        int save_valid_code = save_to_file(*head);
        if (save_valid_code == EMPTY_LIST_ERROR || save_valid_code == OPEN_FILE_ERROR) {
            fprintf(stderr, "Fatal error of adding student, data lost. exit code %d",code);
        }else {
            fprintf(stderr, "Fatal error of adding student,data saved. exit code %d",code);
        }
        free_list(head);
        exit(0);
}

void saveError(Node** head,int code) {
        fprintf(stderr,"Fatal error of saving data, data lost. Exit code %d", code);
        free_list(head);
        exit(0);
}

void loadError(int code) {
    fprintf(stderr,"Fatal error of loading data. Exit code %d", code);
    exit(0);
}

