#include <criterion/criterion.h>

#include "unit/commonUnittests.c"
#include "unit/fileUnittests.c"

Test(misc, passing) {
    cr_assert(1);
}

TestSuite(Common, .disabled=false);
TestSuite(File, .disabled=false);