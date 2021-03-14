#include "compl_num.h"
#include <stdlib.h>
void* sum_compl (void* c1,void* c2)
{
    struct compl cp1 = *(struct compl*) c1;
    struct compl cp2 = *(struct compl*) c2;

    struct compl * res = (struct compl*)calloc(1,sizeof(struct compl));
    res->x = cp1.x + cp2.x;
    res->y = cp1.y + cp2.y;
    return res;
}

void* mult_compl (void* c1,void* c2)
{
    struct compl cp1 = *(struct compl*) c1;
    struct compl cp2 = *(struct compl*) c2;

    struct compl * res = (struct compl*)calloc(1,sizeof(struct compl));
    res->x = cp1.x * cp2.x - cp1.y * cp2.y;
    res->y = cp1.y *cp1.x + cp2.y *cp2.x;
    return res;
}