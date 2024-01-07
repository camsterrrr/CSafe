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
    int fd;
} File;

/* CONSTRUCTORS */
File newFileObj();
File* newFileObj_();

/* MEMBER FUNCTIONS */
char* enterFileLocation();
int checkValidFileDescriptor(int);
int creatFileLocation(char*);
int closeFileDescriptor (int);
int openFileLocation(char*);
int readFileDescriptor(File*, int);
int unlinkFileLocation(char*);
size_t writeFileDescriptor(int, char*);

/* GETTERS */
char* getFileLocation(File*);
int getFD(File*);

/* SETTERS */
int setFileLocation(File*, char*);
int setFD(File*, int);

#endif 

/* END OF FILE CLASS */