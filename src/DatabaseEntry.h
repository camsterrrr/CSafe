/**
 * 
*/

/* LIBRARIES */

#include "Database.h"
#include "Password.h"

/* START OF DATABASEENTRY CLASS */
#ifndef DATABASEENTRY_H
#define DATABASEENTRY_H

typedef struct DatabaseEntry {
    Database *databasePtr;
    struct DatabaseEntry *backwardPtr, *forwardPtr; // struct work around. If not, use void* and then cast
    Password *passwordPtr;
} DatabaseEntry;

/* CONSTRUCTORS*/
DatabaseEntry newDatabaseEntry();
DatabaseEntry newDatabaseEntryParams(Database*, DatabaseEntry*, DatabaseEntry*, Password*);

/* MEMBER FUNCTIONS */

/* GETTERS */
Database* getDatabasePtr(DatabaseEntry*);
DatabaseEntry* getBackwardPtr(DatabaseEntry*);
DatabaseEntry* getForwardPtr(DatabaseEntry*);
Password* getPasswordPtr(DatabaseEntry*);

/* SETTERS */
int setDatabasePtr(DatabaseEntry*, Database*);
int setBackwardPtr(DatabaseEntry*, DatabaseEntry*);
int setForwardPtr(DatabaseEntry*, DatabaseEntry*);
int setPasswordPtr(DatabaseEntry*, Password*);

#endif

/* END OF DATABASEENTRY CLASS */