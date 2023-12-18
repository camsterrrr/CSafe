/**
 * 
*/
/* LIBRARIES */
#include <fcntl.h>
#include <string.h>

#include "File.h"
#include "Log.h"

/* START OF FILE CLASS IMPLEMENTATION */

/* CONSTRUCTORS */
/**
 * This function serves as the default constructor of the File class.
*/
File newFileObj() {
    File fileObj = {
        .fileLocation = NULL, 
        .hashedMasterPW = NULL, 
        .fd = 0,
    };

    return fileObj;
}

File newFileObjParams(char *fileLocation, char *hashedMasterPW, int fd) {
    File fileObj = {
        .fileLocation = NULL, 
        .hashedMasterPW = NULL, 
        .fd = 0,
    };

    setFileLocation(&fileObj, fileLocation);
    setHashedMasterPW(&fileObj, hashedMasterPW);
    setFD(&fileObj, fd);

    return fileObj;
}

/* MEMBER FUNCTIONS */
int checkFuncParamsPtr(void *arbitraryPtr0, void *arbitraryPtr1) { 
    return ((arbitraryPtr0 == NULL) || (arbitraryPtr1 == NULL)) ? 1 : 0; 
}

int checkFuncParamsInt(void *arbitraryPtr0, int arbitraryInt) { 
    return ((arbitraryPtr0 == NULL) || (arbitraryInt == 0)) ? 1 : 0; 
}

int checkValidFileDescriptor(int fd) { return (fd > 0) ? 0 : 1; }

int closeFileDescriptor (int fd) { return close(fd); }

int creatFileAtLocation(char *fileLocation) {
    int fd = creat(fileLocation, O_RDWR);

    //* Error check
    if (checkValidFileDescriptor(fd)) {
        ERROR("Unable to open file descriptor! -- creatFileAtLocation\n");
        return -1;
    }

    return fd;
}

int openFileAtLocation(char *fileLocation) {
    int fd = open(fileLocation, O_RDONLY);

    //* Error check
    if (checkValidFileDescriptor(fd)) {
        ERROR("Unable to open file descriptor! -- openFileAtLocation\n");
        return -1;
    }

    return fd;
}

int readFromFileDescriptor(File *fileObj, int fd) {
    FILE *FILE = fdopen(fd, "r");

    //* NULL check
    if (FILE == NULL) {
        ERROR("Unable to open file descriptor!\n");
        return -1;
    }

    /* This will be annoying to write */
    //- scan ahead for special chars
    // char buffer[256];
    // std::string fileContents = "";
    // while (fgets(buffer, 1024, FILE) != NULL) {
    //     fileContents.append(buffer);
    //     PRINTSTR(buffer);
    // }

    fclose(FILE);
}

/* GETTERS */
char* getFileLocation(File *fileObj) {
    //* NULL check
    if (checkFuncParamsPtr(fileObj, (*fileObj).fileLocation)) {
        ERROR("NULL pointers! -- getFileLocation");
        return NULL;
    }

    int cStrSize = strlen((*fileObj).fileLocation);
    char *retBuf = calloc(cStrSize + 1, sizeof(char));
    
    //* NULL check
    if (retBuf == NULL) {
        ERROR("Error initializing buffer -- getFileLocation \n");
        return NULL;
    }

    memcpy(retBuf, (*fileObj).fileLocation, cStrSize);

    return retBuf;
}

char* getHashedMasterPW(File *fileObj) {
    //* NULL check
    if (checkFuncParamsPtr(fileObj, (*fileObj).hashedMasterPW)) {
        ERROR("NULL pointers! -- getHashedMasterPW");
        return NULL;
    }

    int cStrSize = strlen((*fileObj).hashedMasterPW);
    char *retBuf = calloc(cStrSize + 1, sizeof(char));
    
    //* NULL check
    if (retBuf == NULL) {
        ERROR("Error initializing buffer -- getHashedMasterPW \n");
        return NULL;
    }

    memcpy(retBuf, (*fileObj).hashedMasterPW, cStrSize);
    
    return retBuf;
}

int getFD(File *fileObj) {
    //* NULL check
    if (checkFuncParamsInt(fileObj, (*fileObj).fd)) {
        ERROR("NULL pointers! -- getFD");
        return -1;
    }

    int retVal = (*fileObj).fd;

    return retVal;
}

/* SETTERS */
int setFileLocation(File *fileObj, char *fileLocation) {
    //* NULL check
    if (checkFuncParamsPtr(fileObj, fileLocation)) {
        ERROR("NULL pointers! -- setFileLocation");
        return 1;
    }

    int cStrSize = 0; // helper var

    // wipe fileObj memory location
    if ((*fileObj).fileLocation != NULL) {
        cStrSize = strlen((*fileObj).fileLocation);
        memset((*fileObj).fileLocation, 0b00000000, cStrSize);
        free((*fileObj).fileLocation);
    }
    
    // assign fileObj new memory
    cStrSize = strlen(fileLocation);
    (*fileObj).fileLocation = calloc(cStrSize + 1, sizeof(char));

    //* NULL check
    if ((*fileObj).fileLocation == NULL) {
        ERROR("Memory allocation failed! -- setFileLocation");
        return 1;
    }

    // copy data
    memcpy((*fileObj).fileLocation, fileLocation, cStrSize);

    return 0;
}

int setHashedMasterPW(File *fileObj, char *hashedMasterPW) {
    //* NULL check
    if (checkFuncParamsPtr(fileObj, hashedMasterPW)) {
        ERROR("NULL pointers! -- setHashedMasterPW");
        return 1;
    }

    int cStrSize = 0; // helper var

    // wipe memory location
    if ((*fileObj).hashedMasterPW != NULL) {
        cStrSize = strlen((*fileObj).hashedMasterPW);
        memset((*fileObj).hashedMasterPW, 0b00000000, cStrSize);
        free((*fileObj).hashedMasterPW);
    }

    // assign new memory
    cStrSize = strlen(hashedMasterPW);
    (*fileObj).hashedMasterPW = calloc(cStrSize + 1, sizeof(char));

    //* NULL check
    if ((*fileObj).hashedMasterPW == NULL) {
        ERROR("Memory allocation failed! -- setHashedMasterPW");
        return 1;
    }

    // copy data
    memcpy((*fileObj).hashedMasterPW, hashedMasterPW, cStrSize);

    return 0;
}

int setFD(File *fileObj, int fd) {
    //* NULL check
    if (checkFuncParamsInt(fileObj, fd)) {
        ERROR("NULL pointers! -- setFD");
        return 1; 
    }

    (*fileObj).fd = fd;

    return 0;
}

/* END OF FILE CLASS IMPLEMENTATION */