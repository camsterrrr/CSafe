#include <criterion/criterion.h>
#include <string.h>

#include "../../src/Database.h"
#include "../../src/Log.h"

TestSuite(Database, .disabled=false);

// Test(File, constructorFileObj0) {
//     File fileObj = newFileObj();

//     cr_assert_eq(fileObj.fileLocation, NULL);
//     cr_assert_eq(fileObj.hashedMasterPW, NULL);
//     cr_assert_eq(fileObj.fd, 0);
// }

// Test(File, enterPlaintextMasterPW0) {
//     char *buf0 = "File location", *buf1 = "Hashed password";
//     int val0 = 1000;
//     File fileObj = newFileObjParams(buf0, buf1, val0);

//     cr_assert(strcmp(fileObj.fileLocation, buf0) == 0);
//     cr_assert(strcmp(fileObj.hashedMasterPW, buf1) == 0);
//     cr_assert(fileObj.fd == val0);
// }