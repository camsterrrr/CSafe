/**
 * 
*/

/* LIBRARIES */
#include <fcntl.h>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

/* PREPROCESSING STATEMENTS */

/** LOGGING FUNCTIONS
 * DEBUG: info that is useful to devs.
 * ERROR: errors that crash a function.
 * FATAL: errors that force app to shutdown or crash.
 * INFO: general info about how app is running.
 * WARN: something can cause oddities in application behavior.
*/
#define DEBUG(...) fprintf(stderr, "DEBUG:\t"); fprintf(stderr, __VA_ARGS__);
#define ERROR(...) fprintf(stderr, "ERROR:\t"); fprintf(stderr, __VA_ARGS__);
#define FATAL(...) fprintf(stderr, "FATAL:\t"); fprintf(stderr, __VA_ARGS__);
#define INFO(...) fprintf(stderr, "INFO:\t"); fprintf(stderr, __VA_ARGS__);
#define WARN(...) fprintf(stderr, "WARN:\t"); fprintf(stderr, __VA_ARGS__);
#define PRINTSTR(...) fprintf(stderr, "%s\n", __VA_ARGS__);

/* FUNCTION DECLARATIONS */
void menu(unsigned int*);
void menuSwitchBlock(unsigned int*);
void testLogging();
int creatFileAtLocation(std::string);
int closeFileDescriptor (int);
int openFileAtLocation(std::string);
void readFromFileDescriptor(int);

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
    char inputBuf[256];
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

        readFromFileDescriptor(fd);

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

void readFromFileDescriptor(int fd) {
    FILE *fileObj = fdopen(fd, "r");

    if (fileObj == NULL) {
        ERROR("Unable to open file descriptor!\n");
        return; 
    }

    char buffer[256];
    std::string fileContents = "";
    while (fgets(buffer, 1024, fileObj) != NULL) {
        fileContents.append(buffer);
        PRINTSTR(buffer);
    }

    fclose(fileObj);
}

int checkValidFileDescriptor(int fd) { return (fd > 0) ? 0 : 1; }

int closeFileDescriptor (int fd) { return close(fd); }

int creatFileAtLocation(std::string fileLocation) {
    const char *cStrFileLocation = fileLocation.c_str();
    int fd = creat(cStrFileLocation, O_RDWR);

    if (checkValidFileDescriptor(fd) == 1) { return -1; }

    return fd;
}

int openFileAtLocation(std::string fileLocation) {
    const char *cStrFileLocation = fileLocation.c_str();
    int fd = open(cStrFileLocation, O_RDONLY);

    if (checkValidFileDescriptor(fd) == 1) { return -1; }

    return fd;
}

/* UNIT TESTS */
void testLogging() {
    DEBUG("DEBUG test\n");
    ERROR("ERROR test\n");
    FATAL("FATAL test\n");
    INFO("INFO test\n");
    WARN("WARN test\n");
}

/* END OF FILE */