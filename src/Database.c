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
    Timestamp timestampObj = newTimestamp();

    Database dbObj = {
        .fileObj = &fileObj,
        .hashedMasterPW = NULL,
        .numReaders = 0,
        .numWriters = 0,
        .timestampObj = &timestampObj
    };

    return dbObj;
}

Database newDatabase_() {
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
        ERROR("writeBufContents failed! -- getHashedMasterPW\n");
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

Timestamp* getTimestampObj(Database *dbObj) {
    return  (*dbObj).timestampObj;
}

/* SETTERS */
int setHashedMasterPW(Database *dbObj, char *hashedMasterPW) {
    if (copyBufContents((*dbObj).hashedMasterPW, hashedMasterPW)) {
        ERROR("copyBufContents failed! -- setHashedMasterPW\n");
        return 1;
    }

    return 0;
}

int setFileObj(Database *dbObj, File *fileObj) {
    if(checkFuncParamsPtrs(dbObj, fileObj)) {
        ERROR("NULL pointers! -- setFileObj\n");
        return 1;
    }

    (*dbObj).fileObj = fileObj;

    return 0;
}

int setNumReaders(Database *dbObj, int numReaders) {
    //* NULL check
    if(checkFuncParamPtr(dbObj)) {
        ERROR("NULL pointer! -- setNumReaders\n");
        return 1; 
    }

    (*dbObj).numReaders = numReaders;

    return 0;
}

int setNumWriters(Database *dbObj, int numWriters) {
    //* NULL check
    if(checkFuncParamPtr(dbObj)) {
        ERROR("NULL pointer! -- setNumWriters\n");
        return 1; 
    }

    (*dbObj).numWriters = numWriters;

    return 0;
}

int setTimestampObj(Database *dbObj, Timestamp *timestampObj) {
    if(checkFuncParamsPtrs(dbObj, timestampObj)) {
        ERROR("NULL pointers! -- setTimestampObj\n");
        return 1;
    }

    (*dbObj).timestampObj = timestampObj;

    return 0;
}

/* END OF DATABASE CLASS IMPLEMENTATION */