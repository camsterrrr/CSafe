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
    char *fileLocation, *hashedMasterPW;
    int fd;
} File;

/* CONSTRUCTORS */
File newFileObj();
File newFileObjParams(char*, char*, int);

/* MEMBER FUNCTIONS */
char* enterFileLocation();
int checkValidFileDescriptor(int);
int creatFileAtLocation(char*);
int closeFileDescriptor (int);
int openFileAtLocation(char*);
int readFromFileDescriptor(File*, int);
int unlinkFromFileDescriptor(char*);

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