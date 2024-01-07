/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Common.h"
#include "Log.h"

/* START OF PASSWORD CLASS IMPLEMENTATION */

/* MEMBER FUNCTIONS */
int checkFuncParamPtr(void *arbitraryPtr) {
    return arbitraryPtr == NULL ? 1 : 0;
}

int checkFuncParamsPtrs(void *arbitraryPtr0, void *arbitraryPtr1) { 
    return ((arbitraryPtr0 == NULL) || (arbitraryPtr1 == NULL)) ? 1 : 0; 
}

int checkFuncParamsInt(void *arbitraryPtr0, int arbitraryInt) { 
    return ((arbitraryPtr0 == NULL) || (arbitraryInt == 0)) ? 1 : 0; 
}

int clearBuf(char **arbitraryBuf) {
    if (checkFuncParamPtr((*arbitraryBuf))) {
        ERROR("NULL pointer! -- clearBuf");
        return 1;
    }

    int cStrSize = strLen((*arbitraryBuf));
    memset(&(*arbitraryBuf), 0, cStrSize);
    free((*arbitraryBuf));

    return 0;
}

int copyBufContents(char** dest, char **src) {
    //* NULL check
    if (checkFuncParamPtr((*src))) {
        ERROR("NULL pointer! -- copyBufContents");
        return 1;
    }

    int cStrSize = 0; // helper var

    // wipe memory location
    if ((*dest) != NULL) {
        clearBuf(dest);
        // cStrSize = strlen((*dest));
        // memset(&(*dest), 0, cStrSize);
        // free((*dest));
    }

    // assign new memory
    cStrSize = strlen((*src));
    (*dest) = calloc(cStrSize + 1, sizeof(char)); // + 1 for NULL terminator

    //* NULL check
    if ((*dest) == NULL) {
        ERROR("Memory allocation failed! -- copyBufContents");
        return 1;
    }

    // copy data
    memcpy((*dest), (*src), cStrSize);
    (*dest)[cStrSize] = '\0';
    
    return 0;
}
/**
 * Notes: 
 *  I needed to make the parameters char** for two reasons:
 *      1. Since we want to modify the original location of dest, we need to pass a pointer
 *          to the pointer. A little bit weird, but I can see the use case.
 *      2. I'm not sure why I needed to make src a char** type. When I didn't have that, 
 *          the original source value would be nulled out, and I'm not entirely sure why...
*/

char* writeBufContents(char* src) {
    //* NULL check
    if (src == NULL) {
        ERROR("NULL pointer! -- writeBufContents");
        return NULL;
    }

    int cStrSize = strlen(src);
    char *dest = calloc(cStrSize + 1, sizeof(char)); // + 1 for NULL terminator
    
    //* NULL check
    if (dest == NULL) {
        ERROR("Error initializing buffer -- writeBufContents \n");
        return NULL;
    }

    memcpy(dest, src, cStrSize);

    return dest;
}

int strLen(char *src) {
    return src == NULL ? -1 : strlen(src);
}

void displayHashInHex(char *arbitraryHash) {
    if (checkFuncParamPtr(arbitraryHash) == 0) {
        for (int i = 0; i < SHA1_BYTES; i++) {
            printf("%x", (unsigned char)arbitraryHash[i]);
        }
        printf("\n");
    }
}

/* END OF PASSWORD CLASS IMPLEMENTATION */