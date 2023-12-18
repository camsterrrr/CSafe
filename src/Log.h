/**
 * 
*/

/* LIBRARIES */


/* START OF FILE CLASS */
#ifndef LOG_H
#define LOG_H

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

/* CONSTRUCTORS*/

/* MEMBER FUNCTIONS */

/* GETTERS */

/* SETTERS */

#endif 

/* END OF LOG CLASS */