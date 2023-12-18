/**
 * 
*/

/* LIBRARIES */
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "Database.h"
#include "File.h"
#include "Log.h"

/* PREPROCESSING STATEMENTS */


/* FUNCTION DECLARATIONS */
void menu(unsigned int*);
void menuSwitchBlock(unsigned int*);
Database* newDatabase(char*);

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
    // printf("\t3. \n");
    // printf("\t4. \n");
    printf("==========================================\n");
    printf("\t$ ");

    /* USER INPUT */
    scanf("%u", userInput);
    // PRINTSTR(inputBuf);
}

void menuSwitchBlock(unsigned int *userInput) {
    char *inputBuf = (char*)calloc(256, sizeof(char));
    if (*userInput == 1) {
        printf("\tEnter file location:\n");
        printf("\t$ ");

        /* USER INPUT */
        scanf("%s", inputBuf);
        // PRINTSTR(inputBuf);

        std::string fileLocation(inputBuf);
        int fd = creatFileAtLocation(fileLocation);

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

        std::string fileLocation(inputBuf);
        int fd = openFileAtLocation(fileLocation);

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

Database* newDatabase(char *fileLocation) {
    printf("Your master password is used to decrypt the database. 
        There are two considerations user's should make:\n");
    printf("1. Master passwords unlock access to ALL stored passwords,
        please ensure that it is secure!\n");
    printf("2. If you forget this password, you won't be able to
        decrypt your password database!\n");
    printf("Enter a master password: \n");
    printf("\t$");

    /* USER INPUT */
    char *plaintextMasterPWBuffer = (char*)calloc(256, sizeof(char));
    scanf("%s", plaintextMasterPWBuffer);

    time_t currTimestamp;
    time(&currTimestamp);
    
    Database newDB = new Database(currTimestamp, currTimestamp, currTimestamp, 
        fileLocation, plaintextMasterPWBuffer);

    /* NULL BUFFER */
    memset(plaintextMasterPWBuffer, 0b00000000, sizeof(char));
    memset(fileLocation, 0b00000000, sizeof(char));

    return newDB; 
}
// * calloc: https://en.cppreference.com/w/c/memory/calloc 
// * memset: https://en.cppreference.com/w/cpp/string/byte/memset

/* END OF FILE */