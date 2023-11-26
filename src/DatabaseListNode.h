/**
 * 
*/

/* LIBRARIES */
#include <string>

#include <DatabaseEntry.h>

/* START OF DATABASELISTNODE CLASS */
#ifndef DATABASELISTNODE_H
#define DATABASELISTNODE_H

class DatabaseListNode {
    public:
        /* CONSTRUCTORS*/
        DatabaseListNode();
        /* MEMBER FUNCTIONS */
        /* GETTERS */
        /* SETTERS */

    /* MEMBER VARIABLES */
    private:
        DatabaseEntry *backwardPtr, *forwardPtr; // used to traverse/have references to all of the entries.
        DatabaseEntry *databaseEntryPtr; // points to the actual entry.
};

#endif

/* END OF DATABASELISTNODE CLASS */