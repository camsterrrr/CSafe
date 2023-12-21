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
    char *saltVal;
    File *fileObj;
    int numReaders, numWriters;
    Password *passwordObj;
    time_t createTS, lastAccessedTS, lastModifiedTS;
} Database;

/* CONSTRUCTORS */
Database newDatabase();
Database newDatabaseParams(char*);

/* MEMBER FUNCTIONS */
int deleteDB(char*);
int updateMasterPW(char*, char*);
int verifyMasterPW(char*);
int writeDataToFile(char*);

/* LOCKS */

/* GETTERS */
char* getSaltVal(Database*);
File* getFileObj(Database*);
int getNumReaders(Database*);
int getNumWriters(Database*);
Password* getPasswordObj(Database*);
time_t getCreateTS(Database*);
time_t getLastAccessedTS(Database*);
time_t getLastModifiedTS(Database*);

/* SETTERS */
int setSaltVal(Database*, char*);
int setFileObj(Database*, File*);
int setNumReaders(Database*, int);
int setNumWriters(Database*, int);
int setPasswordObj(Database*, Password*);
int setCreateTS(Database*, time_t);
int setLastAccessedTS(Database*, time_t);
int setLastModifiedTS(Database*, time_t);

#endif

/* END OF DATABASE CLASS */