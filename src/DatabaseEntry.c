/**
 * 
*/

/* PREPROCESSING STATEMENTS */

#include "Common.h"
#include "DatabaseEntry.h"
#include "Log.h"

/* START OF DATABASEENTRY CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the DatabaseEntry class.
*/
DatabaseEntry newDatabaseEntry() {
    DatabaseEntry dbeObj = {
        .databasePtr = NULL,
        .backwardPtr = NULL,
        .forwardPtr = NULL,
        .passwordPtr = NULL,
    };

    return dbeObj;
}

DatabaseEntry newDatabaseEntryParams(Database *databasePtr, DatabaseEntry *backwardPtr, 
        DatabaseEntry *forwardPtr, Password *passwordPtr) {
    DatabaseEntry dbeObj = {
        .databasePtr = NULL,
        .backwardPtr = NULL,
        .forwardPtr = NULL,
        .passwordPtr = NULL,
    };

    setDatabasePtr(&dbeObj, databasePtr);
    setBackwardPtr(&dbeObj, backwardPtr);
    setForwardPtr(&dbeObj, forwardPtr);
    setPasswordPtr(&dbeObj, passwordPtr);

    return dbeObj;
}


/* MEMBER FUNCTIONS */

/* GETTERS */
Database* getDatabasePtr(DatabaseEntry *dbeObj) {
    //* NULL check
    if (dbeObj == NULL) {
        ERROR("NULL pointer! -- getDatabasePtr\n");
        return NULL;
    }

    return (*dbeObj).databasePtr;
}

DatabaseEntry* getBackwardPtr(DatabaseEntry *dbeObj) {
    //* NULL check
    if (dbeObj == NULL) {
        ERROR("NULL pointer! -- getBackwardPtr\n");
        return NULL;
    }

    return (*dbeObj).backwardPtr;
}

DatabaseEntry* getForwardPtr(DatabaseEntry *dbeObj) {
    //* NULL check
    if (dbeObj == NULL) {
        ERROR("NULL pointer! -- getForwardPtr\n");
        return NULL;
    }

    return (*dbeObj).forwardPtr;
}

Password* getPasswordPtr(DatabaseEntry *dbeObj) {
    //* NULL check
    if (dbeObj == NULL) {
        ERROR("NULL pointer! -- getPasswordPtr\n");
        return NULL;
    }

    return (*dbeObj).passwordPtr;
}

/* SETTERS */
int setDatabasePtr(DatabaseEntry *dbeObj, Database *databasePtr) {
    //* NULL check
    if (checkFuncParamsPtrs(dbeObj, databasePtr)) {
        ERROR("NULL pointers! -- setDatabasePtr");
        return 1;
    }

    (*dbeObj).databasePtr = databasePtr;

    return 0;
}

int setBackwardPtr(DatabaseEntry *dbeObj, DatabaseEntry *backwardPtr) {
    //* NULL check
    if (checkFuncParamsPtrs(dbeObj, backwardPtr)) {
        ERROR("NULL pointers! -- setBackwardPtr");
        return 1;
    }

    (*dbeObj).backwardPtr = backwardPtr;

    return 0;
}

int setForwardPtr(DatabaseEntry *dbeObj, DatabaseEntry *forwardPtr) {
    //* NULL check
    if (checkFuncParamsPtrs(dbeObj, forwardPtr)) {
        ERROR("NULL pointers! -- setForwardPtr");
        return 1;
    }

    (*dbeObj).forwardPtr = forwardPtr;

    return 0;
}

int setPasswordPtr(DatabaseEntry *dbeObj, Password *passwordPtr) {
    //* NULL check
    if (checkFuncParamsPtrs(dbeObj, passwordPtr)) {
        ERROR("NULL pointers! -- setPasswordPtr");
        return 1;
    }

    (*dbeObj).passwordPtr = passwordPtr;

    return 0;
}

/* END OF DATABASEENTRY CLASS IMPLEMENTATION */