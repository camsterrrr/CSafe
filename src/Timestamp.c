/**
 * 
*/

/* PREPROCESSING STATEMENTS */

#include "Log.h"
#include "Timestamp.h"

/* START OF TIMESTAMP CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Timestamp class.
*/
Timestamp newTimestamp() {
    Timestamp timestampObj = {
        .timeCreated = time(NULL),
        .lastAccessed = time(NULL),
        .lastModified = time(NULL)
    };

    return timestampObj;
}

/* MEMBER FUNCTIONS */


/* GETTERS */
time_t getTimeCreated(Timestamp *timestampObj) {
    time_t retVal = (*timestampObj).timeCreated;

    return retVal;
}

time_t getLastAccessed(Timestamp *timestampObj) {
    time_t retVal = (*timestampObj).lastAccessed;

    return retVal;
}

time_t getLastModified(Timestamp *timestampObj) {
    time_t retVal = (*timestampObj).lastModified;

    return retVal;
}

/* SETTERS */
int setTimeCreated(Timestamp *timestampObj, time_t timeCreated) {
    //* NULL check
    if (checkFuncParamPtr(timestampObj)) {
        ERROR("NULL pointers! -- setTimeCreated\n");
        return 1; 
    }

    (*timestampObj).timeCreated = timeCreated;

    return 0;
}

int setLastAccessed(Timestamp *timestampObj, time_t lastAccessed) {
    //* NULL check
    if (checkFuncParamPtr(timestampObj)) {
        ERROR("NULL pointers! -- setLastAccessed\n");
        return 1; 
    }

    (*timestampObj).lastAccessed = lastAccessed;

    return 0;
}

int setLastModified(Timestamp *timestampObj, time_t lastModified) {
    //* NULL check
    if (checkFuncParamPtr(timestampObj)) {
        ERROR("NULL pointers! -- setLastModified\n");
        return 1; 
    }

    (*timestampObj).lastModified = lastModified;

    return 0;
}

/* END OF TIMESTAMP CLASS IMPLEMENTATION */