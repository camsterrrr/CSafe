#include <criterion/criterion.h>
#include <openssl/sha.h>

#include "../../src/Common.h"
#include "../../src/Database.h"
#include "../../src/Log.h"

TestSuite(Database, .disabled=false);

// Test(File, constructorFileObj0) {
//     File fileObj = newFileObj();

//     cr_assert_eq(fileObj.fileLocation, NULL);
//     cr_assert_eq(fileObj.hashedMasterPW, NULL);
//     cr_assert_eq(fileObj.fd, 0);
// }


//! In order to make this test work, I need to compare the hex of retBuf against string of sha1Buf
// Test(Database, hashPlaintextMasterPW0) {
//     char *plaintextBuf = "Hello, world!";

//     char *sha1Buf = "943a702d06f34599aee1f8da8ef9f7296031d699";

//     char *retBuf = hashPlaintextPassword(plaintextBuf);

//     printf("%s\n", sha1Buf);
//     displayHashInHex(retBuf);

//     cr_assert(strcmp(retBuf, sha1Buf) == 0);
// }

Test(Database, hashPlaintextMasterPW1) {
    char *plaintextBuf = "Hello, world!";

    char *sha1Buf = (char*)calloc(20, sizeof(char));
    SHA1((unsigned char*)plaintextBuf, strLen(plaintextBuf), (unsigned char*)sha1Buf);

    char *retBuf = hashPlaintextPassword(plaintextBuf);

    cr_assert(strcmp(retBuf, sha1Buf) == 0);
}