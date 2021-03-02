#include <stdio.h>
#include "DynAr .h"
#include "DynAr_str.h"
#include "stdlib.h"
#include "string.h"
int main() {
    struct DynAr test = init_str_DynAr(sizeof ('test'));
//    char** st =(char)calloc(1,sizeof ('blah'));
    char a[2][14];
    char *st = NULL;
    def_DynAr(test,st);
    printf("Hello, World!\n");
    return 0;
}
