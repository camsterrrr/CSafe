/**
 * 
*/

/* LIBRARIES */
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
void menu();
void testLogging();

/* START OF MAIN */
int main(void) {
    menu();
}
/* END OF MAIN */

/* FUNCTION DEFINITIONS */
/**
 * 
*/
void menu() {
    printf("============ WELCOME TO CSafe ============\n");
    printf("\t1. Create new password database.\n");
    printf("\t2. Open an existing password database.\n");
    printf("\t3. \n");
    printf("\t4. \n");
    printf("==========================================\n");
}

/**
 * 
*/
int readFileLocation(std::string fileLocation) {

    return 0;
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