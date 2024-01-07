/**
 * 
*/

/* LIBRARIES */
// #include <pthread.h>
#include <time.h>

#include "File.h"
#include "Password.h"

/* START OF DATABASE CLASS */
#ifndef DATABASE_H
#define DATABASE_H

typedef struct Database {
    char *hashedMasterPW;
    File *fileObj;
    int numReaders, numWriters;
    time_t createTS, lastAccessedTS, lastModifiedTS;
} Database;

/* CONSTRUCTORS */
Database newDatabase();
Database newDatabaseParams_();

/* MEMBER FUNCTIONS */
char* enterPlaintextMasterPW();
char* hashPlaintextPassword(char*);
int deleteDB(char*);
int updateMasterPW(char*, char*);
int verifyMasterPW(char*);
int writeDataToFile(char*);
void passwordPrompt();

/* LOCKS */

/* GETTERS */
char* getHashedMasterPW(Database*);
File* getFileObj(Database*);
int getNumReaders(Database*);
int getNumWriters(Database*);
time_t getCreateTS(Database*);
time_t getLastAccessedTS(Database*);
time_t getLastModifiedTS(Database*);

/* SETTERS */
int setHashedMasterPW(Database*, char*);
int setFileObj(Database*, File*);
int setNumReaders(Database*, int);
int setNumWriters(Database*, int);
int setCreateTS(Database*, time_t);
int setLastAccessedTS(Database*, time_t);
int setLastModifiedTS(Database*, time_t);

#endif

/* END OF DATABASE CLASS */