#include <criterion/criterion.h>

#include "../../src/Common.h"
#include "../../src/Password.h"
#include "../../src/Log.h"

TestSuite(Password, .disabled=false);

Test(Password, passwordObj0) {
    Password passwordObj = newPasswordObj();

    cr_assert(getPlaintextPW(&passwordObj) == NULL);
}

Test(Password, generatePW0) {
    Password *passwordObj = NULL;
    size_t arbitraryVal = 1000;

    char retBuf = generatePW(passwordObj, arbitraryVal);

    cr_assert(retBuf == NULL);
}

Test(Password, generatePW1) {
    Password passwordObj = newPasswordObj();
    size_t newPwLen = 25;

    char *newPW = generatePW(&passwordObj, newPwLen);

    PRINTSTR(newPW);

    cr_assert(newPW != NULL);
    cr_assert(strLen(newPW) == newPwLen);
}

Test(Password, generatePW2) {
    Password passwordObj = newPasswordObj();
    setSpecialBit(&passwordObj, 1);
    size_t newPwLen = 25;

    char *newPW = generatePW(&passwordObj, newPwLen);

    PRINTSTR(newPW);

    cr_assert(newPW != NULL);
    cr_assert(strLen(newPW) == newPwLen);
}

Test(Password, generatePW6) {
    Password passwordObj = newPasswordObj();
    setNumberBit(&passwordObj, 1);
    setSpaceBit(&passwordObj, 1);
    setSpecialBit(&passwordObj, 1);
    setUppercaseBit(&passwordObj, 1);
    size_t newPwLen = 25;

    char *newPW = generatePW(&passwordObj, newPwLen);

    PRINTSTR(newPW);

    cr_assert(newPW != NULL);
    cr_assert(strLen(newPW) == newPwLen);
}

// Test(Password, hashPlaintextMasterPW1) {
//     char *plaintextBuf = "Hello, world!";

//     char *sha1Buf = (char*)calloc(20, sizeof(char));
//     SHA1((unsigned char*)plaintextBuf, strLen(plaintextBuf), (unsigned char*)sha1Buf);

//     char *retBuf = hashPlaintextPassword(plaintextBuf);

//     cr_assert(strcmp(retBuf, sha1Buf) == 0);
// }