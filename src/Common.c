/**
 * 
*/

/* PREPROCESSING STATEMENTS */
#include <stdlib.h>
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

int copyBufContents(char* dest, char* src) {
    //* NULL check
    if (checkFuncParamsPtrs(dest, src)) {
        ERROR("NULL pointers! -- copyBufContents");
        return 1;
    }

    int cStrSize = 0; // helper var

    // wipe memory location
    if (dest != NULL) {
        cStrSize = strlen(dest);
        memset(dest, 0, cStrSize);
        free(dest);
    }

    // assign new memory
    cStrSize = strlen(src);
    dest = calloc(cStrSize + 1, sizeof(char)); // + 1 for NULL terminator

    //* NULL check
    if (dest == NULL) {
        ERROR("Memory allocation failed! -- copyBufContents");
        return 1;
    }

    // copy data
    memcpy(dest, src, cStrSize);

    return 0;
}

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
    return (src == NULL) ? -1 : strlen(src);
}

/* END OF PASSWORD CLASS IMPLEMENTATION */