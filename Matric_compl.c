#include <stdlib.h>
#include <stdio.h>
#include "Matric_compl.h"
#include "Matric .h"
#include "compl_num.h"
#include <assert.h>
#include <string.h>

void print_el_compl_Matric(void* el)
{
    struct compl a = *(struct compl*) el;

    if (a.y>=0)
    {
        printf(" %d+%di |",a.x,a.y);
    }
    else
    {
        printf(" %d%di |",a.x,a.y);
    }
}

void ** zero_compl_Matric(int size)
{
    struct compl* a = (struct compl *) calloc(1, size * size * sizeof(struct compl));
    void** ar = (void **) calloc(1,size * size*sizeof(a));
    struct compl zero;
    zero.x = 0;
    zero.y = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            a[i*size+j] = zero;
            ar[i*size+j] = &a[i*size+j];

        }
    }
    return ar;
}

struct Matric init_compl_Matric(int element_size, int size,void** ar)
{
    assert(size > 0);

    struct Matric cont;

    cont.element_size = element_size;
    cont.size = size;

    cont.mas = ar;

    cont.print_el = print_el_compl_Matric;
    cont.sum_el = sum_compl;
    cont.mult_el = mult_compl;
    cont.zero_matric = zero_compl_Matric;
    return cont;
}

void ** vvod_compl_Matric(int size)
{
    struct compl c;
    struct compl *a = (struct compl*)calloc(1,size*size * sizeof(struct compl));
    void** ar = (void**)calloc(1,size*size * sizeof(a));

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            int x;
            int y;
            scanf("%d%d", &x, &y);
            c.x = x;
            c.y = y;
            memcpy(&a[i*size+j],&c,sizeof(struct compl));
            ar[i*size+j] = &a[i*size+j];
        }
    }
    return ar;
}
