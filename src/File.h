/**
 * 
*/

/* LIBRARIES */
#include <fcntl.h>
#include "stdlib.h"
#include "stdio.h"
#include <unistd.h>

#define READ_BYTES 128

/* START OF FILE CLASS */
#ifndef FILE_H
#define FILE_H

typedef struct File {
    char *fileLocation;
    int fd;
} File;

// enum lseekEnum {
//     startOffset = SEEK_CUR, 
//     currPlusOffset = SEEK_SET,
//     endOffset = SEEK_END
// };

// enum openModeEnum {
//     read = O_RDONLY,
//     readWrite = O_RDWR
// };

/* CONSTRUCTORS */
File newFileObj();
File* newFileObj_();

/* MEMBER FUNCTIONS */
char* enterFileLocation();
int checkValidFileDescriptor(int);
int creatFileLocation(char*);
int closeFileDescriptor (int);
int openFileLocation(char*, mode_t);
char* readFileDescriptor(int);
int unlinkFileLocation(char*);
off_t seekFileDescriptor(int, int, off_t);
size_t writeFileDescriptor(int, char*);

/* GETTERS */
char* getFileLocation(File*);
int getFD(File*);

/* SETTERS */
int setFileLocation(File*, char*);
int setFD(File*, int);

#endif 

/* END OF FILE CLASS */