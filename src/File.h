/**
 * 
*/

/* LIBRARIES */
#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>

/* START OF FILE CLASS */
#ifndef FILE_H
#define FILE_H

typedef struct File {
    char *fileLocation;
    char *hashedMasterPW;
    int fd;
} File;

/* CONSTRUCTORS */
File newFileObj();

/* MEMBER FUNCTIONS */
int checkFuncParams(void*, void*);
int checkFuncParams(void*, int);
int checkValidFileDescriptor(int);
int creatFileAtLocation(char*);
int closeFileDescriptor (int);
int openFileAtLocation(char*);
void readFromFileDescriptor(File*, int);

/* GETTERS */
char* getFileLocation(File*);
char* getHashedMasterPW(File*);
int getFD(File*);

/* SETTERS */
int setFileLocation(File*, char*);
int setHashedMasterPW(File*, char*);
int setFD(File*, int);

#endif 

/* END OF FILE CLASS */