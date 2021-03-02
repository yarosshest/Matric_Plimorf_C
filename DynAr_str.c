#include "DynAr_str.h"
#include "DynAr .h"
#include "stdlib.h"

void def_str_DynAr(void *ar,void *def)
{
//    ar.mas = (char **)def;
}

struct DynAr init_str_DynAr(int element_size)
{
    struct DynAr cont;
    struct DynAr_str *arT = (struct DynAr_str* ) calloc(1,sizeof (struct DynAr_str));
    char** ar = NULL;
    arT->mas = ar;
    cont.def = (void *(*)(void *, void *)) def_str_DynAr;
    cont = init_DynAr(element_size, arT);
    return cont;
}
