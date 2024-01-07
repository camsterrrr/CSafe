/**
 * 
*/

/* LIBRARIES */
#include <openssl/sha.h>
#include <stdlib.h>

#include "src/Common.h"
#include "src/Database.h"
#include "src/DatabaseEntry.h"
#include "src/Log.h"
#include "src/Password.h"

/* PREPROCESSING STATEMENTS */

/* FUNCTION DECLARATIONS */

/* START OF MAIN */
int main(void) {
    printf("Debug!\n");

    char *buf0 =  (char*)calloc(256, sizeof(char));
    char *buf1 = (char*)calloc(256, sizeof(char));
    
    strcpy(buf0, "Hello, world!");
    SHA1((unsigned char*)buf0, strLen(buf0), (unsigned char*)buf1);

    printf("%s\n", buf0);
    displayHashInHex(buf1);
}
/* END OF MAIN */

/* FUNCTION DEFINITIONS*/

/* END OF FILE */
