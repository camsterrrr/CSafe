#include <criterion/criterion.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#include "../../src/File.h"
#include "../../src/Log.h"

TestSuite(File, .disabled=false);

Test(File, infoMsg) {
    INFO("Now testing File methods, these should output warnings!\n");
}

Test(File, constructorFileObj0) {
    File fileObj = newFileObj();

    cr_assert_eq(fileObj.fileLocation, NULL);
    cr_assert_eq(fileObj.fd, 0);
}

Test(File, constructorFileObj1) {
    char *fileLocation = "File location";
    int fd = 1000;
    File fileObj = newFileObj();

    setFileLocation(&fileObj, fileLocation);
    setFD(&fileObj, fd);

    cr_assert(strcmp(fileObj.fileLocation, fileLocation) == 0);
    cr_assert(fileObj.fd == fd);
}

Test(File, constructorFileObj2) {
    char *fileLocation = "File location";
    int fd = 1000;
    File fileObj = newFileObj();

    setFileLocation(&fileObj, fileLocation);
    setFD(&fileObj, fd);

    char *retFileLocation = getFileLocation(&fileObj);
    int retFD = getFD(&fileObj);

    cr_assert(strcmp(retFileLocation, fileLocation) == 0);
    cr_assert(retFD == fd);

    /* Verify we are pointing to a new location */
    cr_assert(fileLocation != retFileLocation); // ptrs should NOT be the same address
}

Test(File, creatFileLocation0) {
    char *fileLocation = NULL;

    int creatFD = creatFileLocation(fileLocation);
    cr_assert(creatFD == -1);
}

Test(File, creatFileLocation1) {
    char *fileLocation = "./output/creatFileLocation1";

    int creatFD = creatFileLocation(fileLocation);
    cr_assert(creatFD != -1);

    close(creatFD);
}

Test(File, creatFileLocation2) {
    char *fileLocation = "./output/creatFileLocation2";

    int creatFD = creatFileLocation(fileLocation);
    cr_assert(creatFD != -1);

    close(creatFD); // must close fd in order to unlink it

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == 0);
}

Test(File, openFileLocation0) {
    char *fileLocation = "./output/openFileLocation0";

    int openFD = openFileLocation(fileLocation, O_RDWR);
    cr_assert(openFD == -1);
}

Test(File, openFileLocation1) {
    char *fileLocation = "./output/openFileLocation1";

    int creatFD = creatFileLocation(fileLocation);
    // close(creatFD);
    int openFD = openFileLocation(fileLocation, O_RDWR);
    cr_assert(openFD != creatFD); // close(creatFD) on line 83 changes the result

    close(creatFD);
    close(openFD);

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == 0);
}

Test(File, unlinkFileLocation0) {
    char *fileLocation = NULL; 

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == -1);
}

Test(File, unlinkFileLocation1) {
    char *fileLocation = "./output/creatFileLocation1"; // delete leftover file

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == 0);
}

Test(File, writeFileDescriptor0) {
    char *dataToWrite = NULL; 
    int arbitraryInt = 1;

    int writeVal = writeFileDescriptor(arbitraryInt, dataToWrite);
    cr_assert(writeVal == -1);
}

Test(File, writeFileDescriptor1) {
    char *fileLocation = "./output/writeFileDescriptor1";
    int creatFD = creatFileLocation(fileLocation);

    char *dataToWrite = "CSafe was written in C by C!";
    int writeVal = writeFileDescriptor(creatFD, dataToWrite);

    cr_assert(writeVal != -1);
    cr_assert(writeVal == (strLen(dataToWrite) + 1));

    close(creatFD);

    // intentionally not unlinking the file
}

Test(File, writeFileDescriptor2) {
    // append data to file created in last unit test

    char *fileLocation = "./output/writeFileDescriptor1";
    int openFD = openFileLocation(fileLocation, O_RDWR); 

    seekFileDescriptor(openFD, 0, SEEK_END);

    char *dataToWrite = "Adding more data!";
    int writeVal = writeFileDescriptor(openFD, dataToWrite);

    cr_assert(writeVal != -1);
    cr_assert(writeVal == (strLen(dataToWrite) + 1));

    close(openFD);

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == 0);
}

Test(File, readFileDescriptor1) {
    char *fileLocation = "./output/readFileDescriptor1";
    int creatFD = creatFileLocation(fileLocation);

    char *dataToWrite = "CSafe was written in C by C!";
    int writeVal = writeFileDescriptor(creatFD, dataToWrite);
    close(creatFD);

    int openFD = openFileLocation(fileLocation, O_RDONLY); 
    char *readBuf = readFileDescriptor(openFD);
    close(openFD);

    int unlinkVal = unlinkFileLocation(fileLocation);
    cr_assert(unlinkVal == 0);

    cr_assert(strcmp(readBuf, dataToWrite) == 0);
}