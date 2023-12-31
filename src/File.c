/**
 * 
*/

/* LIBRARIES */
#include <errno.h>
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
        .fd = 0,
    };

    return fileObj;
}

File* newFileObj_() {
    File fileObj = newFileObj();

    //* USER INPUT
    char *fileLocation = enterFileLocation();
    int fd = creatFileLocation(fileLocation);

    if (fd == -1) {
        ERROR("File creation failed! -- newFileObj_\n");
        return NULL;
    }

    setFileLocation(&fileObj, fileLocation);
    setFD(&fileObj, fd);

    return &fileObj;
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

int creatFileLocation(char *fileLocation) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- creatFileAtLocation\n");
        return -1;
    }

    mode_t mode = O_RDWR;

    // check if file already exists, otherwise it will rewrite it (lose all data)
    int openFD = openFileLocation(fileLocation, mode);
    if (openFD != -1) {
        INFO("File location already exists! -- creatFileLocation\n");
        return openFD;
    }

    mode = O_CREAT | O_RDWR;

    int creatFD = open(fileLocation, mode);

    //* Error check
    if (checkValidFileDescriptor(creatFD)) {
        ERROR("Unable to open file descriptor! -- creatFileLocation\n");
        return -1;
    }

    return creatFD;
}

int openFileLocation(char *fileLocation, mode_t openModeEnum) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- openFileLocation\n");
        return 1;
    }

    int openFD = open(fileLocation, openModeEnum);

    //* Error check
    if (checkValidFileDescriptor(openFD)) {
        ERROR("Unable to open file descriptor! -- openFileLocation\n");
        return -1;
    }

    return openFD;
}

char* readFileDescriptor(int fd) {
    char *readBuf = (char*)calloc(READ_BYTES, sizeof(char));
    size_t readVal = read(fd, readBuf, READ_BYTES);

    if (readVal == 0) {
        INFO("read system call reached the end of the file! -- readFileDescriptor\n");
    } else if (readVal == -1) {
        ERROR("read system call failed! -- readFileDescriptor\n");
        fprintf(stderr, "errno: %d\n", errno);
        return NULL;
    }

    return readBuf;
}

int unlinkFileLocation(char *fileLocation) {
    if (checkFuncParamPtr(fileLocation)) {
        ERROR("NULL pointer! -- unlinkFileLocation\n");
        return -1;
    }

    if (unlink(fileLocation) == -1) {
        ERROR("unlink failed! File was not deleted. -- unlinkFileLocation\n");
        return -1;
    }

    return 0;
}

/**
 * This function moves the offset of the file descriptor using the `seek` 
 *  system call.
 */
off_t seekFileDescriptor(int fd, int lseekEnum, off_t offset) {

    off_t seekVal = lseek(fd, offset, lseekEnum);

    if (seekVal == -1) {
        ERROR("lseek system call failed! -- seekFileDescriptor\n");
        return -1;
    }

    return seekVal;
}

size_t writeFileDescriptor(int fd, char *dataToWrite) {
    if (checkFuncParamPtr(dataToWrite)) {
        ERROR("NULL pointer! -- writeFileDescriptor\n");
        return -1;
    }

    size_t count = strLen(dataToWrite) + 1;
    size_t writeVal = write(fd, dataToWrite, count);

    if (writeVal == -1) {
        ERROR("write failed! No bytes were written. -- writeFileDescriptor\n");
    }

    return writeVal;
}

/* GETTERS */
char* getFileLocation(File *fileObj) {
    char *retBuf = writeBufContents((*fileObj).fileLocation);

    //* NULL check
    if (retBuf == NULL) {
        ERROR("writeBufContents failed! -- getFileLocation\n");
        return NULL;
    }

    return retBuf;
}

int getFD(File *fileObj) {
    //* NULL check
    if (checkFuncParamsInt(fileObj, (*fileObj).fd)) {
        ERROR("NULL pointers! -- getFD\n");
        return -1;
    }

    int retVal = (*fileObj).fd;

    return retVal;
}

/* SETTERS */
int setFileLocation(File *fileObj, char *fileLocation) {
    if (copyBufContents(&(*fileObj).fileLocation, &fileLocation)) {
        ERROR("copyBufContents failed! -- setFileLocation\n");
        return 1;
    }

    return 0;
}

int setFD(File *fileObj, int fd) {
    //* NULL check
    if (checkFuncParamsInt(fileObj, fd)) {
        ERROR("NULL pointers! -- setFD\n");
        return 1; 
    }

    (*fileObj).fd = fd;

    return 0;
}

/* END OF FILE CLASS IMPLEMENTATION */