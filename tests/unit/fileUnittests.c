#include <criterion/criterion.h>

#include "../../src/File.h"

TestSuite(File, .disabled=false);

Test(File, constructorFileObj0) {
    File fileObj = newFileObj();

    cr_assert_eq(fileObj.fileLocation, NULL);
    cr_assert_eq(fileObj.hashedMasterPW, NULL);
    cr_assert_eq(fileObj.fd, 0);
}
