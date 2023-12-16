/**
 * 
*/

/* LIBRARIES */
#include <fcntl.h>
#include <iostream>

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

/* FUNCTION DECLARATIONS */
void menu(unsigned int*);
void testLogging();
char* stringToCString(std::string);
int creatFileAtLocation(std::string);
int openFileAtLocation(std::string);

/* START OF MAIN */
int main(void) {
    INFO("Starting CSafe...\n"); 
    
    while (1) {   
        unsigned int userInput = 0;
        menu(&userInput);
        if(userInput) {
            // switchBlock(&userInput);
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
    printf("\t3. \n");
    printf("\t4. \n");
    printf("==========================================\n");
    printf("\t$ ");

    scanf("%u", userInput);
}

int checkValidFileDescriptor(int fileDescriptor) {
    return (fileDescriptor > 0) ? 0 : 1;
}

/**
 * 
*/
int creatFileAtLocation(std::string fileLocation) {

    // int fd = creat();

    return 0;
}

/**
 * 
*/
int openFileAtLocation(std::string fileLocation) {
    const char *cStrFileLocation = fileLocation.c_str();
    int fd = open(cStrFileLocation, O_RDONLY);

    if (checkValidFileDescriptor(fd) == 1) { return 1; }

    return 0;
}



// char* stringToCString(std::string stringToConvert) {

// }

/* UNIT TESTS */
void testLogging() {
    DEBUG("DEBUG test\n");
    ERROR("ERROR test\n");
    FATAL("FATAL test\n");
    INFO("INFO test\n");
    WARN("WARN test\n");
}

/* END OF FILE */