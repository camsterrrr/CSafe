/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <openssl/sha.h>

#include "Common.h"
#include "Database.h"
#include "Log.h"

/* START OF DATABASE CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Database class.
*/
Database newDatabase() {
    File fileObj = newFileObj();

    Database dbObj = {
        .fileObj = &fileObj,
        .hashedMasterPW = NULL,
        .numReaders = 0,
        .numWriters = 0,
        .createTS = 0, 
        .lastAccessedTS = 0,
        .lastModifiedTS = 0,
    };

    return dbObj;
}

Database newDatabaseParams_() {
    Database dbObj = newDatabase();

    //* USER INPUT
    File *fileObj = newFileObj_();
    setFileObj(&dbObj, fileObj);
    
    //* USER INPUT
    char *plaintextPW = enterPlaintextMasterPW();
    char *hashedMasterPW = hashPlaintextPassword(plaintextPW);
    setHashedMasterPW(&dbObj, hashedMasterPW);

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

    if (checkFuncParamPtr(inputBuf) == 1) {
        ERROR("No password provided! -- enterPlaintextMasterPW\n");
        return NULL;
    }

    return inputBuf;
}

/**
 * The following function uses the SHA1 function defined in the OpenSSL library's
 *  `sha.h` file.
*/
char* hashPlaintextPassword(char *plaintextPW) {
    if (checkFuncParamPtr(plaintextPW) == 1) {
        ERROR("No password provided! -- enterPlaintextMasterPW\n");
        return NULL;
    }

    char *hashedPW = (char*)calloc(SHA1_BYTES, sizeof(char));

    SHA1((unsigned char*)plaintextPW, strLen(plaintextPW), (unsigned char*)hashedPW);

    return hashedPW;
}

void passwordPrompt() {
    printf("Enter a master password for your database!\n");
    printf("When creating this password, there are two things you should consider...\n");
    printf("\t1. This password will be used to access *all* of your passwords, so don't forget it!\n");
    printf("\t2. This password should be secure enough to protect *all* of your passwords.\n");
}

/* LOCKS */

/* GETTERS */
char* getHashedMasterPW(Database *dbObj) {
    char *retBuf = writeBufContents((*dbObj).hashedMasterPW);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getHashedMasterPW");
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
int setHashedMasterPW(Database *dbObj, char *hashedMasterPW) {
    if (copyBufContents((*dbObj).hashedMasterPW, hashedMasterPW)) {
        ERROR("copyBufContents failed! -- setHashedMasterPW");
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