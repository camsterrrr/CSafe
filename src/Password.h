/**
 * 
*/

/* LIBRARIES */
#include <stdio.h>

/* START OF PASSWORD CLASS */
#ifndef PASSWORD_H
#define PASSWORD_H

typedef struct Password {
    char *plaintextPW, *hashedPW;
    size_t pwLen;
    unsigned int capitalCharFlag, spaceCharFlag, specialCharFlag;
} Password;

/* CONSTRUCTORS */
Password newPasswordObj();
Password newPasswordObjParams(char*, char*, unsigned int, unsigned int, unsigned int);

/* MEMBER FUNCTIONS */

/* GETTERS */
char* getPlaintextPW(Password*);
char* getHashedPW(Password*);
size_t getPWLength(Password*);
unsigned int getCapitalCharFlag(Password*);
unsigned int getSpaceCharFlag(Password*);
unsigned int getSpecialCharFlag(Password*);

/* SETTERS */
int setPlaintextPW();
int setHashedPW();
int setPWLen();
int setCapitalCharFlag();
int setSpaceCharFlag();
int setSpecialCharFlag();

#endif

/* END OF PASSWORD CLASS */