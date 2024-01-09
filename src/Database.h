/**
 * 
*/

/* LIBRARIES */
// #include <pthread.h>
#include <time.h>

#include "File.h"
#include "Password.h"
#include "Timestamp.h"

/* START OF DATABASE CLASS */
#ifndef DATABASE_H
#define DATABASE_H

typedef struct Database {
    char *hashedMasterPW;
    File *fileObj;
    int numReaders, numWriters;
    Password *passwordObj;
    Timestamp *timestampObj;
} Database;

/* CONSTRUCTORS */
Database newDatabase();
Database newDatabase_();

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
char* getSaltVal(Database*);
File* getFileObj(Database*);
int getNumReaders(Database*);
int getNumWriters(Database*);
Password* getPasswordObj(Database*);
Timestamp* getTimestampObj(Database*);

/* SETTERS */
int setSaltVal(Database*, char*);
int setFileObj(Database*, File*);
int setNumReaders(Database*, int);
int setNumWriters(Database*, int);
int setPasswordObj(Database*, Password*);
int setTimestampObj(Database*, Timestamp*);

#endif

/* END OF DATABASE CLASS */