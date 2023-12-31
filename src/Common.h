/**
 * 
*/

/* LIBRARIES */

#define SHA1_BYTES 20

/* START OF COMMON CLASS */

#ifndef COMMON_H
#define COMMON_H

/* MEMBER FUNCTIONS */
int checkFuncParamPtr(void*);
int checkFuncParamsPtrs(void*, void*);
int checkFuncParamsInt(void*, int);
int clearBuf(char**);
int copyBufContents(char**, char**);
char* writeBufContents(char*);
int strLen(char*);
void displayHashInHex(char*);

#endif

/* END OF COMMON CLASS IMPLEMENTATION */