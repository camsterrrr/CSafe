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
    /* CREATE NEW DATABASE */
    if (*userInput == 1) {
        char *inputBuf = enterFileLocation();
        int fd = creatFileAtLocation(inputBuf);

        if (fd <= 0) {
            ERROR("Database creation failed!\n");
            return;
        }

        char *plaintextPW = enterPlaintextMasterPW();



        Database dbObj = newDatabaseParams();

        // readFromFileDescriptor(fd);

        closeFileDescriptor(fd);
    } 
    
    /* OPEN EXISTING DATABASE*/
    else if (*userInput == 2) {
        char *inputBuf = enterFileLocation();

        // std::string fileLocation(inputBuf);
        int fd; // = openFileAtLocation(fileLocation);

        if (fd <= 0) {
            ERROR("Unable to read database!\n");
            return;
        }

        // READ DATA

        closeFileDescriptor(fd);
    } 
}

/* END OF FILE */