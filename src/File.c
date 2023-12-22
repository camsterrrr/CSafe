/**
 * 
*/
/* LIBRARIES */
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "Common.h"
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
char* enterFileLocation() {
    char *inputBuf = (char*)calloc(256, sizeof(char));

    printf("\tEnter file location:\n");
    printf("\t$ ");

    //* USER INPUT
    scanf("%s", inputBuf);

    return inputBuf;
}

int checkValidFileDescriptor(int fd) { return (fd > 0) ? 0 : 1; }

int closeFileDescriptor (int fd) { return close(fd); }

int creatFileAtLocation(char *fileLocation) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- creatFileAtLocation");
        return 1;
    }

    int fd = creat(fileLocation, O_RDWR);

    //* Error check
    if (checkValidFileDescriptor(fd)) {
        ERROR("Unable to open file descriptor! -- creatFileAtLocation\n");
        return -1;
    }

    return fd;
}

int openFileAtLocation(char *fileLocation) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- openFileAtLocation");
        return 1;
    }
    int fd = open(fileLocation, O_RDONLY);

    //* Error check
    if (checkValidFileDescriptor(fd)) {
        ERROR("Unable to open file descriptor! -- openFileAtLocation\n");
        return -1;
    }

    return fd;
}

int readFromFileDescriptor(File *fileObj, int fd) {
    if (checkFuncParamPtr(fileObj)) {
        ERROR("NULL pointer! -- readFromFileDescriptor");
        return 1;
    }

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

    return 0;
}

int unlinkFromFileDescriptor(char *fileLocation) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- unlinkFromFileDescriptor");
        return 1;
    }

    if (unlink(fileLocation) == -1) {
        ERROR("unlink failed! -- unlinkFromFileDescriptor");
        return 1;
    }

    return 0;
}

/* GETTERS */
char* getFileLocation(File *fileObj) {
    char *retBuf = writeBufContents((*fileObj).fileLocation);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getFileLocation");
        return NULL;
    }

    return retBuf;
}

char* getHashedMasterPW(File *fileObj) {
    char *retBuf = writeBufContents((*fileObj).hashedMasterPW);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getHashedMasterPW");
        return NULL;
    }

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
    if (copyBufContents(&(*fileObj).fileLocation, &fileLocation)) {
        ERROR("copyBufContents failed! -- setFileLocation");
        return 1;
    }

    return 0;
}

int setHashedMasterPW(File *fileObj, char *hashedMasterPW) {
    if (copyBufContents(&(*fileObj).hashedMasterPW, &hashedMasterPW)) {
        ERROR("copyBufContents failed! -- setHashedMasterPW");
        return 1;
    }

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