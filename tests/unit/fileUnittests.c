#include <criterion/criterion.h>
#include <string.h>

#include "../../src/File.h"
#include "../../src/Log.h"

TestSuite(File, .disabled=false);

Test(File, constructorFileObj0) {
    File fileObj = newFileObj();

    cr_assert_eq(fileObj.fileLocation, NULL);
    cr_assert_eq(fileObj.hashedMasterPW, NULL);
    cr_assert_eq(fileObj.fd, 0);
}

Test(File, constructorFileObj1) {
    char *buf0 = "File location", *buf1 = "Hashed password";
    int val0 = 1000;
    File fileObj = newFileObjParams(buf0, buf1, val0);

    cr_assert(strcmp(fileObj.fileLocation, buf0) == 0);
    cr_assert(strcmp(fileObj.hashedMasterPW, buf1) == 0);
    cr_assert(fileObj.fd == val0);
}

Test(File, constructorFileObj2) {
    char *buf0 = "File location", *buf1 = "Hashed password";
    int val0 = 1000;
    File fileObj = newFileObjParams(buf0, buf1, val0);

    char *buf2, *buf3;
    int val1;

    buf2 = getFileLocation(&fileObj);
    buf3 = getHashedMasterPW(&fileObj);
    val1 = getFD(&fileObj);

    cr_assert(strcmp(buf2, buf0) == 0);
    cr_assert(strcmp(buf3, buf1) == 0);
    cr_assert(val1 == val0);

    /* Verify we are pointing to a new location */
    cr_assert(buf2 != buf0); // ptrs should NOT be the same address
    cr_assert(buf3 != buf1);
}

// Test(File, creatFileAtLocation1) {
//     char *buf0 = "./output/creatFileAtLocation";

//     int val0 = creatFileAtLocation(buf0);
//     cr_assert(val0 != -1);

//     int val1 = unlinkFromFileDescriptor(buf0);
//     cr_assert(val1 == 0);
// }