#include "compl_num.h"
#include <stdlib.h>
struct compl sum_compl (struct compl c1,struct compl c2)
{
    struct compl * res = (struct compl*)calloc(1,sizeof(struct compl));
    res->x = c1.x + c2.x;
    res->y = c1.y + c2.y;
    return *res;
}

struct compl mult_compl (struct compl c1,struct compl c2)
{
    struct compl * res = (struct compl*)calloc(1,sizeof(struct compl));
    res->x = c1.x * c2.x - c1.y * c2.y;
    res->y = c1.y *c1.x + c2.y *c2.x;
    return *res;
}