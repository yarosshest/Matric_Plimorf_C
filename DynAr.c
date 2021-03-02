#include "DynAr .h"
#include "DynAr_str.h"
struct DynAr init_DynAr(int element_size, void *arT)
{
    struct DynAr ar;
    ar.size = 0;
    ar.element_size = element_size;
    ar.arT = arT;
    return ar;
}

void def_DynAr(struct DynAr cont, void *ar)
{
    def_str_DynAr(cont.arT,ar);
    cont.def(cont.arT,ar);
}