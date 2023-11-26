/**
 * @author Cameron Oakley (@camsterrrr)
 * @details: This class is used to store references to each of the DatabaseEntry objects as they are 
 *  sitting in memory. Objects of this class will only hold ptr data, so I don't want any of this data 
 *  stored along with the password data. 
*/

/* LIBRARIES */
#include <string>

#include "DatabaseEntry.h"

/* START OF DATABASELISTNODE CLASS */
#ifndef DATABASELISTNODE_H
#define DATABASELISTNODE_H

class DatabaseListNode {
    public:
        /* CONSTRUCTORS*/
        DatabaseListNode();
        DatabaseListNode(DatabaseEntry*, DatabaseEntry*, DatabaseEntry*);
        /* MEMBER FUNCTIONS */
        /* GETTERS */
        DatabaseEntry* getBackwardPtr();
        DatabaseEntry* getForewardPtr();
        DatabaseEntry* getDatabasePtr();
        /* SETTERS */
        void setBackwardPtr(DatabaseEntry*);
        void setForwardPtr(DatabaseEntry*);
        void setDatabasePtr(DatabaseEntry*);

    /* MEMBER VARIABLES */
    private:
        DatabaseEntry *backwardPtr, *forwardPtr; // used to traverse/have references to all of the entries.
        DatabaseEntry *databaseEntryPtr; // points to the actual entry.
};

#endif

/* END OF DATABASELISTNODE CLASS */