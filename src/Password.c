/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

#include "Common.h"
#include "Log.h"
#include "Password.h"

/* START OF PASSWORD CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Password class.
*/
/* CONSTRUCTORS */
Password newPasswordObj() {
    Password passwordObj = {
        .plaintextPW = NULL, 
        .hashedPW = NULL,
        .pwLen = 0,
        .capitalCharFlag = 0,
        .spaceCharFlag = 0,
        .specialCharFlag = 0,
    };

    return passwordObj;
}

Password newPasswordObjParams(char* plaintextPW, char *hashedPW, 
        unsigned int capitalCharFlag, unsigned int spaceCharFlag, 
        unsigned int specialCharFlag) {
    Password passwordObj = {
        .plaintextPW = NULL, 
        .hashedPW = NULL,
        .pwLen = 0,
        .capitalCharFlag = 0,
        .spaceCharFlag = 0,
        .specialCharFlag = 0,
    };

    //! Account for NULL checks
    setPlaintextPW(&passwordObj, plaintextPW);
    setHashedPW(&passwordObj, hashedPW);
    setPWLen(&passwordObj, strLen(plaintextPW));
    setCapitalCharFlag(&passwordObj, capitalCharFlag);
    setSpaceCharFlag(&passwordObj, spaceCharFlag);
    setSpecialCharFlag(&passwordObj, specialCharFlag);

    return passwordObj;
}

/* MEMBER FUNCTIONS */

/* GETTERS */
char* getPlaintextPW(Password *passwordObj) {
    char *retBuf = writeBufContents((*passwordObj).hashedPW);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getPlaintextPW");
        return NULL;
    }

    return retBuf;
}

char* getHashedPW(Password *passwordObj) {
    char *retBuf = writeBufContents((*passwordObj).hashedPW);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getHashedPW");
        return NULL;
    }

    return retBuf;
}

size_t getPWLen(Password *passwordObj) {
    size_t retVal = (*passwordObj).pwLen;

    return retVal;
}

unsigned int getCapitalCharFlag(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).capitalCharFlag;

    return retVal;
}

unsigned int getSpaceCharFlag(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).spaceCharFlag;

    return retVal;
}

unsigned int getSpecialCharFlag(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).specialCharFlag;

    return retVal;
}

/* SETTERS */
int setPlaintextPW(Password *passwordObj, char *plaintextPW) {
    //* copyBufContents call
    if (copyBufContents((*passwordObj).plaintextPW, plaintextPW)) {
        ERROR("copyBufContents failed! -- setPlaintextPW");
        return 1;
    }

    return 0;
}

int setHashedPW(Password *passwordObj, char *hashedPW) {
    //* copyBufContents call
    if (copyBufContents((*passwordObj).hashedPW, hashedPW)) {
        ERROR("copyBufContents failed! -- setHashedPW");
        return 1;
    }

    return 0;
}

int setPWLen(Password *passwordObj, size_t pwLen) {
    //* NULL check
    if (checkFuncParamsInt(passwordObj, pwLen)) {
        ERROR("NULL pointers! -- setPWLen");
        return 1; 
    }

    (*passwordObj).pwLen = pwLen;

    return 0;
}

int setCapitalCharFlag(Password *passwordObj, unsigned int capitalCharFlag) {
    //* NULL check
    if (checkFuncParamsInt(passwordObj, capitalCharFlag)) {
        ERROR("NULL pointers! -- setCapitalCharFlag");
        return 1; 
    }

    (*passwordObj).capitalCharFlag = capitalCharFlag;

    return 0;
}

int setSpaceCharFlag(Password *passwordObj, unsigned int spaceCharFlag) {
    //* NULL check
    if (checkFuncParamsInt(passwordObj, spaceCharFlag)) {
        ERROR("NULL pointers! -- setSpaceCharFlag");
        return 1; 
    }

    (*passwordObj).spaceCharFlag = spaceCharFlag;

    return 0;
}

int setSpecialCharFlag(Password *passwordObj, unsigned int specialCharFlag) {
    //* NULL check
    if (checkFuncParamsInt(passwordObj, specialCharFlag)) {
        ERROR("NULL pointers! -- setSpecialCharFlag");
        return 1; 
    }

    (*passwordObj).specialCharFlag = specialCharFlag;

    return 0;
}

/* END OF PASSWORD CLASS IMPLEMENTATION */