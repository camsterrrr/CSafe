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
void testLogging();

/* START OF MAIN */
int main(void) {
    printf("CSafe!\n");
    testLogging();
}
/* END OF MAIN */

/* FUNCTION DEFINITIONS */
/**
 * 
*/
void menu() {

}

/**
 * 
*/
int readFileLocation(std::string fileLocation) {

    return 0;
}

void testLogging() {
    DEBUG("DEBUG test\n");
    ERROR("ERROR test\n");
    FATAL("FATAL test\n");
    INFO("INFO test\n");
    WARN("WARN test\n");
}

/* END OF FILE */