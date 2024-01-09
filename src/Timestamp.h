/**
 * 
*/

/* LIBRARIES */
#include <time.h>

/* START OF PASSWORD CLASS */
#ifndef TIMESTAMP_H
#define TIMESTAMP_H

typedef struct Timestamp {
    time_t timeCreated, lastAccessed, lastModified;
} Timestamp;

/* CONSTRUCTORS */
Timestamp newTimestamp();

/* MEMBER FUNCTIONS */

/* GETTERS */
time_t getTimeCreated(Timestamp*);
time_t getLastAccessed(Timestamp*);
time_t getLastModified(Timestamp*);

/* SETTERS */
int setTimeCreated(Timestamp*, time_t);
int setLastAccessed(Timestamp*, time_t);
int setLastModified(Timestamp*, time_t);

#endif

/* END OF TIMESTAMP CLASS */