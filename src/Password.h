/**
 * 
*/

/* LIBRARIES */
#include <stdio.h>

#define SPACE_ASCII 32
#define SPECIALRANGE1_ASCII_BEGIN 33
#define SPECIALRANGE1_ASCII_END 47
#define SPECIALRANGE2_ASCII_BEGIN 58
#define SPECIALRANGE2_ASCII_END 64
#define SPECIALRANGE3_ASCII_BEGIN 91
#define SPECIALRANGE3_ASCII_END 96
#define SPECIALRANGE4_ASCII_BEGIN 123
#define SPECIALRANGE4_ASCII_END 126
#define NUMBER_ASCII_BEGIN 48
#define NUMBER_ASCII_END 57
#define UPPERCASE_ASCII_BEGIN 65
#define UPPERCASE_ASCII_END 90
#define LOWERCASE_ASCII_BEGIN 97
#define LOWERCASE_ASCII_END 122
// Quick reference: www.asciitable.com

/* START OF PASSWORD CLASS */
#ifndef PASSWORD_H
#define PASSWORD_H

typedef struct Password {
    char *plaintextPW;
    size_t pwLen;
    unsigned int numberBit, spaceBit, specialBit, uppercaseBit;
} Password;

/* CONSTRUCTORS */
Password newPasswordObj();
Password* newPasswordObj_(char*, unsigned char, unsigned char, unsigned char, unsigned char);

/* MEMBER FUNCTIONS */
char* generatePW(Password*, size_t);

/* GETTERS */
char* getPlaintextPW(Password*);
size_t getPWLength(Password*);
unsigned char getNumberBit(Password*);
unsigned char getSpaceBit(Password*);
unsigned char getSpecialBit(Password*);
unsigned char getUppercaseBit(Password*);

/* SETTERS */
int setPlaintextPW(Password*, char*);
int setPWLen(Password*, size_t);
int setNumberBit(Password*, unsigned char);
int setSpaceBit(Password*, unsigned char);
int setSpecialBit(Password*, unsigned char);
int setUppercaseBit(Password*, unsigned char);

#endif

/* END OF PASSWORD CLASS */