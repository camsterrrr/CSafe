/**
 * 
*/

/* LIBRARIES */
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "Database.h"
#include "File.h"
#include "Log.h"

/* PREPROCESSING STATEMENTS */


/* FUNCTION DECLARATIONS */
void menu(unsigned int*);
void menuSwitchBlock(unsigned int*);

/* START OF MAIN */
int main(void) {
    INFO("Starting CSafe...\n"); 
    
    while (1) {   
        unsigned int userInput = 0;
        menu(&userInput);
        if(userInput) {
            menuSwitchBlock(&userInput);
        } else {
            break;
        }
    }

    INFO("Ending CSafe...\n");
}
/* END OF MAIN */

/* FUNCTION DEFINITIONS */
/**
 * 
*/
void menu(unsigned int *userInput) {
    printf("============ WELCOME TO CSafe ============\n");
    printf("\t0. End program.\n");
    printf("\t1. Create new password database.\n");
    printf("\t2. Open an existing password database.\n");
    printf("==========================================\n");
    printf("\t$ ");

    /* USER INPUT */
    scanf("%u", userInput);
}

void menuSwitchBlock(unsigned int *userInput) {
    char *inputBuf = (char*)calloc(256, sizeof(char));
    if (*userInput == 1) {
        printf("\tEnter file location:\n");
        printf("\t$ ");

        /* USER INPUT */
        scanf("%s", inputBuf);
        // PRINTSTR(inputBuf);

        // std::string fileLocation(inputBuf);
        int fd; // = creatFileAtLocation(fileLocation);

        if (fd <= 0) {
            ERROR("Database creation failed!\n");
            return;
        }

        // readFromFileDescriptor(fd);

        closeFileDescriptor(fd);
    } else if (*userInput == 2) {
        printf("\tEnter file location:\n");
        printf("\t$ ");

        /* USER INPUT */
        scanf("%s", inputBuf);
        // PRINTSTR(inputBuf);

        // std::string fileLocation(inputBuf);
        int fd; // = openFileAtLocation(fileLocation);

        if (fd <= 0) {
            ERROR("Unable to read database!\n");
            return;
        }

        // READ DATA

        closeFileDescriptor(fd);
    } else if (*userInput == 3) {
        
    } else if (*userInput == 4) {
        
    }  else {

    }
}

/* END OF FILE */