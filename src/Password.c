/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Common.h"
#include "Log.h"
#include "Password.h"

/* START OF PASSWORD CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the Password class.
*/
Password newPasswordObj() {
    Password passwordObj = {
        .plaintextPW = NULL, 
        .pwLen = 0,
        .numberBit = 0,
        .spaceBit = 0,
        .specialBit = 0,
        .uppercaseBit = 0
    };

    return passwordObj;
}

Password* newPasswordObj_(char *plaintextPW, unsigned char numberBit,
        unsigned char uppercaseBit, unsigned char spaceBit, 
        unsigned char specialBit) {
    Password passwordObj = newPasswordObj();

    //! Account for NULL checks
    setPlaintextPW(&passwordObj, plaintextPW);
    setPWLen(&passwordObj, strLen(plaintextPW));
    setNumberBit(&passwordObj, numberBit);
    setSpaceBit(&passwordObj, spaceBit);
    setSpecialBit(&passwordObj, specialBit);
    setUppercaseBit(&passwordObj, uppercaseBit);

    return &passwordObj;
}

/* MEMBER FUNCTIONS */
char* generatePW(Password *passwordObj, size_t newPwLen) {
    if (checkFuncParamPtr(passwordObj)) {
        ERROR("NULL pointers! -- generatePW\n");
        return NULL;
    }

    char *newPW = (char*)calloc(newPwLen + 1, sizeof(char));

    int idx = 0;
    srand(time(NULL)); // this is not very secure
    while (idx < newPwLen) {
        unsigned char flag = 0;

        int randNum = rand() % (128 + 1); // 128 is the "normal" ascii range

        if (randNum == SPACE_ASCII) {
            if (getSpaceBit(passwordObj) == 1) { flag = 1; } 
        } else if (randNum >= SPECIALRANGE1_ASCII_BEGIN && randNum <= SPECIALRANGE1_ASCII_END
            || (randNum >= SPECIALRANGE2_ASCII_BEGIN && randNum <= SPECIALRANGE2_ASCII_END)
            || (randNum >= SPECIALRANGE3_ASCII_BEGIN && randNum <= SPECIALRANGE3_ASCII_END)
            || (randNum >= SPECIALRANGE4_ASCII_BEGIN && randNum <= SPECIALRANGE4_ASCII_END)
            ) {
            if (getSpecialBit(passwordObj) == 1) { flag = 1; } 
        } else if (randNum >= NUMBER_ASCII_BEGIN && randNum <= NUMBER_ASCII_END) { 
            if (getNumberBit(passwordObj) == 1) { flag = 1; } 
        } else if (randNum >= UPPERCASE_ASCII_BEGIN && randNum <= UPPERCASE_ASCII_END) { 
            if (getUppercaseBit(passwordObj) == 1) { flag = 1; } 
        } else if (randNum >= LOWERCASE_ASCII_BEGIN && randNum <= LOWERCASE_ASCII_END) { 
            flag = 1; // no need to check for "lowercaseBit"
        }

        if (flag == 1) { 
            newPW[idx] = randNum;
            idx++; 
        }
    }

    newPW[newPwLen] = '\0';

    return newPW;
}

/* GETTERS */
char* getPlaintextPW(Password *passwordObj) {
    char *retBuf = writeBufContents((*passwordObj).plaintextPW);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getPlaintextPW\n");
        return NULL;
    }

    return retBuf;
}

size_t getPWLen(Password *passwordObj) {
    size_t retVal = (*passwordObj).pwLen;

    return retVal;
}

unsigned char getNumberBit(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).numberBit;

    return retVal;
}

unsigned char getSpaceBit(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).spaceBit;

    return retVal;
}

unsigned char getSpecialBit(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).specialBit;

    return retVal;
}

unsigned char getUppercaseBit(Password *passwordObj) {
    unsigned int retVal = (*passwordObj).uppercaseBit;

    return retVal;
}

/* SETTERS */
int setPlaintextPW(Password *passwordObj, char *plaintextPW) {
    //* copyBufContents call
    if (copyBufContents((*passwordObj).plaintextPW, plaintextPW)) {
        ERROR("copyBufContents failed! -- setPlaintextPW\n");
        return 1;
    }

    return 0;
}

int setPWLen(Password *passwordObj, size_t pwLen) {
    //* NULL check
    if (checkFuncParamsInt(passwordObj, pwLen)) {
        ERROR("NULL pointers! -- setPWLen\n");
        return 1; 
    }

    (*passwordObj).pwLen = pwLen;

    return 0;
}

int setNumberBit(Password *passwordObj, unsigned char numberBit) {
    //* NULL check
    if (checkFuncParamPtr(passwordObj)) {
        ERROR("NULL pointers! -- setNumberBit\n");
        return 1; 
    }

    (*passwordObj).numberBit = numberBit;

    return 0;
}

int setUppercaseBit(Password *passwordObj, unsigned char uppercaseBit) {
    //* NULL check
    if (checkFuncParamPtr(passwordObj)) {
        ERROR("NULL pointers! -- setUppercaseBit\n");
        return 1; 
    }

    (*passwordObj).uppercaseBit = uppercaseBit;

    return 0;
}

int setSpaceBit(Password *passwordObj, unsigned char spaceBit) {
    //* NULL check
    if (checkFuncParamPtr(passwordObj)) {
        ERROR("NULL pointers! -- setSpaceBit\n");
        return 1; 
    }

    (*passwordObj).spaceBit = spaceBit;

    return 0;
}

int setSpecialBit(Password *passwordObj, unsigned char specialBit) {
    //* NULL check
    if (checkFuncParamPtr(passwordObj)) {
        ERROR("NULL pointers! -- setSpecialBit\n");
        return 1; 
    }

    (*passwordObj).specialBit = specialBit;

    return 0;
}

/* END OF PASSWORD CLASS IMPLEMENTATION */