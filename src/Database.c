/**
 * 
*/

/* PREPROCESSING STATEMENTS */

#include "Common.h"
#include "Database.h"
#include "Log.h"

/* START OF DATABASE CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Database class.
*/
Database newDatabase() {
    Database dbObj = {
        .saltVal = NULL,
        .fileObj = NULL,
        .passwordObj = NULL,
        .numReaders = 0,
        .numWriters = 0,
        .createTS = 0, 
        .lastAccessedTS = 0,
        .lastModifiedTS = 0,
    };

    return dbObj;
}

Database newDatabaseParams(char *fileLocation) {
    Database dbObj = {
        .saltVal = NULL,
        .fileObj = NULL,
        .passwordObj = NULL,
        .numReaders = 0,
        .numWriters = 0,
        .createTS = 0, 
        .lastAccessedTS = 0,
        .lastModifiedTS = 0,
    };

    // File *fileObj = newFileObjParams()
    // Password *passwordObj = newPasswordObj();

    // setSaltVal(&dbObjm, )
    // setFileLocation(&dbObj, );
    // setMasterPWHash(&dbObj, );
    setNumReaders(&dbObj, 1);
    setNumWriters(&dbObj, 1);

    time_t ts = time(NULL);
    setCreateTS(&dbObj, ts);
    setLastAccessedTS(&dbObj, ts);
    setLastModifiedTS(&dbObj, ts);

    return dbObj;
}

/* MEMBER FUNCTIONS */
char* enterPlaintextMasterPW() {
    char *inputBuf = (char*)calloc(256, sizeof(char));
    
    passwordPrompt();

    //* USER INPUT
    scanf("%s", inputBuf);



    return inputBuf;
}

void passwordPrompt() {
    printf("Enter a master password for your database!\n");
    printf("When creating this password, there are two things you should consider...\n");
    printf("\t1. This password will be used to ACCESS  ALL of your passwords, so don't forget it.\n");
    printf("\t2. This password should be secure enough to PROTECT ALL of your passwords.\n");
}

/* LOCKS */

/* GETTERS */
char* getSaltVal(Database *dbObj) {
    char *retBuf = writeBufContents((*dbObj).saltVal);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getSaltVal");
        return NULL;
    }

    return retBuf;
}

File* getFileObj(Database *dbObj) {
    return (*dbObj).fileObj;
}

int getNumReaders(Database *dbObj) {
    return (*dbObj).numReaders;
}

int getNumWriters(Database *dbObj) {
    return (*dbObj).numWriters;
}

Password* getPasswordObj(Database *dbObj) {
    return (*dbObj).passwordObj;
}

time_t getCreateTS(Database *dbObj) {
    return (*dbObj).createTS;
}

time_t getLastAccessedTS(Database *dbObj) {
    return (*dbObj).lastAccessedTS;
}

time_t getLastModifiedTS(Database *dbObj) {
    return (*dbObj).lastModifiedTS;
}

/* SETTERS */
int setSaltVal(Database *dbObj, char *saltVal) {
    if (copyBufContents((*dbObj).saltVal, saltVal)) {
        ERROR("copyBufContents failed! -- setSaltVal");
        return 1;
    }

    return 0;
}

int setFileObj(Database *dbObj, File *fileObj) {
    if(checkFuncParamsPtrs((*dbObj).fileObj, fileObj)) {
        ERROR("NULL pointers! -- setFileObj");
        return 1;
    }

    (*dbObj).fileObj = fileObj;

    return 0;
}

int setNumReaders(Database *dbObj, int numReaders) {
    //* NULL check
    if(checkFuncParamsInt(dbObj, numReaders)) {
        ERROR("NULL pointers! -- setNumReaders");
        return 1; 
    }

    (*dbObj).numReaders = numReaders;

    return 0;
}

int setNumWriters(Database *dbObj, int numWriters) {
    //* NULL check
    if(checkFuncParamsInt(dbObj, numWriters)) {
        ERROR("NULL pointers! -- setNumWriters");
        return 1; 
    }

    (*dbObj).numWriters = numWriters;

    return 0;
}

int setPasswordObj(Database *dbObj, Password *passwordObj) {
    if(checkFuncParamsPtrs((*dbObj).passwordObj, passwordObj)) {
        ERROR("NULL pointers! -- setPasswordObj");
        return 1;
    }

    (*dbObj).passwordObj = passwordObj;

    return 0;
}

int setCreateTS(Database *dbObj, time_t createTS) {
    //* NULL check
    if(checkFuncParamsInt(dbObj, createTS)) {
        ERROR("NULL pointers! -- setCreateTS");
        return 1; 
    }

    (*dbObj).createTS = createTS;

    return 0;
}

int setLastAccessedTS(Database *dbObj, time_t lastAccessedTS) {
    //* NULL check
    if(checkFuncParamsInt(dbObj, lastAccessedTS)) {
        ERROR("NULL pointers! -- setLastAccessedTS");
        return 1; 
    }

    (*dbObj).lastAccessedTS = lastAccessedTS;

    return 0;
}

int setLastModifiedTS(Database *dbObj, time_t lastModifiedTS) {
    //* NULL check
    if(checkFuncParamsInt(dbObj, lastModifiedTS)) {
        ERROR("NULL pointers! -- setLastModifiedTS");
        return 1; 
    }

    (*dbObj).lastModifiedTS = lastModifiedTS;

    return 0;
}

/* END OF DATABASE CLASS IMPLEMENTATION */