#include <criterion/criterion.h>
#include <string.h>

#include "../../src/Common.h"
#include "../../src/Log.h"

TestSuite(Common, .disabled=false);

Test(Common, copyBufContents0) {
    char *src = "CSafe was written in C by C!";
    char *dest = NULL;

    cr_assert(dest == NULL);
    copyBufContents(&dest, &src); 
    cr_assert(strcmp(dest, src) == 0); 
}

Test(Common, copyBufContents1) {
    char *src = "CSafe was written in C by C!";
    char *dest = "!C yb C ni nettirw saw efaSC";

    cr_assert(dest != NULL);
    copyBufContents(&dest, &src); 
    cr_assert(strcmp(dest, src) == 0); 
}

Test(Common, writeBufContents0) {
    char *src = "CSafe was written in C by C!";
    char *retBuf = NULL;

    cr_assert(retBuf == NULL);
    retBuf = writeBufContents(src); 
    cr_assert(strcmp(retBuf, src) == 0); 
}

Test(Common, writeBufContents1) {
    char *src = "CSafe was written in C by C!";
    char *retBuf = "!C yb C ni nettirw saw efaSC";
    
    cr_assert(retBuf != NULL);
    retBuf = writeBufContents(src); 
    cr_assert(strcmp(retBuf, src) == 0);
}

Test(Common, checkFuncParamsPtrs0) {
    char *src = "CSafe was written in C by C!";
    char *retBuf = NULL;
    int retVal;

    cr_assert(retBuf == NULL);
    retVal = checkFuncParamsPtrs(retBuf, src);
    cr_assert(retVal == 1);

    retBuf = writeBufContents(src); 
    cr_assert(retBuf != NULL);
    retVal = checkFuncParamsPtrs(retBuf, src);
    cr_assert(retVal == 0);
}

Test(Common, strLen) {
    char *src = "CSafe was written in C by C!";
    char *dest = NULL;
    int len;

    cr_assert(dest == NULL);
    len = strLen(dest);
    cr_assert(len == -1);

    copyBufContents(&dest, &src); 
    cr_assert(strcmp(dest, src) == 0); 
    len = strLen(dest);
    cr_assert(len == strLen(src));
}

Test(Common, clearBuf) {
    char *buf0 = "CSafe was written in C by C!";
    int val0;

    cr_assert(buf0 != NULL);

    val0 = clearBuf(&buf0);

    cr_assert(buf0 == NULL);
    cr_assert(val0 == 0);
}