#include <stdio.h>
#include "Matric_int.h"
#include "Matric .h"
#include "stdlib.h"
#include <assert.h>
void** sum_el_int(void* el1, void* el2)
{
    int a1 = *(int*) el1;
    int a2 = *(int*) el2;
    int sum = a1 + a2;
    void* ret = &sum;
    return ret;
}

void print_el_int_Matric(void* el)
{
    int a = *(int*) el;
    printf(" %d |",a);
}

void ** zero_int_Matric(int size)
{
    int* a = (int *) calloc(1, size * size * sizeof(int));
    void** ar = (void **) calloc(1,size * size*sizeof(a));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            a[i*size+j] = 0;
            ar[i*size+j] = &a[i*size+j];

        }
    }
    return ar;
}

struct Matric init_int_Matric(int element_size, int size,void** ar)
{
    assert(size > 0);
    struct Matric cont;

    cont.element_size = element_size;
    cont.size = size;
    cont.zero_matric = zero_int_Matric;

    cont.print_el = print_el_int_Matric;
    cont.sum_el =  sum_el_int;

    cont.mas = ar;

    return cont;
}


void ** vvod_int_Matric(int size)
{
    int* a = (int *) calloc(1, size * size * sizeof(int));
    void** ar = (void **) calloc(1,size * size*sizeof(a));


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size;j++)
        {
            scanf("%d", &a[i*size+j]);
            ar[i*size+j] = &a[i*size+j];

        }
    }
    return ar;
}

