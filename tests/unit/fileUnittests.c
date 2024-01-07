#include <criterion/criterion.h>
#include <string.h>

#include "../../src/File.h"
#include "../../src/Log.h"

TestSuite(File, .disabled=false);

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

    int fd = creatFileLocation(fileLocation);
    cr_assert(fd == -1);
}

Test(File, creatFileLocation1) {
    char *fileLocation = "./output/creatFileLocation1";

    int fd = creatFileLocation(fileLocation);
    cr_assert(fd != -1);
    close(fd);
}

Test(File, creatFileLocation2) {
    char *fileLocation = "./output/creatFileLocation2";

    int fd = creatFileLocation(fileLocation);
    cr_assert(fd != -1);
    close(fd); // must close fd in order to unlink it

    int retVal = unlinkFileLocation(fileLocation);
    cr_assert(retVal == 0);
}

Test(File, openFileLocation0) {
    char *fileLocation = "./output/openFileLocation0";

    int fd = openFileLocation(fileLocation);
    cr_assert(fd == -1);
}

Test(File, openFileLocation1) {
    char *fileLocation = "./output/openFileLocation1";

    int creatFD = creatFileLocation(fileLocation);
    // close(creatFD);
    int openFD = openFileLocation(fileLocation);
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

    // intentionally not unlinking the file
}

Test(File, writeFileDescriptor2) {
    // append data to file created in last unit test

    char *fileLocation = "./output/writeFileDescriptor1";
    int creatFD = creatFileLocation(fileLocation);

    char *dataToWrite = "CSafe was written in C by C!";
    int writeVal = writeFileDescriptor(creatFD, dataToWrite);

    // intentionally not unlinking the file
}